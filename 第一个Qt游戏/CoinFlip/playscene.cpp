#include "playscene.h"
#include <QDebug>
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QLabel>
#include "mycoin.h"
#include "dataconfig.h"
#include <QPropertyAnimation>
#include <QRect>
#include <QSound>

//PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
//{

//}


PlayScene::PlayScene(int levelNum)
{
    this->levelIndex = levelNum;
    QString str = QString("进入了第%1关").arg(levelNum);
    qDebug()<<str;

    //初始化游戏场景
    //设置固定大小
    this->setFixedSize(320,588);
    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle("翻金币场景");

    //创建菜单栏
    QMenuBar * bar = menuBar();
    setMenuBar(bar);
    //创建开始菜单
    QMenu * startMenu = bar->addMenu("开始");

    //创建退出菜单项
    QAction * quitAction = startMenu->addAction("退出");
    //点击退出实现退出游戏
    connect(quitAction, &QAction::triggered,[=](){
        this->close();

    });

    //音效资源
    QSound * backSound = new QSound(":/res/BackButtonSound.wav",this);
    QSound * flipSound = new QSound(":/res/ConFlipSound.wav",this);
    QSound * winSound = new QSound(":/res/LevelWinSound.wav",this);



    //返回按钮
    MyPushbutton * backBtn = new MyPushbutton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());



    //点击返回
    connect(backBtn, &MyPushbutton::clicked,[=](){
        //播放返回按钮的音效
        backSound->play();
        qDebug()<<"点击了返回按钮";
        //告诉选择场景 我返回了 选择场景监听playscene的返回按钮
        //延时返回
        QTimer::singleShot(400,this,[=](){

            emit this->palySceneBack();
        });
    });

    //显示当前关卡数
    QLabel * label= new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(16);
    QString strLevel = QString("level: %1").arg(this->levelIndex);
    label->setFont(font);
    label->setText(strLevel);
    label->setGeometry(20,this->height() - 50,140,50);

    dataConfig config;
    //初始化每个关卡的二维数组
    for(int i = 0; i<4;i++)
    {
        for(int j = 0; j<4; j++)
        {
            gameArray[i][j]=config.mData[levelIndex][i][j];
        }
    }

    //胜利图片的显示
    QLabel  * winLabel = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/res/LevelCompletedDialogBg.png");
    winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    winLabel->move((this->width() - tmpPix.width())*0.5, - tmpPix.height());

    //显示金币背景图案
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<4;j++)
        {
            //绘制背景图片
            QPixmap pix = QPixmap(":/res/BoardNode.png");
            QLabel * label =new QLabel;
            label->setGeometry(0,0,pix.width(),pix.height());
            label->setPixmap(pix);
            label->setParent(this);
            label->move(57 + i *50, 200+j*50);

            //创建金币
            QString str = QString(":/res/Coin0001.png");
            if(gameArray[i][j] != 1)
            {
                str = QString(":/res/Coin0008.png");
            }
            MyCoin * coin = new MyCoin(str);
            coin->setParent(this);
            coin->move(59 + i *50, 204+j*50);
            coin->posX = i;
            coin->posY = j;
            coin->flag = this->gameArray[i][j];//1正面 0反面

            //将金币放入到金币的二维数组里 以便后期维护
            coinBtn[i][j] = coin;

            //点击金币进行翻转
            connect(coin,&MyCoin::clicked,[=](){
                flipSound->play();
                for(int i = 0; i < 4; i++)
                {
                    for(int j = 0; j < 4; j++)
                    {
                        coinBtn[i][j]->isWin = true;
                    }

                }

                coin->changeFlag();
                this->gameArray[i][j] = this->gameArray[i][j] == 0 ? 1 : 0;

                //翻转周围硬币 延时翻转
                QTimer::singleShot(100,this,[=](){

                    if(coin->posX + 1 <= 3)//右侧金币翻转条件
                    {
                        coinBtn[coin->posX + 1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX + 1][coin->posY] = this->gameArray[coin->posX + 1][coin->posY] == 0 ? 1 : 0;
                    }
                    if(coin->posX - 1 >= 0)//左侧金币翻转条件
                    {
                        coinBtn[coin->posX - 1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX - 1][coin->posY] = this->gameArray[coin->posX - 1][coin->posY] == 0 ? 1 : 0;
                    }
                    if(coin->posY + 1 <= 3)//下侧金币翻转条件
                    {
                        coinBtn[coin->posX][coin->posY + 1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY + 1] = this->gameArray[coin->posX][coin->posY + 1] == 0 ? 1 : 0;
                    }
                    if(coin->posY - 1 >= 0)//上侧金币翻转条件
                    {
                        coinBtn[coin->posX][coin->posY - 1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY - 1] = this->gameArray[coin->posX][coin->posY - 1] == 0 ? 1 : 0;
                    }

                    for(int i = 0; i < 4; i++)
                    {
                        for(int j = 0; j < 4; j++)
                        {
                            coinBtn[i][j]->isWin = false;
                        }

                    }

                    this->isWin = true;
                    for(int i = 0; i < 4; i++)
                    {
                        for(int j = 0; j < 4; j++)
                        {
                            if(coinBtn[i][j]->flag == false)
                            {
                                this->isWin = false;
                                break;
                            }
                        }
                    }
                    if(this->isWin == true)
                    {
                        //胜利音效
                        winSound->play();
                        qDebug()<<"游戏胜利";
                        //将所有按钮的胜利标志改为true
                        for(int i = 0; i < 4; i++)
                        {
                            for(int j = 0; j < 4; j++)
                            {
                                coinBtn[i][j]->isWin = true;
                            }

                        }
                        //将胜利图片移下来
                        QPropertyAnimation * animation = new QPropertyAnimation(winLabel,"geometry");
                        //设置时间间隔
                        animation->setDuration(1000);
                        //设置开始位置
                        animation->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
                        //设置结束位置
                        animation->setEndValue(QRect(winLabel->x(),winLabel->y()+130,winLabel->width(),winLabel->height()));
                        //设置曲线
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        //执行动画
                        animation->start();

                    }

                });
                /* if(coin->posX + 1 <= 3)//右侧金币翻转条件
                {
                    coinBtn[coin->posX + 1][coin->posY]->changeFlag();
                    this->gameArray[coin->posX + 1][coin->posY] = this->gameArray[coin->posX + 1][coin->posY] == 0 ? 1 : 0;
                }
                if(coin->posX - 1 >= 0)//左侧金币翻转条件
                {
                    coinBtn[coin->posX - 1][coin->posY]->changeFlag();
                    this->gameArray[coin->posX - 1][coin->posY] = this->gameArray[coin->posX - 1][coin->posY] == 0 ? 1 : 0;
                }
                if(coin->posY + 1 <= 3)//下侧金币翻转条件
                {
                    coinBtn[coin->posX][coin->posY + 1]->changeFlag();
                    this->gameArray[coin->posX][coin->posY + 1] = this->gameArray[coin->posX][coin->posY + 1] == 0 ? 1 : 0;
                }
                if(coin->posY - 1 >= 0)//上侧金币翻转条件
                {
                    coinBtn[coin->posX][coin->posY - 1]->changeFlag();
                    this->gameArray[coin->posX][coin->posY - 1] = this->gameArray[coin->posX][coin->posY - 1] == 0 ? 1 : 0;
                } */
//                this->isWin = true;
//                for(int i = 0; i < 4; i++)
//                {
//                    for(int j = 0; j < 4; j++)
//                    {
//                        if(coinBtn[i][j]->flag == false)
//                        {
//                            this->isWin = false;
//                            break;
//                        }
//                    }
//                }
//                if(this->isWin == true)
//                {
//                    qDebug()<<"游戏胜利";
//                    //将所有按钮的标志改为true
//                }
            });

        }
    }


};
void PlayScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width()-pix.width())*0.5,30,pix.width(),pix.height(),pix);


}






























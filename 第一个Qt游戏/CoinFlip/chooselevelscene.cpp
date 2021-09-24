#include "chooselevelscene.h"
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <QTimer>
#include <QLabel>
#include <QSound>

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    //配置选择关卡场景
    this->setFixedSize(320,588);
    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));

    //设置标题
    this->setWindowTitle("选择关卡场景");

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

    //选择关卡音效
    QSound * chooseSound = new QSound(":/res/TapButtonSound.wav",this);
    //返回按钮音效
    QSound * backSound = new QSound(":/res/BackButtonSound.wav",this);

    //返回按钮
    MyPushbutton * backBtn = new MyPushbutton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());

    //点击返回
    connect(backBtn, &MyPushbutton::clicked,[=](){
        backSound->play();
        qDebug()<<"点击了返回按钮";
        //告诉主场景 我返回了 主场景监听chooselevelscene的返回按钮
        //延时返回
        QTimer::singleShot(400,this,[=](){
            emit this->chooseSceneBack();
        });

    });



    //创建选择关卡的按钮
    for(int i = 0; i < 20; i++)
    {
        MyPushbutton * menuBtn = new MyPushbutton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25 + i%4*70, 160 + i/4 * 70);

        //监听每个按钮的点击事件
        connect(menuBtn,&MyPushbutton::clicked,this,[=](){
            chooseSound->play();
            QString str = QString("选择的是第%1关").arg(i+1);
            qDebug()<<str;
            //进入到游戏场景
            this->hide(); //将选择场景隐藏
            play = new PlayScene(i + 1);//创建游戏的场景
            play->setGeometry(this->geometry());
            play->show();//显示游戏场景
            connect(play,&PlayScene::palySceneBack,this,[=](){
               //隐藏选择关卡场景
               play->hide();
               this->setGeometry(play->geometry());
               delete play;
               play = nullptr;
               //重新显示主场景

               this->show();
            });
        });


        QLabel * label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText(QString::number(i+1));
        label->move(25 + i%4*70, 160 + i/4 * 70);
        //设置对齐方式 水平居中和垂直居中
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //设置让鼠标进行穿透 51号属性
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }





}
void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    //加载背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width()-pix.width())*0.5,30,pix.width(),pix.height(),pix);

}














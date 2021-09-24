#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <QTimer>
#include <QSound> //多媒体模块下的音效头文件



MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //配置主场景

    //设置固定大小
    this->setFixedSize(320,588);
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    this->setWindowTitle("主场景");

    //退出按钮的实现
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });

    //退出按钮音效实现
    QSound * startSound = new QSound(":/res/TapButtonSound.wav",this);



    //开始按钮
    MyPushbutton * startBtn = new MyPushbutton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5 - startBtn->width()*0.5, this->height()*0.7);

    //实例化选择关卡的场景
    chooseScene = new ChooseLevelScene;

    connect(chooseScene,&ChooseLevelScene::chooseSceneBack,this,[=](){
       //隐藏选择关卡场景
       chooseScene->hide();
       //重新显示主场景
       //设置主场景的位置
       this->setGeometry(this->geometry());
       this->show();
    });

    connect(startBtn, &MyPushbutton::clicked, this, [=](){
        qDebug() << "点击了开始按钮";

        //播放开始音效资源
        startSound->play();

        //做弹起特效
        startBtn->zoom1();
        startBtn->zoom2();


        //延时进入到
        QTimer::singleShot(400,this,[=](){
            //进入到选择关卡场景中
            //自身隐藏
            this->hide();
            //显示选择关卡的场景
            //设置显示位置
            chooseScene->setGeometry(this->geometry());
            chooseScene->show();

            //监听选择关卡的返回按钮的信号


        });


    } );


}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //画背景上的图标
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.5, pix.height()*0.5);
    painter.drawPixmap(10,30,pix);
};











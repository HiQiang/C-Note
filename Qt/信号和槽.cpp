#include "mywidget.h"
#include <QPushButton>
#include "mypushbutton.h"
#include "QDebug"

/*
//命名规范
//类名 首字母大写，单词和单词之间首字母大写
//函数名 变量名称 首字母小写，单词和单词之间首字母大写

//快捷键
//注释 ctrl + /
//运行 ctrl + r
//编译 ctrl + b
//字体缩放 ctrl + 鼠标滚轮
//查找 ctrl + f
//整行移动 ctrl + shift + ↑ or ↓
//帮助文档 f1
//自动对齐 ctrl + i
//同名之间.h 和 .cpp切换 f4
//帮助文档 Qt assistant
*/
myWidget::myWidget(QWidget * parent)
    : QWidget(parent)
{
    //创建一个按钮

    QPushButton * btn = new QPushButton;

    //btn->show();//show 以顶层方式弹出窗口控件

    //让btn对象 依赖在mywidget窗口中
    btn->setParent(this);

    //显示文本
    btn->setText("myButton1");

    //按钮重新制定大小
    btn->resize(200,100);


    //创建第二个按钮,按照控件的大小创建窗口
    QPushButton * btn2 = new QPushButton("myButton2",this);

    //移动btn2按钮
    btn2->move(200,0);

    //重置窗口大小
    resize(600, 400);

    //设置固定窗口大小
    setFixedSize(600,400);

    //设置窗口标题
    setWindowTitle("设置窗口标题");

    //创建一个自己的按钮对象
    MyPushButton * myBtn = new MyPushButton;
    myBtn->setText("我自己的按钮");
    myBtn->move(200,200);
    myBtn->setParent(this);//设置到对象树中

    //需求   点击我的按钮 关闭窗口
    //connect(信号的发送者，发送的具体信号(函数地址)，信号的接收者，信号的处理(槽函数)(函数的地址))
    //信号槽的优点，松散耦合
    //信号发送端和接受端本身没有关联，通过connect连接 将两端耦合在一起

    //connect(myBtn, &MyPushButton::clicked,this,&myWidget::close);
    connect(myBtn, &QPushButton::clicked,this,&QWidget::close);

}

myWidget::~myWidget()
{
    qDebug()<<"myWidget的析构调用";
}




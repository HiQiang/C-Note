#include "widget.h"
#include "ui_widget.h"

//Teacher 类
//Student 类
//下课后，老师会触发一个信号，饿了，学生响应信号，请客吃饭


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建一个老师对象
    this->zt = new Teacher(this);
    //创建一个学生对象
    this->st = new Student(this);
    //老师饿了 学生请客的连接
    connect(zt, &Teacher::hungry, st, &Student::treat);
    //调用下课函数
    classIsOver();
}
void Widget::classIsOver(){
    //下课函数调用后，触发老师饿了的信号
    emit zt->hungry();
}
Widget::~Widget()
{
    delete ui;
}


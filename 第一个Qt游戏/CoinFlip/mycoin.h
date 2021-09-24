#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTimer>
class MyCoin : public QPushButton
{
    Q_OBJECT
public:
//    explicit MyCoin(QWidget *parent = nullptr);
    MyCoin(QString btnImg);//参数代表传入的是金币的路径还是银币路径

    //金币的属性
    int posX;
    int posY;
    bool flag;
    //改变标志的方法
    void changeFlag();
    QTimer * timer1;//正面翻反面定时器
    QTimer * timer2;//反面翻正面定时器

    int min = 1;
    int max = 8;

    //执行动画 标志
    bool isAnimation = false;

    //重写 按下
    void mousePressEvent(QMouseEvent *e);

    bool isWin = false;


signals:

public slots:

};

#endif // MYCOIN_H

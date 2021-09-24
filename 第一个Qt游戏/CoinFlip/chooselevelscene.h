#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include "playscene.h"

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);
    //重写绘图事件
    void paintEvent(QPaintEvent *);
    PlayScene * play = nullptr;

signals:

    //自定义信号 告诉主场景 点击了返回按钮
    void  chooseSceneBack();

public slots:
};

#endif // CHOOSELEVELSCENE_H

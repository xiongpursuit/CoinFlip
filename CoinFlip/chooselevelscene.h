#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include "playscene.h"

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);

signals:
    //写一个自定义信号，告诉主场景  点击了返回
        void chooseSceneBack();

public slots:

    void paintEvent(QPaintEvent *event);

private:
    PlayScene *pScene = NULL;
};

#endif // CHOOSELEVELSCENE_H

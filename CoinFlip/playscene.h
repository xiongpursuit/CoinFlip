#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "mycoin.h"
#include <QLabel>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int nPlayNo);


signals:
    void chooseSceneBack();

public slots:

protected:
    void paintEvent(QPaintEvent *event);

public:
    bool isWin = true; //是否胜利
private:
    void checkWin();
private:
    int m_nPlayNo;
    int gameArray[4][4]; //二维数组数据
    MyCoin * coinBtn[4][4]; //金币按钮数组;

    QLabel* winLabel = new QLabel;
};

#endif // PLAYSCENE_H

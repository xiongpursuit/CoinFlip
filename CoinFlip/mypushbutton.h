#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QString>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QPushButton *parent = nullptr);
    MyPushButton(QString normalImg, QString pressImg="");
    void zoom1();
    void zoom2();
signals:

public slots:
private:
    QString normalImgPath;
    QString pressImgPath;

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
};

#endif // MYPUSHBUTTON_H

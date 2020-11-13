#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QSound>

MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);
    //set fixed size
    this->setFixedSize(320, 588);
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    this->setWindowTitle("Coin Flip");
    //QSound* startSound = new QSound(":/res/TapButtonSound.wav",this);

    connect(ui->actionQuit, &QAction::triggered, [=](){this->close();});

    chooseScene=new ChooseLevelScene;
    //监听选择关卡的返回按钮的信号
    connect(chooseScene,&ChooseLevelScene::chooseSceneBack,this,[=]()
    {
        chooseScene->hide(); //将选择关卡场景 隐藏掉
        this->show(); //重新显示主场景
    });

    MyPushButton* startButton = new MyPushButton(":/res/MenuSceneStartButton.png");
    startButton->setParent(this);
    startButton->move(this->width()*0.5 - startButton->width()*0.5, this->height()*0.7);



    connect(startButton, &MyPushButton::clicked, [=]()
    {

       // startSound->play();
        startButton->zoom1();
        startButton->zoom2();
        QTimer::singleShot(500, [=]()
        {
            this->hide();
            chooseScene->show();
        });
    });
}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    pix.load(":/res/Title.png");
    pix.scaled(pix.width()*0.5, pix.height()*0.5);
    painter.drawPixmap(10, 30, pix.width()*0.5, pix.height()*0.5, pix);

//    MyPushButton* startButton = new MyPushButton(":/res/MenuSceneStartButton.png");
//    startButton->setParent(this);
//    startButton->move(this->width()*0.5 - startButton->width()*0.5, this->height()*0.7);

}

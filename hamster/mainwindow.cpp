#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "handler.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->sc=new myScene;
    ui->graphicsView->setScene(this->sc);
    connect(this->ui->pushButton_start,SIGNAL(clicked(bool)),this->sc,SLOT(startGame()));
    connect(this->ui->pushButton_pause,SIGNAL(clicked(bool)),this->sc,SLOT(pauseGame()));
    connect(this->ui->pushButton_stop,SIGNAL(clicked(bool)),this->sc,SLOT(stopGame()));

    this->score=0;
    handler *hand=handler::getInstance();
    connect(hand,SIGNAL(beatMouse()),this,SLOT(updateScore()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    int ret=QMessageBox::question(this,"确认信息","确定关闭窗口吗","是","否");
    if(ret==1)
    {
        event->ignore();    //如果选择第二个按钮，忽略此次关闭按钮点击事件
    }
}

void MainWindow::updateScore()
{
    this->score+=10;
    ui->lcdNumber->display(this->score);
}

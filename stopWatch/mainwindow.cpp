#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connect第一个参数只能接收指针，所以非指针对象ptimer只能传入地址
    connect(&ptimer,SIGNAL(timeout()),this,SLOT(updateAndDisplay()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateAndDisplay()
{
//    这个方法可能会随着计算机性能的变化而产生一定的误差
//    baseTime=baseTime.addMSecs(1);
//    QString showStr=baseTime.toString("hh:mm:ss:zzz");
//    ui->lcdNumber->display(showStr);
    QTime current=QTime::currentTime();
    int ms=baseTime.msecsTo(current);
    QTime showTime(0,0,0,0);
    showTime=showTime.addMSecs(ms);
    showStr=showTime.toString("hh:mm:ss:zzz");
    ui->lcdNumber->display(showStr);
}

void MainWindow::on_pushButton_start_clicked()
{
//    baseTime.setHMS(0,0,0,0);   //每次点击开始按钮都会重置时间
    baseTime=QTime::currentTime();
    ptimer.start(1);
    ui->pushButton_start->setEnabled(false);
}



void MainWindow::on_pushButton_stop_clicked()
{
    if(ui->pushButton_stop->text()=="停止")
    {
        ui->pushButton_stop->setText("清零");
        ptimer.stop();
        ui->pushButton_pause->setEnabled(false);
    }
    else
    {
        ui->pushButton_stop->setText("停止");
        ui->lcdNumber->display("00:00:00:000");
        ui->pushButton_start->setEnabled(true);
        ui->pushButton_pause->setEnabled(true);
        ui->textBrowser->clear();
    }

}

void MainWindow::on_pushButton_pause_clicked()
{
    static QTime pauseTime;
    if(ui->pushButton_pause->text()=="暂停")
    {
        pauseTime=QTime::currentTime();
        ptimer.stop();
        ui->pushButton_pause->setText("继续");
        ui->pushButton_start->setEnabled(false);
        ui->pushButton_stop->setEnabled(false);
    }
    else
    {
        QTime cur=QTime::currentTime();
        int t= pauseTime.msecsTo(cur);
        baseTime=baseTime.addMSecs(t);
        ptimer.start(1);
        ui->pushButton_pause->setText("暂停");
//        ui->pushButton_start->setEnabled(true);
        ui->pushButton_stop->setEnabled(true);
    }
}

void MainWindow::on_pushButton_log_clicked()
{
    ui->textBrowser->append(showStr);
}












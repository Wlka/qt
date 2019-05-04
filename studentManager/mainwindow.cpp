#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addstu.h"
#include "querystu.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_addStu_triggered()
{
    addStu a;
//    a.show();   //直接调用不可取，函数结束后，局部变量a被销毁，生成的窗口也会被跟着销毁,除非将a设为mainwindows的私有成员
    a.exec();

}

void MainWindow::on_action_queryStu_triggered()
{
    queryStu q;
    q.exec();
}

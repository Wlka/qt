#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myscene.h"
#include <QCloseEvent>  //准备重写QWidget的关闭事件

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void closeEvent(QCloseEvent *event);    //重写关闭事件

private slots:
    void updateScore();

private:
    Ui::MainWindow *ui;
    myScene *sc;
    int score;
};

#endif // MAINWINDOW_H

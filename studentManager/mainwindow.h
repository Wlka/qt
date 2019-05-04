#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addstu.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_addStu_triggered();

    void on_action_queryStu_triggered();

private:
    Ui::MainWindow *ui;
    addStu a;   //将addStu对象作为mainwindows的私有成员，这样就能使用show方法显示addStu的窗口了
};

#endif // MAINWINDOW_H

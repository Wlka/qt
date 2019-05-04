#ifndef QUERYSTU_H
#define QUERYSTU_H

#include <QDialog>
#include <QFile>
#include <QList>
#include <QString>
#include <QStandardItem>
#include <QStandardItemModel>

namespace Ui {
class queryStu;
}

class queryStu : public QDialog
{
    Q_OBJECT

public:
    explicit queryStu(QWidget *parent = nullptr);
    ~queryStu();
    int readFromFile();
    void setHeader();
    void doQuery(int sreachIndex,QString content);
    void disPlay(int row,QStringList line_list);

private slots:
    void on_pushButton_search_clicked();

private:
    Ui::queryStu *ui;
    QList<QString> stu_line;
    QStandardItemModel *model;
};

#endif // QUERYSTU_H

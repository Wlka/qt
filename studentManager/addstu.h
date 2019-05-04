#ifndef ADDSTU_H
#define ADDSTU_H

#include <QDialog>

namespace Ui {
class addStu;
}

class addStu : public QDialog
{
    Q_OBJECT

public:
    explicit addStu(QWidget *parent = nullptr);
    ~addStu();
    void clearUserInterface();
    void writeToFile(QString msg);

private slots:
    void on_pushButton_Ok_clicked();
private:
    Ui::addStu *ui;
};

#endif // ADDSTU_H

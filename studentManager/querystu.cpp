#include "querystu.h"
#include "ui_querystu.h"
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <QStringList>

queryStu::queryStu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::queryStu)
{
    ui->setupUi(this);
    if(readFromFile()==-1)
    {
        QMessageBox::critical(this,"Error","学生信息文件未能打开，已为您关闭窗口","确定");
        this->close();
    }
    model=new QStandardItemModel;
    setHeader();
}

queryStu::~queryStu()
{
    delete ui;
}

void queryStu::setHeader()
{
    //设置表头
    model->setHorizontalHeaderItem(0,new QStandardItem("姓名"));
    model->setHorizontalHeaderItem(1,new QStandardItem("学号"));
    model->setHorizontalHeaderItem(2,new QStandardItem("性别"));
    model->setHorizontalHeaderItem(3,new QStandardItem("年龄"));
    model->setHorizontalHeaderItem(4,new QStandardItem("院系"));
    model->setHorizontalHeaderItem(5,new QStandardItem("兴趣"));

    //将view和model进行绑定
    ui->tableView->setModel(model);

    //设置单元格宽度
    ui->tableView->setColumnWidth(0,100);
    ui->tableView->setColumnWidth(1,150);
    ui->tableView->setColumnWidth(2,50);
    ui->tableView->setColumnWidth(3,50);
    ui->tableView->setColumnWidth(4,100);
    ui->tableView->setColumnWidth(5,150);
}

int queryStu::readFromFile()
{
    QFile file("stu.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        return -1;
    }

    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line=in.readLine();
        stu_line.append(line);
    }

    file.close();

    return 0;
}

void queryStu::on_pushButton_search_clicked()
{
    model->clear(); //每次查询都清空原有的item
    setHeader();
    int sreachIndex=ui->comboBox_method->currentIndex();
    QString content=ui->lineEdit_content->text();
    doQuery(sreachIndex,content);
}

void queryStu::doQuery(int sreachIndex,QString content)
{
    if(sreachIndex==0)
    {
        QMessageBox::critical(this,"Error","未选择搜索方式","确定");
        return;
    }
    int row=0;
    for(int i=0;i<stu_line.length();++i)
    {
        QString line=stu_line.at(i);
        QStringList line_list=line.split(" ");
        if(line_list[sreachIndex-1]==content)
        {
            disPlay(row++,line_list);
        }
    }
}

void queryStu::disPlay(int row,QStringList line_list)
{
    for(int i=0;i<line_list.length();++i)
    {
        model->setItem(row,i,new QStandardItem(line_list.at(i)));
    }
}










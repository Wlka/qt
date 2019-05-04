#include "addstu.h"
#include "ui_addstu.h"
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>
#include <QList>
#include <QAbstractButton>
#include <QCheckBox>
#include <QFile>
#include <QTextStream>
#include <QIODevice>

addStu::addStu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addStu)
{
    ui->setupUi(this);
    connect(ui->pushButton_Cancel,SIGNAL(clicked(bool)),this,SLOT(close()));
}

addStu::~addStu()
{
    delete ui;
}

void addStu::on_pushButton_Ok_clicked()
{
    QString name=ui->lineEdit_Name->text();

    QString id=ui->lineEdit_ID->text();

    QString sex=ui->buttonGroup_sex->checkedButton()->text();

    QString age=ui->comboBox_age->currentText();

    QString college=ui->comboBox_college->currentText();

    QList<QAbstractButton*> interest_list=ui->buttonGroup_interest->buttons();
    QString interest;
    for(int i=0;i<interest_list.length();++i)
    {
        QAbstractButton* che=interest_list.at(i);
        if(che->isChecked())
        {
            interest+=che->text()+",";
        }
    }
//    interest=interest.left(interest.length()-1);    //删除最后一位
    interest.chop(1);   //删除最后一位


    QString content=name+"\n"+id+"\n"+sex+"\n"+age+"\n"+college+"\n"+interest;

    if(name.length()==0||id.length()==0 || id.length()>10 || interest.length()<1)
    {
        QMessageBox::critical(this,"警告","请填写正确姓名和学号",QMessageBox::Ok);
    }
    else
    {
        int ret=QMessageBox::information(this,"确认信息",content,"确认","取消");
        switch(ret)
        {
        case 0:
            clearUserInterface();
            writeToFile(content);
            break;
        case 1:
            break;
        }
    }

//    QMessageBox msgBox;
//    msgBox.setText("确认信息");
//    msgBox.setInformativeText(name+"\n"+id);
//    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);   //这里设置标准按钮
//    msgBox.setDefaultButton(QMessageBox::Ok);   //这里设置默认选择按钮
//    QPushButton *Ok_btn=msgBox.addButton("确定",QMessageBox::AcceptRole); //自定义按钮
//    msgBox.addButton("取消",QMessageBox::RejectRole);
//    msgBox.setDefaultButton(Ok_btn);    //设置自定义按钮的默认选择
//    int ret=msgBox.exec();

//    QMessageBox::aboutQt(this,"鸣谢");
//    QMessageBox::information(this,"确认信息",name+"\n"+id,QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
}


void addStu::clearUserInterface()
{
    ui->lineEdit_Name->clear();
    ui->lineEdit_ID->clear();
    ui->radioButton_male->setChecked(true);
    ui->comboBox_age->setCurrentIndex(0);
    ui->comboBox_college->setCurrentIndex(0);
    QList<QAbstractButton*>interest_List=ui->buttonGroup_interest->buttons();
    for(int i=0;i<interest_List.length();++i)
    {
        interest_List.at(i)->setChecked(false);
    }
    ui->lineEdit_Name->setFocus();
}

void addStu::writeToFile(QString msg)
{
    msg.replace("\n"," ");
    QFile file("stu.txt");
    if(!file.open(QIODevice::Append|QIODevice::Text))
    {
        QMessageBox::critical(this,"Error","Fail to open file,information wrote failed!");
        return;
    }
    QTextStream out(&file);
    out<<msg<<endl;
    file.close();
}












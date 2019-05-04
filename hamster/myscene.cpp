#include "myscene.h"
#include <QDebug>
#include <stdlib.h>

myScene::myScene(QObject *parent) : QGraphicsScene(parent)
{
    //通过一次循环new出所有图元并计算图元的位置
    for(int i=0;i<16;++i)
    {
        this->item[i]=new myItem;
        item[i]->setPos(i/4*this->item[i]->boundingRect().width(),i%4*this->item[i]->boundingRect().height());
        this->addItem(this->item[i]);
    }

    this->ptimer=new QTimer;
    connect(this->ptimer,SIGNAL(timeout()),this,SLOT(showMouse()));
}

void myScene::showMouse()
{
    //每次显示前先重置图片
    for(int i=0;i<16;++i)
    {
        this->item[i]->setPic(":bg/src/image/background1.png");
        this->item[i]->setMouse(false);
    }

    //随机产生1-3个0-15的整数作为下标进行老鼠图片设置
    int cnt=rand()%3+1;
    for(int i=0;i<cnt;++i)
    {
        int index=rand()%16;
        this->item[index]->setPic(":bg/src/image/background2.png");
        this->item[index]->setMouse(true);
    }
}

void myScene::startGame()
{
    this->ptimer->start(1000);
    for(int i=0;i<16;++i)
    {
        this->item[i]->setStart(true);
    }
}

void myScene::pauseGame()
{
    this->ptimer->stop();
    for(int i=0;i<16;++i)
    {
        this->item[i]->setStart(false);
    }
}

void myScene::stopGame()
{
    this->ptimer->stop();
    for(int i=0;i<16;++i)
    {
        this->item[i]->setPic(":bg/src/image/background1.png");
        this->item[i]->setMouse(false);
        this->item[i]->setStart(false);
    }
}







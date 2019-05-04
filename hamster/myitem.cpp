#include "myitem.h"
#include <QPixmap>
#include <QDebug>
#include "handler.h"
#include <QCursor>

myItem::myItem():mouse(false),start(false)
{
    this->setPixmap(QPixmap(":bg/src/image/background1.png"));
    this->setCursor(QCursor(QPixmap(":/mouse/src/image/down.png")));
}

void myItem::setPic(const QString& path)
{
    this->setPixmap(QPixmap(path));
}

void myItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/mouse/src/image/down.png")));
    if(this->isStart())
    {
        handler *hand=handler::getInstance();
        if(this->isMouse())
        {
            hand->addScore();   //当点击到老鼠时发送addScore里的beatMouse信号
            this->setPixmap(QPixmap(":/mouse/src/image/beat.png"));
            this->mouse=false;  //打到老鼠后重复敲打该位置不能继续改变分数
        }
    }
}

void myItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/mouse/src/image/up.png")));
}

void myItem::setMouse(bool mouse)
{
    this->mouse=mouse;
}

bool myItem::isMouse()
{
    return this->mouse;
}

void myItem::setStart(bool start)
{
    this->start=start;
}

bool myItem::isStart()
{
    return this->start;
}

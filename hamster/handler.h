#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>

class handler : public QObject
{
    Q_OBJECT
public:
    static handler *getInstance();
    void addScore();

private:
    explicit handler(QObject *parent = nullptr);
    static handler *hand;

signals:
    void beatMouse();

public slots:
};

#endif // HANDLER_H

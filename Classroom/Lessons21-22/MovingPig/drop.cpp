#include "drop.h"
#include "mainwindow.h"
Drop::Drop(int x, MainWindow * parent) : Cloud(parent)
{

    setGeometry(x, 0, 50,50);
    this->setPixmap(QPixmap("c://Users//..path..//drop.jpg").scaled(this->width(),this->height(),Qt::KeepAspectRatioByExpanding));
}

void Drop::start()
{
    timer = new QTimer();
    timer->setInterval(50);

    speed = 10;
    connect(this->timer, SIGNAL(timeout()), this, SLOT(moveMeVertical()));
    timer->start();
}

void Drop::moveMeVertical()
{
    if (this->y()+this->height() <this->parentWindow->height())
    {
        setGeometry(this->x(), this->y()+speed, 50,50);
    }
    this->repaint();
}

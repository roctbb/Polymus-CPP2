#include "cloud.h"
#include "mainwindow.h"
void Cloud::start()
{

    timer->setInterval(50);
    speed = 10;
    connect(this->timer, SIGNAL(timeout()), this, SLOT(moveMe()));
    timer->start();
}

Cloud::Cloud(MainWindow *parent) : QLabel((QWidget*)parent)
{
    int mx = rand()%parent->width();
    this->setGeometry(mx, 0, 150,150);
    this->setPixmap(QPixmap("/Users/roctbb/Downloads/face.png"));
    parentWindow = parent;
    timer = new QTimer();
}

void Cloud::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
}

void Cloud::moveMe()
{
    if (this->x()+this->width() >this->parentWindow->width()|| this->x()<0)
    {
        speed *= -1;
    }
    setGeometry(this->x()+speed, 0, 150,150);
    this->parentWindow->addDrop(this->x());
    this->repaint();
}

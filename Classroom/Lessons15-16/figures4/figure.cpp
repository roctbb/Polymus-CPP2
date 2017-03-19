#include "figure.hpp"

#include <QPainter>

Figure::Figure(QWidget * parent) : QWidget(parent)
{

    x = 200;
    y = 200;
    setMaximumHeight(500);
    setMaximumWidth(400);
    setMinimumHeight(500);
    setMinimumWidth(400);
}

void Figure::paintEvent(QPaintEvent *)
{

    QPainter p(this);
    p.setPen(QPen(Qt::red,1,Qt::SolidLine));
    p.drawLine(QPoint(x-20,y-20), QPoint(x+20,y+20));
    p.drawLine(QPoint(x+20,y-20), QPoint(x-20,y+20));
}

void Figure::moveFigure()
{
    update();

    if (x>=0)
    {
        x--;
    }
    else
    {
        x+=399;
    }

}

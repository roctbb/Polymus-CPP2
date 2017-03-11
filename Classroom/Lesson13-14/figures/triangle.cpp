#include "triangle.hpp"
#include "QPainter"


Triangle::Triangle(QWidget *parent):Figure(parent)
{
    rad = qrand()%20+30;

}

void Triangle::paintEvent(QPaintEvent *)
{
    QPainter p(this);



    p.setPen( QPen(Qt::red,1,Qt::SolidLine) );

    p.drawEllipse( QPoint(x,y),rad, rad);


}

void Triangle::moveFigure()
{
    update();

    if (y >= 0)
    {
        y--;
    }
    else
    {
        y+=399;
    }



}

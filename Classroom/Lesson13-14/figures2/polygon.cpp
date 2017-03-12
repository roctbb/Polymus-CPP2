#include "polygon.hpp"
#include "figure.hpp"
#include "QPainter"

Polygon::Polygon(QWidget *parent): Figure(parent)
{

}

void Polygon::paintEvent(QPaintEvent *)
{
    QPixmap pix;
    pix = QPixmap("C:\\figures\\2.png");

    QPainter p(this);
    p.setPen(QPen(Qt::blue,1,Qt::SolidLine));
    p.drawLine(QPoint(x-20,y-20), QPoint(x+20,y-20));
    p.drawLine(QPoint(x+20,y-20), QPoint(x+20,y+20));
    p.drawLine(QPoint(x+20,y+20), QPoint(x-20,y+20));
    p.drawLine(QPoint(x-20,y+20), QPoint(x-20,y-20));
    p.drawPixmap(x,y,x,y,pix);



}

void Polygon::moveFigure()
{
    update();

    if (x<=400)
    {
        x++;
    }
    else
    {
        x-=399;
    }
}

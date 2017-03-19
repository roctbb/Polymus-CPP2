#include "Ball.hpp"
#include "QPainter"
#include <ctime>


Ball::Ball(QWidget *parent):Figure(parent)
{


    rad = 10;
    x = 200 - 50 - qrand() % 100;
    y = 200 + qrand() % 100;
    color = qrand()%255;
    color2 = qrand()%255;
    color3 = qrand()%255;

}

void Ball::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    qsrand(time(NULL));


    p.setPen( QPen(QColor(color,color2,color3) ,1,Qt::SolidLine ) ) ;
    p.setBrush(QColor(color,color2,color3));
    p.drawEllipse( QPoint(x,y),rad, rad);


}

int Ball::getX()
{
    return x;
}

int Ball::getY()
{
    return y;
}

int Ball::getRad()
{
    return rad;
}

void Ball::setCoords()
{
    x = 0 - rad;
    y = qrand() % 400;
}



void Ball::moveFigure()
{
    update();
    if (x - rad >= 400){
        x = -rad;
        y = qrand() % 400;
    }
    else
        x += (1 + qrand() % 4);


}

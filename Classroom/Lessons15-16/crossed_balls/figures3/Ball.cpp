#include "Ball.hpp"
#include "QPainter"
#include <ctime>


Ball::Ball(QWidget *parent):Figure(parent)
{


    rad = qrand()%20+30;
    x = 200;
    y = 200;
    color = qrand()%255;
    color2 = qrand()%255;
    color3 = qrand()%255;
    direction = true;
}

void Ball::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    qsrand(time(NULL));


    p.setPen( QPen(QColor(color,color2,color3) ,1,Qt::SolidLine ) ) ;
    p.setBrush(QColor(color,color2,color3));
    p.drawEllipse( QPoint(x,y),rad, rad);


}

void Ball::moveFigure()
{
    update();
    if (y + rad == 400)
        direction = true;
    if (y - rad == 0)
        direction = false;
    if (direction){
        y--;
    }
    else{
        y++;
    }

}

void Ball::moveFigureX()
{
    update();
    if (x + rad == 400)
        direction2 = true;
    if (x - rad == 0)
        direction2 = false;
    if (direction2){
        x--;
    }
    else{
        x++;
    }
}

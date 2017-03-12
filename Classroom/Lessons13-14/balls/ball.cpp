#include "ball.h"

Ball::Ball(int width, int height, QObject *parent) :
    QObject(parent), color(rand()%255,rand()%255,rand()%255)
{
    x = rand()%width;
    y = rand()%height;

    vx = 5+rand()%10;
    vy = 5+rand()%10;
    r = 5 + rand()%20;
    if (rand()%2==0) vx*=-1;
    if (rand()%2==0) vy*=-1;
}
int Ball::GetX()
{
    return x;
}
int Ball::GetY()
{
    return y;
}
void Ball::ReverseX()
{
    vx *= -1;
}
void Ball::ReverseY()
{
    vy *= -1;
}
void Ball::Move()
{
    x = x + vx;
    y = y + vy;
}
void Ball::Draw(QPainter &painter){
    painter.setBrush(color);
    painter.setPen(color);
    painter.drawEllipse(x-r,y-r,2*r,2*r);
}


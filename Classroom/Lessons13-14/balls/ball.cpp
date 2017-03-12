#include "ball.h"

Ball::Ball(int width, int height, QObject *parent) :
    QObject(parent), color(rand()%255,rand()%255,rand()%255)
{
    x = rand()%width;
    y = rand()%height;

    vx = rand()%10;
    vy = rand()%10;
    r = 5 + rand()%10;
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
    x *= -1;
}
void Ball::ReverseY()
{
    y *= -1;
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


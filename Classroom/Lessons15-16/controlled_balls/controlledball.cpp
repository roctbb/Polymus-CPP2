#include "controlledball.h"
#include <QtGui>
ControlledBall::ControlledBall(int width, int height):
    Ball(width,height)
{
    life = 10;
    points = 0;
}

void ControlledBall::moveDown() {
    y += 10;
}

void ControlledBall::moveUp() {
    y -= 10;
}

void ControlledBall::moveRight() {
    x += 10;
}
void ControlledBall::moveLeft() {
    x -= 10;
}

void ControlledBall::Hit()
{
    life--;
}
void ControlledBall::AddPoint()
{
    points++;
}

int ControlledBall::getHealth()
{
    return life;
}
int ControlledBall::getPoints()
{
    return points;
}

void ControlledBall::Draw(QPainter& painter) {
    painter.setBrush(color);
    painter.setPen(color);
    painter.drawRect(x-r,y-r,2*r,2*r);
    painter.drawEllipse(x-r,y-r,2*r,2*r);
}

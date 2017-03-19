#ifndef CONTROLLEDBALL_H
#define CONTROLLEDBALL_H
#include <QtGui>
#include "ball.h"

class ControlledBall : public Ball
{
    int life;
    int points;

public:
    ControlledBall(int width, int height);
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    void Hit();
    void AddPoint();

    int getHealth();
    int getPoints();

    void Draw(QPainter& painter);

};

#endif // CONTROLLEDBALL_H

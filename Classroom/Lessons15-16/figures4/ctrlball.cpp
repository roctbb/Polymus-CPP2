#include "ctrlball.hpp"

CtrlBall::CtrlBall(QWidget *parent) : Ball(parent)
{

}


void CtrlBall::moveFigure(QKeyEvent *event)
{
   update();
   switch(event->key())
    {
    case Qt::Key_W:
        isWall(0, -10);
        break;
    case Qt::Key_S:
        isWall(0, 10);
        break;
//   case Qt::Key_A:
//       isWall(-10, 0);
//       break;
//   case Qt::Key_D:
//       isWall(10, 0);
//       break;
    default:
        break;
    }
}

void CtrlBall::isWall(int dx, int dy)
{
    if ((x + dx - rad >= 0) && (x + dx + rad <= 400)){
        x += dx;
    }
    if ((y + dy - rad >= 0) && (y + dy + rad <= 400)){
        y += dy;
    }
}

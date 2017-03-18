#ifndef CTRLBALL_HPP
#define CTRLBALL_HPP

#include <QWidget>
#include <QKeyEvent>
#include "Ball.hpp"

class CtrlBall : public Ball
{
    Q_OBJECT
public:
    explicit CtrlBall(QWidget *parent = 0);
    void isWall(int dx, int dy);

signals:

public slots:
    void moveFigure(QKeyEvent *event);
    void moveFigureX();

};

#endif // CTRLBALL_HPP

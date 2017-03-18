#ifndef Ball_H
#define Ball_H

#include "figure.hpp"


class Ball : public Figure
{
      Q_OBJECT

public:
    Ball(QWidget * parent = 0);
    void paintEvent(QPaintEvent *);
public slots:
    virtual void moveFigure();
    virtual void moveFigureX();
private:

    bool direction;
    bool direction2;

    int color;
    int color2;
    int color3;
protected:
    int rad;

};

#endif // Ball_H

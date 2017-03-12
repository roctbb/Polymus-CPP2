#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.hpp"


class Triangle : public Figure
{
      Q_OBJECT

public:
    Triangle(QWidget * parent = 0);
    void paintEvent(QPaintEvent *);
public slots:
    void moveFigure();
    void moveFigureX();
private:

    bool direction;
    bool direction2;
    int rad;
    int color;
    int color2;
    int color3;

};

#endif // TRIANGLE_H

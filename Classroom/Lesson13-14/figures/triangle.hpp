#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.hpp"

class Triangle : public Figure
{
      Q_OBJECT

public:
    Triangle(QWidget * parent = 0);
    void paintEvent(QPaintEvent *);
    void moveFigure();
private:
    int rad;
};

#endif // TRIANGLE_H

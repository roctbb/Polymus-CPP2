#ifndef POLYGON_H
#define POLYGON_H
#include "figure.hpp"


class Polygon : public Figure
{
    Q_OBJECT
public:
    Polygon(QWidget * parent = 0);
    void paintEvent(QPaintEvent *);
    void moveFigure();
};

#endif // POLYGON_H

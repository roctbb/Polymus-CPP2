#include "circle.hpp"



Circle::Circle(QWidget *parent) : QWidget(parent)
{
    x = 200;
    y = 200;
    rad = qrand()%30+20;
}

void Circle::paintEvent(QPaintEvent *)
{



}

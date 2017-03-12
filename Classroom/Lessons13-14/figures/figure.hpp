#ifndef FIGURE_H
#define FIGURE_H

#include <QWidget>

class Figure:public QWidget
{
    Q_OBJECT
protected:

    int x;
    int y;

public:
    Figure(QWidget * parent = 0);
    virtual void paintEvent(QPaintEvent *);
public slots:
    virtual void moveFigure();
};

#endif // FIGURE_H

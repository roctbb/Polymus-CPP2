#ifndef CIRCLE_HPP
#define CIRCLE_HPP


#include <QWidget>

class Circle : public QWidget
{
    Q_OBJECT
public:
    explicit Circle(QWidget *parent = 0);
    virtual void paintEvent(QPaintEvent *);

signals:

public slots:
private:
    int x;
    int y;
    int rad;
};

#endif // CIRCLE_HPP

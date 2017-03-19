#ifndef BALL_H
#define BALL_H

#include <QObject>
#include <QtGui>

class Ball : public QObject
{
    Q_OBJECT

protected:
    int x,y;
    int vx,vy;
    int r;
    QColor color;

public:
    explicit Ball(int width, int height, QObject *parent = 0);

    int GetX();
    int GetY();
    void ReverseX();
    void ReverseY();
    void Move();
    void Draw(QPainter& painter);
    int GetRadius();

signals:

public slots:
};

#endif // BALL_H

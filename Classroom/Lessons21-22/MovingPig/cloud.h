#ifndef CLOUD_H
#define CLOUD_H

#include <QWidget>
#include <QtGui>
#include <QLabel>
#include <QTimer>
class MainWindow;
class Cloud : public QLabel
{
    Q_OBJECT
protected:
    QTimer * timer;
    int speed;
    MainWindow *parentWindow;
public:
    void start();
    int getY();
    explicit Cloud(MainWindow *parent = 0);
protected:
    void paintEvent(QPaintEvent *event);

signals:

public slots:
    void moveMe();
};

#endif // CLOUD_H

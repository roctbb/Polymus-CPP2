#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtGui>
#include <QMainWindow>
#include <QTimer>
#include "figure.hpp"
#include "Ball.hpp"
#include "ctrlball.hpp"

#include <QVector>

#include <ctime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Figure *f;

    Ball *t[10];// circle
    QTimer *timer;
    qint8 lifes;

    QVector <Ball> vector;
    CtrlBall *ball;
protected:
    void keyPressEvent(QKeyEvent * event);
protected slots:
    void reduceLifes();


};

#endif // MAINWINDOW_H

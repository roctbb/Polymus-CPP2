#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtGui>
#include <QMainWindow>
#include <QTimer>
#include "figure.hpp"
#include "Ball.hpp"
#include "ctrlball.hpp"
#include "polygon.hpp"
#include <QVector>
#include "circle.hpp"
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

    Ball *t[100];// circle
    QTimer *timer;

    QVector <Ball> vector;
    CtrlBall *ball;
protected:
    void keyPressEvent(QKeyEvent * event);


};

#endif // MAINWINDOW_H

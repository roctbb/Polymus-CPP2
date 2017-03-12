#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "figure.hpp"
#include "triangle.hpp"
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

    Triangle *t[100];// circle
    Polygon *p;
    QTimer *timer;

    QVector <Triangle> vector;


};

#endif // MAINWINDOW_H

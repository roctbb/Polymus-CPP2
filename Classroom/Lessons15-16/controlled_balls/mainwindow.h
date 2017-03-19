#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ball.h"
#include "controlledball.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}
const int N = 30;
class MainWindow : public QMainWindow
{
    Q_OBJECT

    Ball * balls[N];
    ControlledBall * Debil;
    QTimer timer;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
protected:
    void paintEvent(QPaintEvent* event);
    void keyPressEvent(QKeyEvent *event);
protected slots:
    void moveBalls();
};

#endif // MAINWINDOW_H

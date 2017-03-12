#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ball.h"
#include <QtGui>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i<N; i++)
    {
        balls[i] = new Ball(this->size().width(), this->size().height());
    }
    timer.setInterval(50);
    connect(&timer, SIGNAL(timeout()),
            this, SLOT(moveBalls()));
    timer.start();
}

MainWindow::~MainWindow()
{
    for (int i = 0; i<N; i++)
    {
        delete balls[i];
    }
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);
    for (int i = 0; i<N; i++)
    {
        balls[i]->Draw(painter);
    }
}

void MainWindow::moveBalls() {
    for (int i = 0; i<N; i++)
    {
        if (balls[i]->GetX()>size().width() ||
                balls[i]->GetX()<0)
            balls[i]->ReverseX();
        if (balls[i]->GetY()>size().width() ||
                balls[i]->GetY()<0)
            balls[i]->ReverseY();
        balls[i]->Move();
    }

    this->repaint();
}

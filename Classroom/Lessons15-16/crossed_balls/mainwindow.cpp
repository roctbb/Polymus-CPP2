#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ball.h"
#include <QtGui>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(0,0,800,800);
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

bool isCrossed(double x1, double y1,
                 double x2, double y2,
                 double r1, double r2)
{
    //return условие столкновения;
}

void MainWindow::moveBalls() {
    //столкновения со стенкой
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
    //столкновения между собой
    for (int i = 0; i<N; i++)
    {
        for (int j = i+1; j<N; j++)
        {
            //посмотреть столкнулись ли шарики с номерами i и j
        }
    }


    this->repaint();
}

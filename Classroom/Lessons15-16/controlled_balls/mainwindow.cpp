#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ball.h"
#include <QtGui>
#include <QDebug>
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
    Debil = new ControlledBall(this->size().width(), this->size().height());
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
    delete Debil;
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
    Debil->Draw(painter);
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key()==Qt::Key_W)
    {
       Debil->moveUp();
    }
    if (event->key()==Qt::Key_D)
    {
       Debil->moveRight();
    }
    if (event->key()==Qt::Key_A)
    {
       Debil->moveLeft();
    }
    if (event->key()==Qt::Key_S)
    {
       Debil->moveDown();
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

    qDebug()<<Debil->getHealth();
    ui->label_3->setText(QString::number(Debil->getHealth()));
    ui->label_4->setText(QString::number(Debil->getPoints()));
    this->repaint();
}

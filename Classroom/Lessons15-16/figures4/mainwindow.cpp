#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QDebug>
#include <QLCDNumber>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), lifes(15)
{
    for (int i = 0; i < sizeof(t) / sizeof(void*); i++)
    {
        t[i] = new Ball(this);
    }

    ball = new CtrlBall(this);
    ui->setupUi(this);
    timer = new QTimer;
    timer->start(20);

    for (int i = 0; i < sizeof(t) / sizeof(void*); i++)
    {
        connect(timer, SIGNAL(timeout()), t[i], SLOT(moveFigure()));
        connect(timer, SIGNAL(timeout()), this, SLOT(reduceLifes()));
    }

    qDebug() << "Your life is " << lifes;



}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    qDebug()<<"Pressed "<<event->key();

    ball->moveFigure(event);
}

void MainWindow::reduceLifes()
{
    for (int i = 0;i < sizeof(t) / sizeof(void*); i++)
        if ((ball->getX() - t[i]->getX())*(ball->getX() - t[i]->getX()) +
                (ball->getY() - t[i]->getY())*(ball->getY() - t[i]->getY())
                <= (ball->getRad() + t[i]->getRad())*(ball->getRad() + t[i]->getRad()))
        {
            lifes--;
            t[i]->setCoords();
        }
    qDebug() << "LIFES: " << lifes;
}

MainWindow::~MainWindow()
{

    for (int i = 0; i < 100; i++)
    {
        delete t[i];

    }
    delete *t;

    delete timer;
    delete ui;
}

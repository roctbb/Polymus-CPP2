#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ball = new CtrlBall(this);
    ui->setupUi(this);
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    qDebug()<<"Pressed "<<event->key();

    ball->moveFigure(event);
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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ball.h"
#include <QtGui>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Vasya = new Ball(this->size().width(), this->size().height());
    timer.setInterval(50);
    connect(&timer, SIGNAL(timeout()),
            this, SLOT(moveBalls()));
    timer.start();
}

MainWindow::~MainWindow()
{
    delete Vasya;
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    Vasya->Draw(painter);
}

void MainWindow::moveBalls() {
    Vasya->Move();
    this->repaint();
}

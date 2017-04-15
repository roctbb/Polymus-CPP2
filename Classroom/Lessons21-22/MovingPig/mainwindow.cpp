#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bg = new QLabel(this);
    Yoba = new Cloud(this);
    this->Yoba->start();


}

void MainWindow::addDrop(int x)
{
    Drop * newDrop = new Drop(x, this);
    newDrop->start();
    newDrop->show();
    drops.push_back(newDrop);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    bg->setGeometry(0,0,this->width(), this->height());
    bg->setPixmap(QPixmap("/Users/roctbb/Downloads/windows-xp.jpg").scaled(this->width(),this->height(),Qt::KeepAspectRatioByExpanding));
}

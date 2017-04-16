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
    timer.setInterval(10);
    timer.start();
    connect(&timer, SIGNAL(timeout()), this, SLOT(deleteDrop()));


}

void MainWindow::addDrop(int x)
{
    Drop * newDrop = new Drop(x, this);
    newDrop->start();
    newDrop->show();
    drops.push_back(newDrop);
}

void MainWindow::deleteDrop()
{
    for (QList<Drop*>::iterator iter = drops.begin(); iter != drops.end(); ++iter)
    {
        if((*iter)->getY() >= this->height() - 100)
        {
            delete *iter;
            drops.erase(iter);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    bg->setGeometry(0,0,this->width(), this->height());
    bg->setPixmap(QPixmap("c:\\Users\\..path..\\backgnd.png").scaled(this->width(),this->height(),Qt::KeepAspectRatioByExpanding));
}

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    f = new Figure(this);
    t = new Triangle(this);
    p = new Polygon(this);

    timer =     new QTimer;
    timer->start(10);
    connect( timer, SIGNAL( timeout() ), p, SLOT(moveFigure()) );
    connect( timer, SIGNAL( timeout() ), t, SLOT(moveFigure()) );
    connect( timer, SIGNAL( timeout() ), f, SLOT(moveFigure()) );

    ui->setupUi(this);
}



MainWindow::~MainWindow()
{

    delete p;
    delete t;
    delete f;
    delete timer;
    delete ui;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    for (int i = 0; i < 100; i++)
    {
        t[i] = new Triangle(this);

    }
    timer =     new QTimer;
    timer->start(10);
   // connect( timer, SIGNAL( timeout() ), p, SLOT(moveFigure()) );
    qsrand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        int temp = qrand() % 2;
        if (temp){
            connect( timer, SIGNAL( timeout() ), t[i], SLOT(moveFigure()) );
        }
        else
        {
            connect( timer, SIGNAL( timeout() ), t[i], SLOT(moveFigureX()) );
        }

    }
    //connect( timer, SIGNAL( timeout() ), f, SLOT(moveFigure()) );

    ui->setupUi(this);
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

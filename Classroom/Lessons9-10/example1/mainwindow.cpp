#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    n = 0;
    connect(ui->pushButton, SIGNAL(clicked(bool)),this,  SLOT(inc()) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inc()
{
    n++;
    ui->lcdNumber->display(n);
}
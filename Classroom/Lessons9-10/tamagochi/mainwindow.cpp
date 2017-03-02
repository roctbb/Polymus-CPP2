#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tamagochi.hpp"
#include <QTimer>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    animal = new Tamagochi;
    timer = new QTimer;

    ui->labelNameOfAnimal->setText(animal->getName());


    connect( ui->pushButtonFood, SIGNAL( clicked() ),this, SLOT( giveFood() ) );
    connect( ui->pushButtonPlay, SIGNAL( clicked() ),this, SLOT( giveHappy() ) );
    connect( ui->pushButtonWash, SIGNAL( clicked() ),this, SLOT( giveHearth() ) );
    timer->start(3000);
    connect( timer, SIGNAL( timeout() ),this, SLOT( timeIsGo() ) );

    updateInformation();
}

MainWindow::~MainWindow()
{

    delete animal;
    delete timer;
    delete ui;
}

void MainWindow::updateInformation()
{
    ui->lcdNumberFood->display(animal->getFood());
    ui->lcdNumberHealth->display(animal->getHealth());
    ui->lcdNumberHappyness->display(animal->getHappiness());
    if(animal->isHappy())
    {
        ui->labelImage->setPixmap(QPixmap("good.jpg"));
    }
    else
    {
        ui->labelImage->setPixmap(QPixmap("angry.jpg"));
    }
    if(!animal->isAlive())
    {
        timer->stop();
       // this->hide();
        QMessageBox gameOver;
        gameOver.show();
        gameOver.setText("Game over. Ваш зверь умер");
        gameOver.setDefaultButton(QMessageBox::Ok);
        switch (gameOver.exec())
        {
            case QMessageBox::Ok:
            {
                this->close();
                break;
            }
        }
    }
}

void MainWindow::giveFood()
{
    animal->feed();
    updateInformation();
}

void MainWindow::giveHearth()
{
    animal->wash();
    updateInformation();
}

void MainWindow::giveHappy()
{
    animal->play();
    updateInformation();
}

void MainWindow::timeIsGo()
{
    animal->timeIsGo();
    updateInformation();
}


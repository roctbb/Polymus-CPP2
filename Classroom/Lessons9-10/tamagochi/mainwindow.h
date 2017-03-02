#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "tamagochi.hpp"
#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void updateInformation();

private slots:
void giveFood();
void giveHearth();
void giveHappy();
void timeIsGo();

private:
    Ui::MainWindow *ui;
    Tamagochi *animal;
    QTimer *timer;
};

#endif // MAINWINDOW_H

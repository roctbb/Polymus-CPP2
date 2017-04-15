#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QtGui>
#include "cloud.h"
#include "drop.h"
#include <QList>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QLabel * bg;
    Cloud * Yoba;
    QList<Drop*> drops;
public:
    explicit MainWindow(QWidget *parent = 0);
    void addDrop(int x);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *event);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

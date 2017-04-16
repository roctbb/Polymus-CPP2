#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QtGui>
#include "cloud.h"
#include "drop.h"
#include <QList>
#include <QTimer>
#include <iterator>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QLabel * bg;
    Cloud * Yoba;
    QList<Drop*> drops;
    QTimer timer;
public:
    explicit MainWindow(QWidget *parent = 0);
    void addDrop(int x);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *event);
private:
    Ui::MainWindow *ui;
public slots:
    void deleteDrop();
};

#endif // MAINWINDOW_H

# Занятия 9-10: Основы QT
## Что такое QT?
 	
QT это кроссплатформенный фреймворк, включаещий множество элементов управления, и созданный для разработки кроссплатформенных приложений, использующий GUI на языке C++. Qt позволяет запускать написанное с его помощью ПО в большинстве современных операционных систем путём простой компиляции программы для каждой ОС без изменения исходного кода.
## Механизм сигналов и слотов
Механизм сигналов и слотов является одной из отличительных особенностей QT и позволяет с легкостью управлять с помощью одних объектов другими. 
Чтобы использовать механизм сигналов и слотов в своем классе необходимо добавить директиву **Q_OBJECT** и наследовать свой класс от QObject или QWidget
```cpp
class Tamagochi:public QWidget
{
    Q_OBJECT
    .......
private:

public:
};
```

Для соединения объектов между собой требуется использовать функцию  QObject::connect(отправитель, сигнал, приемник, слот);

Например:
```cpp
    connect(ui->pushButton, SIGNAL(clicked(bool)),this,  SLOT(inc()) );

```
## Пример main.cpp

```cpp
#include "mainwindow.h" // подключенние заголовочного файла главного окна(формы)
#include <QApplication> // подключение заголовочного файла стандартного QT приложения

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //создание объекта прилождения QT
    MainWindow w; // создание объекта главного окна
    w.show(); // вызов стандартного для QWidget метода show(), показывающего объект

    return a.exec();
}
```
## Работа с таймером
Чтобы работать с таймером в QT необходимо подключить заголовочный файл QTimer (#include <QTimer>).
```cpp
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
public slots:
    void inc();
private:
    int n;
    QTimer *timer;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
```

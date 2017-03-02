#ifndef TAMAGOCHI_H
#define TAMAGOCHI_H

#include <QWidget>
#include <QObject>
#include <QString>

class Tamagochi:public QWidget
{
    Q_OBJECT
private:
    int health;
    int happiness;
    int food;
    int lastPlay;
    int lastFeed;
    int lastWash;

    QString name;

public:
    Tamagochi();
    bool isAlive();
    bool isHappy();

    int getHealth() const;
    int getHappiness() const;
    int getFood() const;
    QString getName() const;


    void feed();
    void wash();
    void play();
    void timeIsGo();
};

#endif // TAMAGOCHI_H







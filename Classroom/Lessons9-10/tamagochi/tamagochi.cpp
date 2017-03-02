#include "tamagochi.hpp"
#include <ctime>



Tamagochi::Tamagochi()
{
    srand(time(0));
    QString names[29] = {"Abby", "Angel", "Annie", "Baby", "Bailey", "Bandit", "Bear", "Bella", "Bob", "Boo",
                         "Boots", "Bubba", "Buddy", "Buster", "Cali", "Callie", "Casper", "Charlie",
                         "Chester", "Chloe", "Cleo", "Coco", "Cookie", "Cuddles", "Daisy", "Dusty", "Felix",
                         "Fluffy", "Garfield"};
    name = names[std::rand() % 29];
    health = 100 + std::rand() % 150;
    happiness = 100 + std::rand() % 150;
    food = 100 + std::rand() % 150;
    lastPlay = std::time(NULL);
    lastFeed = std::time(NULL);
    lastWash = std::time(NULL);

}

bool Tamagochi::isAlive()
{
    if (health <= 0 ||food <= 0 ||happiness <= 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Tamagochi::isHappy()
{
    if (health <= 100 ||food <= 100 ||happiness <= 100)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int Tamagochi::getHealth() const
{
    return health;
}

void Tamagochi::wash()
{
     health += 150;
}

int Tamagochi::getHappiness() const
{
    return happiness;
}

void Tamagochi::play()
{
    happiness += 150;
}

void Tamagochi::timeIsGo()
{
    food-=200;
    happiness-=200;
    health-=200;
}

int Tamagochi::getFood() const
{
     return food;
}

void Tamagochi::feed()
{
    food += 150;
}

QString Tamagochi::getName() const
{
    return name;
}


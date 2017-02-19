#include <iostream>
#include <cmath>

using namespace std;

class Cat {
protected:
    int hunger = 0;
public:
    void setHunger(int hunger) {
        Cat::hunger = hunger;
    }

    void say() {
        for (int i = 0; i < hunger; i++)
            cout << "meow ";
        cout << endl;
    }
};

class Dog : public Cat {
public:
    void say() {
        for (int i = 0; i < hunger; i++)
            cout << "bark ";
        cout << endl;
    }
};

int main() {
    Cat Masha;
    Masha.setHunger(3);

    Dog Bobik;
    Bobik.setHunger(2);

    Masha.say(); // meow meow meow
    Bobik.say(); // bark bark
}

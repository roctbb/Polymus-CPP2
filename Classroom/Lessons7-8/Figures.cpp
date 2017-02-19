#include <iostream>
#include <cmath>

using namespace std;

class Figure {
public:
    virtual void draw() {}
};

class Rectangle : public Figure {
    int w,h;
public:
    Rectangle(int w, int h) : w(w), h(h) {}
    void draw()
    {
        for (int i=0; i<h; i++)
        {
            for (int j=0; j<w; j++)
                cout<<"* ";
            cout<<endl;
        }
        cout<<endl;
    }
};

class Stairs : public Figure {
    int h;
public:
    Stairs(int h) : h(h) {}
    void draw()
    {
        for (int i=0; i<h; i++)
        {
            for (int j=0; j<i+1; j++)
                cout<<"* ";
            cout<<endl;
        }
        cout<<endl;
    }
};

class FigureGenerator {
public:
    static Figure* Generate()
    {
        if (rand()%2==0)
            return new Stairs(rand()%5+2);
        return new Rectangle(rand()%5+2,rand()%5+2);
    }
};

int main() {
    for (int i = 0; i<3; i++)
    {
        Figure* figure = FigureGenerator::Generate();
        figure->draw();
        delete figure;
    }
}


#include <iostream>
#include <ctime>
#include <stack>
using namespace std;

template <class T>
class Stack {
    T * mas;
    int realSize;
    int head;
    void resize(int newSize)
    {
        T * temp = new T[newSize];
        for (int i=0; i<realSize; i++)
        {
            temp[i]=mas[i];
        }
        delete [] mas;
        mas = temp;
        realSize = newSize;
    }

public:
    Stack()
    {
        mas = new T[255]; //начальный размер
        realSize = 255;
        head = 0;
    }
    ~Stack()
    {
        delete [] mas;
    }
    bool Empty()
    {
        return head == 0;
    }
    void Push(T value)
    {
        if (head==realSize)
        {
            resize(realSize*2);
        }
        mas[head]=value;
        head++;
    }
    T Pop()
    {
        head--;
        return mas[head];
    }
};


int main() {

    int t = time(0);
    Stack <int> q;
    for (int j=0; j<100; j++)
    {
        for (int i=0; i<1000000; i++)
        {
            q.Push(i);
        }
        while (!q.Empty())
        {
            q.Pop();
        }
    }
    cout<<"My Stack Time:"<<time(0)-t<<endl;

    t = time(0);
    stack <int> q1;
    for (int j=0; j<100; j++)
    {
        for (int i=0; i<1000000; i++)
        {
            q1.push(i);
        }
        while (!q1.empty())
        {
            q1.pop();
        }
    }
    cout<<"STL Time:"<<time(0)-t<<endl;

}

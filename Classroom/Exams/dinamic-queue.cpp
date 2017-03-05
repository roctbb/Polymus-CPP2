#include <iostream>
#include <ctime>
#include <queue>
using namespace std;

template <class T>
class Queue {
    T * mas;
    int realSize;
    int start, end;
    void resizeAndFit(int newSize)
    {
        int startPos = start;
        T * temp = new T[newSize];
        for (int i=startPos; i<realSize; i++)
        {
            temp[i-startPos]=mas[i];
        }
        delete [] mas;
        mas = temp;
        realSize = newSize;
        start = 0;
        end = end - startPos;
    }

public:
    Queue()
    {
        mas = new T[255]; //начальный размер
        realSize = 255;
        start = 0;
        end = 0;
    }
    ~Queue()
    {
        delete [] mas;
    }
    bool Empty()
    {
        return start == end;
    }
    void Push(T value)
    {
        if (end==realSize)
        {
            resizeAndFit(realSize*2);
        }
        mas[end] = value;
        end++;
    }
    T Pop()
    {
        end--;
        return mas[end];
    }
};


int main() {

    int t = time(0);
    Queue <int> q;
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
    cout<<"My Queue Time:"<<time(0)-t<<endl;

    t = time(0);
    queue <int> q1;
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

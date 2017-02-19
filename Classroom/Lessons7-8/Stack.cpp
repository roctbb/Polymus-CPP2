#include <iostream>
#include <cmath>

using namespace std;

template<class T>
class Stack {
    T array[255];
    int head = 0;
public:
    void push(T value) {
        if (head < 255) {
            array[head++] = value;
            return;
        }
        throw;
    }

    T pop() {
        if (head > 0) {
            return array[--head];
        }
        throw;
    }

    bool isEmpty() {
        return head == 0;
    }

};

int main() {
    Stack<int> stack;
    for (int i = 0; i < 5; i++)
        stack.push(i);
    while (!stack.isEmpty())
        cout << stack.pop() << " "; // 4 3 2 1 0
}

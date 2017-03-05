### Задание 1
**Теория:** Три принципа ООП.

```cpp
#include <iostream>
#include <cstdlib>

using namespace std;

class Dog {
protected:
    int hunger;
public:
    Dog(int _hunger) {
        hunger = _hunger;
    }
    void voice() {
        for (int i=0; i<hunger; i++)
            cout<<"wow ";
    }

};
class Wolf:public Dog {
public:
    Wolf (int a) : Dog (a*2) {

    }
    void voice() {
        cout<<"a";
        for (int i=0; i<hunger; i++)
            cout<<"u";
    }
};

int main()
{
    Dog A(2);
    Wolf B(4);
    A.voice();
    B.voice();
    return 0;
}
```
### Задание 2
**Теория:** Три типа памяти. Указатель и операции с указателями.

```cpp
#include <iostream>
using namespace std;
int main()
{
    int a = 3;
    int b = 2;
    int * c;
    int * d;
    c = &a;
    d = &b;
    cout<<*c**d;

    int mas[10];

    for (int i=0; i<10; i++)
        mas[i] = i;
    int * mas1 = mas+9;
    for (int i=0; i<10; i++)
       cout<<*(mas1-i);
}
```
### Задание 3
Реализуйте структуру данных очередь, которая поддерживает три операции:
 - push - добавление элемента в конец очереди
 - pop - возвращает первый элемент в очереди и удаляет его
 - empty - возвращает true, если очередь пуста
Используйте шаблоны.

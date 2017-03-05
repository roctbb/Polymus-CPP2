### Задание 1
**Теория:** Класс. Свойства и методы. Конструктор и деструктор.

```cpp
#include <iostream>
#include <cstdlib>

using namespace std;

class A {
    int a;
public:
    A(int _a) {
        a = _a;
        cout<<"A";
    }
    ~A() {
        cout<<"B";
    }
    void func() {
        cout<<a;
    }
};

int main()
{
    A a(1);
    cout<<"C";
    for (int i=0;i<2;i++) {
        A b(2);
        b.func();
        a.func();
    }
    cout<<"C";
    return 0;
}
```


### Задание 2
**Теория:** Динамическая память и операции для работы с ней?

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
Сколько памяти будет утеряно?
```cpp
#include <iostream>
using namespace std;
int main() {
    for (int i=0; i<1024*1024*1024; i++)
        char * a = new char;
}
```
### Задание 3
Реализуйте структуру данных стэк, которая поддерживает три операции:
 - push - добавление элемента на вершину стэка
 - pop - возвращает верхний элемент и удаляет его
 - empty - возвращает true, если стэк пуст
Используйте шаблоны.

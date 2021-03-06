# Занятия 5-6: Работа с динамической памятью
## Три типа памяти: статическая, стэк, куча
В оперативной памяти на самом деле существует три механизма выделения памяти:
 - статическая память
 - динамическая память (куча)
 - стэк

В **статической памяти** находятся все глобальные переменные, переменные, помеченные ключевым словом *static* и сам код программы.
 
В **стэке** находятся все переменные, определенные внутри функций, а также параметры функций. Переменные удаляются из стэка в момент закрытия фигурной скобочки, в которой они были созданы.

Память в **куче** выделяется и освобождается в процессе работы программы. Для выделения и освобождения такой памяти используются операции *new* и *delete*. У переменных в динамической памяти нет имен, поэтому для доступа к такой переменной нужно знать ее **адрес**.

**Адрес переменной** в оперативной памяти - это порядковый номер первой ячейки памяти, в которой хранится ее содержимое, записанный в шестнадцатиричной системе счисления.

## Указатели и операции с ними

Для хранения адресов других переменных в С++ существуют специальный тип данных - указатель.

**Указатель** - это переменная, которая содержит в себе адрес другой переменной. Размер любого указателя в 64-битной системе - 64 бита (эквивалентно long long).

```cpp
int* ptr1; // это указатель на переменную типа int
double* ptr2; // это указатель на переменную типа double
Animal* ptr2; // это указатель объект типа Animal
```
Для работы с указателями используются две специальные операции - **переход по указателю** (\*) и **получение адреса переменной** (&). 
```cpp
int a = 10; // это обычная переменная
int* ptr = &a; //это адрес переменной a
cout << ptr; // это 0x7fff57c03acc 
cout << *ptr; // это 10 - значение переменной по адресу ptr - т.е. переменной a
```
### Связь указателей и массивов

На самом деле название любого массива в C++ - это адрес его первой ячейки. Поэтому операция [] эквивалетна прибавлению индекса к адресу (С++ знает тип данных массива и самостоятельно рассчитает правильное число байт) и перехода по этому адреса. Следующие два примера кода работают одинаково:

```cpp
int mas[5] = { 1, 2, 3, 4, 5};
for (int i = 0; i < 5; i++)
    cout << mas[i];
```
```cpp
int mas[5] = {1, 2, 3, 4, 5};
for (int i = 0; i < 5; i++)
    cout << *(mas + i);
```
Именно поэтому, если функция принимает параметром массив, то тип данных ее параметра - это указатель (например *char\** для строки в стиле СИ)

## Работа с динамической памятью

Для выделения и освобождения динамической памяти используются операции *new* и *delete*. Операция *new* в результате своей работы возвращает **адрес первой ячейки выделенной памяти**.

**Создание перменной в динамической памяти:**
```cpp
int* ptr = new int; // создаем переменную типа int в динамической памяти

*ptr = 10;
cout<< *ptr;

delete ptr; //освобождаем выделенную память
```

**Создание динамического массива:**
```cpp
int size;
cin>>size;

int* mas = new int[size]; // да, теперь так можно!

for (int i = 0; i < size; i++)
    mas[i] = rand() % 100;

delete [] mas; //освобождаем массив целиком
```



**Любая динамически выделенная память обязательно должна быть вручную освобождена**. Ошибка, при которой выделенная память не освобождается программистом называется **утечкой памяти**. Пример:

```cpp
int* mas;

for (int i = 0; i < 10000; i++)
    mas = new int[255]; //при выделение новой памяти, мы теряем указатель на старую
// в итоге потеряно 255 * 4 * 10000 байт памяти
```

## Структура данных "Вектор"

**Структура данных** - это класс, позволяющий удобно хранить и обрабатывать однотипные данные.

**Вектор** - это структура данных, которая делает работу с динамическом массивом более безопасной, исключая вероятность утечки памяти.

Класс *вектор* содержит в себе указатель на динамический массив, его размер, а также поддерживать следующие операции:
 - Изменения размера массива
 - Добавление элемента в ячейку
 - Получения значения ячейки массива
 
В деструкторе класса *вектор* выделенная память должна освобождаться. 

```cpp
class Vector {
    int* array;
    int size;
public:
    Vector(int _size); // выделяет память
    ~Vector(); // освобождает память
    
    int get(int i); // возвращает значение ячейки i
    void set(int i, int value); //изменяет значение ячейки i
    
    void resize(int newSize); //выделяет новую память, копирует в нее старую и освобождает ее
};
```
## Шаблоны

Шаблоны позволяют автоматизировать копирование классов и функций для работы с разными типами данных.

Например, класс вектор часто приходиться использовать с разными типами данных, поэтому в качестве типа данных массива можно использовать шаблон, а тип конкретный тип данных указывать уже при создании объекта.

```cpp
template <class T>
class Vector {
    T* array;
    int size;
public:
    Vector(int _size); // выделяет память
    ~Vector(); // освобождает память

    T get(int i); // возвращает значение ячейки i
    void set(int i, T value); //изменяет значение ячейки i

    void resize(int newSize); //выделяет новую память, копирует в нее старую и освобождает ее
};

int main() {
    Vector <double> vec1(255);
    Vector <int> vec2(255);
}
```

## Виртуальные функции
### Виртуальные функции

Рассмотрим пример:

```cpp
#include <iostream>

using namespace std;

class Tiger {
public:
    void say()
    {
        cout << "Roar" << endl;
    }
};

class Cat : public Tiger {
public:
    void say()
    {
        cout << "Myau" << endl;
    }
};

int main() {
    Cat* Masha = new Cat();
    Tiger* Petka = new Cat();

    Masha->say(); // эквивалетно (*Masha).say()
    Petka->say();

    delete Masha;
    delete Petka;
}
```

В начале мы создаем два класса: кошка и тигр. Кошка наследует от тигра, изменяя метод `say`. Затем мы пробудем положить адрес кошки в указатель на кошку и в указатель на тигра. 

Несмотря на то, что во втором случае по адресу тигра на самом деле лежит кошка, в итоге будет вызван метод `say()` от тигра.

```
Myau
Roar
```

В некоторых случаях будет удобно хранить в одном массиве объекты разных типов (унаследованных от одного), как указатели на тип родителя, но при этом сохранять их исходную функцинальность. Для этого методы родительского класса нужно сделать **виртуальными**.

```cpp
#include <iostream>

using namespace std;

class Tiger {
public:
    virtual void say() // теперь функция виртуальная
    {
        cout<<"Roar"<<endl;
    }
};

class Cat : public Tiger {
public:
    void say()
    {
        cout<<"Myau"<<endl;
        }
};

int main() {
    Cat* Masha = new Cat();
    Tiger* Petka = new Cat();

    Masha->say();
    Petka->say();

    delete Masha;
    delete Petka;
}
```

Теперь метод `say()` виртуальный, и теперь когда мы положим адрес кошки в указатель на тигра, в итоге она все равно будет мяукать.
```
Myau
Myau
```



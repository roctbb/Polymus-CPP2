# Занятия 1-2: Введение в ООП на С++

### Что такое процедурное программирование?

**Парадигма программирования** - это подход, "философия", основные принципы, по которым строится программа.

Программа в **процедурной парадигме** - это алгоритм и данные. Алгоритм может быть описан с помощью блок-схемы, а данные - это переменные базовых типов.

В общем случае можно сказать, что любая программа, которая описывается блок-схемой - процедурная.


### Что такое объектно-ориентированное программирование?

**Абстракция** - это модель объекта или явления, которая учитывает лишь необходимые для конкретной задачи свойства реального объекта или процесса и игнорует несущественные.

В **объектно-ориентированной парадигме** программа - это абстракция реально происходящих в жизни процессов, она состоит из взаимодействующих между собой объектов. Объекты содержат внутри себя как данные, там и операции для работы с ними.

### Понятие структуры, класса, объекта.

**Класс** - описание пользовательского типа данных. Класс включает в себя свойства (произвольные переменные) и методы - функции для работы со свойствами.

**Объект** - реализация класса, переменная.

**Структура** - это тот же класс, только уровень доступа по умолчанию - public (см. инкапсуляция).

Например, класс Собака - это описание собаки в общем виде, он говорит, что у собаки должен быть возраст и порода, она умеет гавкать. А объект этого класса - переменная Шарик - это конкретная дворняшка 2ух летнего возраста.

```
class Dog {
public:
  int age;
  string type;
  
  void Bark()
  {
    cout<<"Wow"<<endl;
  }
}

void main()
{
  Dog Sharik;
  Sharik.age = 2;
  Sharik.Bark();
}
```

Почему класс Собака - это абстракция? На самом деле у собаки бесчисленное множество свойств, начиная от цвета шерсти (а он еще и меняется) и заканчивая, например, длиной пищевода. Но в данной модели мы их не учитываем, потому что они не важны для нашей задачи.

### Конструктор и деструктор.

**Конструктор** - это метод класса, автоматически вызываемый при **создании** объекта класса.

**Деструктор** - это метод класса, автоматически вызываемый при **уничтожении** объекта класса.

```
class Alien {
public:
  string name;
  Alien(string _name) //это конструктор
  {
    name = _name;
    cout<<name<<" is born";
  }
  ~Alien() //это деструктор
  {
    cout<<name<<" is dead";
  }
}

void main()
{
   Alien a("Vupsen"); //вызван конструктор a
   for (int i = 0; i<2; i++)
   {
      Alien b("Pupsen"); //вызван конструктор b
   } //вызван деструктор b
} //вызван деструктор a
```
**Результат:**
```
Vupsen is born
Pupsen is born
Pupsen is dead
Pupsen is born
Pupsen is dead
Vupsen is dead
```
### Инкапсуляция.

**Инкапсуляция** - это разделение прав доступа к элементам класса (а значит объекта этого класса) для его пользователей - других программистов (и вас).

Существует три уровня доступа: **private, protected и public**.
 - Элементы класса в секции private доступны только из методов этого класса.
 - Элементы класса в секции protected доступны только из методов класса и его наследников (об этом позже).
 - Элементы класса в секции public доступны извне.
```
class test {
public:
  int a;
private:
  int b;
  void func()
  {
     cout<<"test"
  }
public:
  void setB(int _b)
  {
    b = _b;
  }

}

void main()
{
   test A;
   A.a = 10; //так можно, a - public
   A.b = 15; //это ошибка при компиляции, тк b - private
   A.func(); //так тоже нельзя
   A.setB(15); //а так - можно!
   
}
```

### Статические методы.

**Статический метод** - это метод класса, который можно вызывать без создания объекта. Также существуют статические свойства.

В полностью ООП языках, таких, как Java, нельзя создать обычную функцию вне какого либо класса. Для этого приходится использовать статические методы. С++ - это мультипарадигмальный язык (можно писать код в разных парадигмах), но при написании ООП кода использование статических методов вместо функций будет хорошим тоном.

```
class Math {
public:
  static Product(int a, int b)
  {
    return a*b;
  }
}

void main()
{
   cout<<Math::product(5,6);
}
```

### Обработка исключений.

Когда в вашей программе в процессе выполнения какой либо функции возникает неожиданная ситуация, об этом часто необходимо сообщить вызывающей стороне. Иногда это можно сделать, например, вернув false, но иногда так сделать нельзя (например, если функция деления, возвращающая результат получила на вход делитель 0). В этом случае можно воспользоваться механизмом исключений - try/catch.

**Пример:**
```
int func(int a)
{
    if (a>5)
    {
        throw "bigger than five"; // кинуть исключение
    }
    if (a<5)
    {
        throw "bigger than five"; // кинуть исключение
    }
    return 0;
}

int main()
{
    int a;
    cin>>a;

    try
    {
        func(a);
        cout<<"all is ok - a=5"<<endl;
    }
    catch (const char * error) // ловим строку, если исключение - не строка - программа аварийно завершится
    {
        cout<<"error: "<<error<<endl;
    }
    cout<<"end";

}
```
**Но можно и проще:**

```
int main()
{
    int a;
    cin>>a;

    try
    {
        func(a);
        cout<<"all is ok - a=5"<<endl;
    }
    catch (...) // ловим произвольное исключение
    {
        cout<<"error:";
    }
    cout<<"end";

}
```
Подробнее об исключениях:
 - [Codenet](http://www.codenet.ru/progr/cpp/Try-Catch-Throw.php)
 - С. Прата - Язык С++: Лекции и упражнения, глава 15

## Примеры на занятии.
 - AccountSimple - класс Account, который хранит информацию о счете в банке.
 - AccountFile - обновление класса Account, который теперь автоматически подгружает информацию из файла и сохраняет в файл.

## Литература.
 - С. Прата - Язык С++: Лекции и упражнения, глава 10
 
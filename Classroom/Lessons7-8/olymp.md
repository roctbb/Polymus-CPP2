### Прямая
```cpp
int main() {
    Line A (3,4);

    A.show(); // 3x + 4 = y

    cout<<A.checkPoint(0, 0)<<endl; // false: 3*0 + 4 != 0;
    cout<<A.checkPoint(2, 10)<<endl; // true: 3*2 + 4 == 10;

    return 0;
}
```
### Вектор
```cpp
int main() {
    Vector2d A(2,3);
    Vector2d B(4,5);

    Vector2d C = Vector2d::sum(A,B);

    cout<<C.getX()<<" "<<C.getY()<<endl; // 6 8
    cout<<C.length(); // 10



    return 0;
}
```
### Кошкин дом
```cpp
int main() {
    Cat Masha;
    Masha.setHunger(3);
    
    Dog Bobik;
    Bobik.setHunger(2);
    
    Masha.say(); // meow meow meow
    Bobik.say(); // bark bark
}
```
### Художник
```cpp
class Figure;
class Stairs;
class Rectangle;

int main() {
    for (int i = 0; i<3; i++)
    {
        Figure* figure = FigureGenerator::Generate();
        figure->draw();
        delete figure;
    }
}
```
```
* * * * 
* * * * 
* * * * 

* 
* * 
* * * 

* 
* * 
```
### Дроби
```cpp
int main() {
    Fraction f1(3, 6);
    Fraction f2(2, 3);

    f1.print(); // 1/2
    f2.print();  // 2/3

    Fraction f3 = Fraction::sum(f1, f2);
    Fraction f4 = Fraction::multiply(f1, f2);

    f3.print(); // 7/6
    f4.print();  // 1/3
}
```
### Стэк
```cpp
int main() {
    Stack <int> stack;
    for (int i=0; i<5; i++)
        stack.push(i);
    while(!stack.isEmpty())
        cout<<stack.pop()<<" "; // 4 3 2 1 0 
}
```


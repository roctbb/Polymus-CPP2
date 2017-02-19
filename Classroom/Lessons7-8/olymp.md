## Вектор
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

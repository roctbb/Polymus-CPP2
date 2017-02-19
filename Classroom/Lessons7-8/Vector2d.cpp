#include <iostream>
#include <cmath>

using namespace std;

class Vector2d {
    int x, y;
public:
    Vector2d(int x, int y) : x(x), y(y) {}

    int getX() const {
        return x;
    }

    void setX(int x) {
        Vector2d::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        Vector2d::y = y;
    }

    float length() {
        return sqrt(x * x + y * y);
    }

    static Vector2d sum(Vector2d &a, Vector2d &b) {
        Vector2d C(a.x + b.x, a.y + b.y);
        return C;
    }

};


int main() {
    Vector2d A(2, 3);
    Vector2d B(4, 5);

    Vector2d C = Vector2d::sum(A, B);

    cout << C.getX() << " " << C.getY() << endl; // 6 8
    cout << C.length(); // 10



    return 0;
}

#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

class Fraction {
    int up, down;
public:
    Fraction(int up, int down) : up(up), down(down) {}

    void print() {
        int delimiter = gcd(up, down);
        cout << up / delimiter << " / " << down / delimiter << endl;
    }

    static Fraction sum(Fraction &a, Fraction &b) {
        Fraction C(a.up * b.down + a.down * b.up, a.down * b.down);
        return C;
    }

    static Fraction multiply(Fraction &a, Fraction &b) {
        Fraction C(a.up * b.up, a.down * b.down);
        return C;
    }


};

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

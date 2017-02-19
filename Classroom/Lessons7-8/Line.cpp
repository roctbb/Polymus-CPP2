#include <iostream>
#include <cmath>

using namespace std;

class Line {
    int k, b;
public:
    Line(int k, int b) : k(k), b(b) {}

    void show()
    {
        if (b>0)
            cout<<k<<"x + "<<b<<" = y";
        else
            cout<<k<<"x - "<<abs(b)<<" = y";
        cout<<endl;
    }
    bool checkPoint(int x, int y)
    {
        if (x*k+b == y)
            return true;
        return false;
    }

};


int main() {
    Line A (3,4);

    A.show(); // 3x + 4 = y

    cout<<A.checkPoint(0, 0)<<endl; // false: 3*0 + 4 != 0;
    cout<<A.checkPoint(2, 10)<<endl; // true: 3*2 + 4 == 10;

    return 0;
}

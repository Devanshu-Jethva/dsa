#include <bits/stdc++.h>
using namespace std;
#define long long ll

class Demo
{
    int x;
    int *y;
    const int z;

public:
    // constructor = ctor - old style

    // Demo(int x, int _y, int _z = 0) // default argument
    // {
    //     this->x = x;
    //     y = new int(_y);
    //     z = _z;
    // }

    // Initialization list : new style
    Demo(int _x, int _y, int _z = 0) : x(_x), y(new int(_y)), z(_z)
    {
        cout << "in initializer list" << endl;
        // z = 20;   // not compile
    }

    int getX() const // now we cant change properties of this class inside this function
    {
        return x;
    }
    void setX(int _x)
    {
        x = _x;
    }
    int getY() const
    {
        // int temp;
        // y = &temp;
        return *y;
    }
    void setY(int val)
    {
        *y = val;
    }
    int getZ() const
    {
        return z;
    }
};

void printDemo(const Demo &a)
{
    // a.setX(3); // using const reference 'a' we can call only const methods
    cout << a.getX() << " " << a.getY() << " " << a.getZ() << endl;
}

int main()
{

    Demo a(1, 2);

    printDemo(a);

    return 0;
}
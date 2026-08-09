#include <bits/stdc++.h>
using namespace std;

class Demo
{
public:
    int x, y;
    static int a, b;

    void print() const
    {
        // here even if parameter list is empty, this pointer is passed which is pointing to current object
        cout << "instance method : " << __FUNCTION__ << endl;
        cout << this->x << " " << this->y << endl;
        cout << a << " " << b << endl;
    }
    static void show()
    {
        // this pointer is not accessible
        cout << "static method : " << __FUNCTION__ << endl;
        cout << a << " " << b << endl;
    }
};

int Demo::a;
int Demo::b;

int main()
{
    Demo obj1 = {1, 2};
    Demo obj2 = {3, 4};
    obj1.print();
    obj2.print();

    obj1.a = 10;
    obj1.b = 20;
    obj1.print();
    obj2.print();

    obj2.a = 100;
    obj2.b = 200;
    obj1.print();
    obj2.print();

    Demo::show();

    return 0;
}
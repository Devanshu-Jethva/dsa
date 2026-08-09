#include <bits/stdc++.h>
using namespace std;

class Demo
{
public:
    int x;
    int *y;

    Demo(int _x, int _y) : x(_x), y(new int(_y)) {};

    // default dumb copy constructor : it does SHALLOW copy
    Demo(const Demo &obj) // Demo b = a; => obj = a
    {
        this->x = obj.x;
        this->y = obj.y;
    }

    // our smart DEEP copy
    // Demo(const Demo &obj)
    // {
    //     x = obj.x;
    //     y = new int(*obj.y);
    // }

    void print() const
    {
        cout << "X : " << x << endl
             << "pointer y : " << y << endl
             << "content at y (*y) : " << *y << endl
             << endl;
    }

    ~Demo()
    {
        delete y;
    }
};

int main()
{

    // Demo a(1, 2);
    // cout << "Object a:" << endl;
    // a.print();

    // Demo b = a; // copy constructor is called here
    // cout << "Object b:" << endl;
    // b.print();

    // *b.y = 20;
    // cout << "Object a:" << endl;
    // a.print();
    // cout << "Object b:" << endl;
    // b.print();

    // problem caused when shallow copy
    Demo *a = new Demo(1, 2);
    Demo b = *a;
    delete a;
    return 0;
}
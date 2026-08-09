#include <bits/stdc++.h>
using namespace std;
#define long long ll

class abcClass
{
    mutable int x; // using mutable keywork we can change state of this variable in const function, BUT it is bad pracitce so avoid doing this
    int *y;
    int z;

public:
    // constructor
    abcClass()
    {
        this->x = 0;
        y = new int(0);
        z = 0;
    }
    abcClass(int x, int _y, int _z = 0) // default argument
    {
        this->x = x;
        y = new int(_y);
        z = _z;
    }

    int getX() const // now we cant change properties of this class inside this function
    {
        // x = 20; // does not compile
        // after marking x as mutable
        x = 20; // it compiles fine
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

void printABC(const abcClass &a)
{
    // a.setX(3); // using const reference 'a' we can call only const methods
    cout << a.getX() << " " << a.getY() << " " << a.getZ() << endl;
}

int main()
{

    abcClass a(1, 2);

    printABC(a);

    return 0;
}

int main2()
{

    const int x = 10; // x is constant
    // initialization can be done, but we can't re-assign a new value
    // x = 11;

    // outdated method, doesn't work anymore
    // int *p = &x;
    // *p = 11;

    // const with pointers
    // CONST data, NON-CONST pointer
    // const int *a = new int(2);
    // int const *a = new int(2); // uparvali line and aa banne same chhe
    // cout << *a << endl;
    // // *a = 20; // can't change the data where pointer is pointing
    // int b = 20;
    // a = &b; // but content of pointer itself can be change, so we can change our pointer to point other memory location
    // cout << *a << endl;

    // CONST pointer, NON-CONST data
    // int *const a = new int(2);
    // *a = 20;      // compiles fine
    // int b = 20;
    // a = &b;       // does not compiles

    // CONST pointer, CONST data
    // const int* const a = new int(2);
    // *a = 20;       // const data
    // int b = 20;
    // a = &b;         // const pointer

    return 0;
}
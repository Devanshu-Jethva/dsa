#include <bits/stdc++.h>
using namespace std;
#define long long ll

class A
{
public:
    int a;
    A()
    {
        this->a = 1;
    }
};

class B
{
public:
    int a;
    B()
    {
        this->a = 1;
    }
};

class C : public A, public B
{
};

int main()
{

    C *obj1 = new C();
    cout << obj1->A::a << " " << obj1->B::a << endl;

    C obj2;
    cout << obj2.A::a << " " << obj2.B::a << endl;

    return 0;
}
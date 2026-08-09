#include <bits/stdc++.h>
using namespace std;
#define long long ll

// function overloading

class Maths
{
public:
    int sum(int a, int b)
    {
        cout << "fist signature" << endl;
        return a + b;
    }

    int sum(int a, int b, int c)
    {
        cout << "second signature" << endl;
        return a + b + c;
    }

    int sum(int a, float b)
    {
        cout << "third signature" << endl;
        return a + b;
    }
};

int main()
{

    Maths obj;

    cout << obj.sum(2, 5) << endl;
    cout << obj.sum(2, 5, 6) << endl;
    cout << obj.sum(2, 7.6f) << endl;

    return 0;
}
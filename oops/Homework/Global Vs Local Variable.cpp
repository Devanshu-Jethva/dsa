#include <bits/stdc++.h>
using namespace std;

int x = 2; // Global

void fun()
{
    int x = 60;
    cout << x << endl;
    cout << ::x << endl;
}

int main()
{

    int x = 4;
    ::x = 20;

    cout << x << endl;
    cout << ::x << endl;

    {
        int x = 50;
        {
            int x = 404;
            cout << x << endl;
            cout << ::x << endl;
        }
        cout << x << endl;
        cout << ::x << endl;
    }

    fun();

    return 0;
}
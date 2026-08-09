#include <bits/stdc++.h>
using namespace std;
#define long long ll

int main()
{

    int arr[10] = {INT_MIN};

    cout << arr << endl;
    cout << &arr << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << &arr[i] << endl;
    }
    cout << endl
         << endl;

    // p[i] is pointer to first element of array of size 10
    int(*p)[10] = &arr;
    for (int i = 0; i < 10; i++)
    {
        cout << p[i] << endl;
    }

    return 0;
}
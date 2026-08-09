#include <bits/stdc++.h>
using namespace std;

/*
n=4

1
2*3
4*5*6
7*8*9*10
7*8*9*10
4*5*6
2*3
1

*/

int main()
{

    int n;
    cin >> n;

    int c = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << c++;
            if (j < i)
                cout << "*";
        }
        cout << endl;
    }

    int start = c - n;
    for (int i = 0; i < n; i++)
    {
        int k = start;
        for (int j = 0; j < n - i; j++)
        {
            cout << k++;
            if (j < n - i - 1)
                cout << "*";
        }
        start = start - (n - i - 1);
        cout << endl;
    }

    return 0;
}
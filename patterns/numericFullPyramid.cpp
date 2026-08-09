#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            cout << " ";
        }

        int j = i + 1;
        for (int k = 0; k < i + 1; k++)
        {
            cout << j++;
        }

        j--;
        j--;
        for (int k = 0; k < i; k++)
        {
            cout << j--;
        }
        cout << endl;
    }

    return 0;
}
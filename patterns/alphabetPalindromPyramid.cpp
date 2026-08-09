#include <bits/stdc++.h>
using namespace std;
#define long long ll

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < i + 1; j++)
        {
            char ch = 'A' + j;

            cout << ch;
        }
        j--;
        for (j = j - 1; j >= 0; j--)
        {
            char ch = 'A' + j;
            cout << ch;
        }

        cout << endl;
    }
    return 0;
}
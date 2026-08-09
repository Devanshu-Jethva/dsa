#include <bits/stdc++.h>
using namespace std;

int main()
{

    // c = c * (i - j)/j
    // i -> [1,n]
    // j -> [1,i]

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int C = 1;
        for (int j = 1; j <= i; j++)
        {
            cout << C << " ";
            C = C * (i - j) / j;
        }
        cout << endl;
    }

    return 0;
}
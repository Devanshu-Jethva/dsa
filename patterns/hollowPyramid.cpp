#include <bits/stdc++.h>
using namespace std;
#define long long ll

int main()
{
    int n;
    cin >> n;
    int temp = n - 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n * 2 - 1; j++)
        {

            if (j < n - i - 1)
            {
                cout << " ";
            }
            else if (j <= 2 * i + temp)
            {
                if (j == temp || j == 2 * i + temp || i == n - 1)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            else
            {
                cout << " ";
            }
        }
        temp--;
        cout << endl;
    }
    return 0;
}
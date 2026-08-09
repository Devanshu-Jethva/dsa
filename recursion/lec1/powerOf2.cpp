#include <bits/stdc++.h>
using namespace std;
#define long long ll

int power(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return 2 * power(n - 1);
}

int main()
{

    int n;
    cout << "2^n enter n : ";
    cin >> n;

    cout << power(n);

    return 0;
}
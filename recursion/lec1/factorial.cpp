#include <bits/stdc++.h>
using namespace std;
#define long long ll

int fac(int n)
{

    // base case
    if (n == 0)
        return 1;

    // recursive relation or recursive call
    return n * fac(n - 1);
}

int main()
{

    int n;
    cout << "Enter number whose factorial you want to : ";
    cin >> n;

    cout << fac(n);

    return 0;
}
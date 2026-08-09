#include <bits/stdc++.h>
using namespace std;
#define long long ll

int fib(int n)
{
    // B.C.
    if (n == 1 || n == 2)
        return n - 1;
    // R.R.

    return fib(n - 1) + fib(n - 2);
}

int main()
{

    int n;
    cout << "Enter nth term to find in fibonacci series : ";
    cin >> n;

    cout << fib(n);

    return 0;
}
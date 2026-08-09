#include <bits/stdc++.h>
using namespace std;
#define long long ll

void counting(int n)
{
    // base case
    if (n == 0)
    {
        return;
    }
    // processing - reverse counting
    cout << n << " ";
    // recursive relation
    counting(n - 1);
    // processing - forward counting
    // cout << n << " ";
}

int main()
{

    int n;
    cout << "Enter number to print counting : ";
    cin >> n;

    counting(n);

    return 0;
}
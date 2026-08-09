#include <bits/stdc++.h>
using namespace std;

double squareRoot(int n)
{
    int s = 0;
    int e = n / 2;

    int mid = s + (e - s) / 2;

    double ans = 0;
    while (s <= e)
    {
        if (mid * mid == n)
        {
            ans = mid;
        }
        if (mid * mid > n)
        {
            e = mid - 1;
        }
        else
        {
            ans = s;
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}

int main()
{
    int number;
    cout << "enter number : ";
    cin >> number;

    double ans = squareRoot(number);

    int n;
    cout << "enter the number of precision after digit you want : ";
    cin >> n;

    double precision = 0.1;
    for (int i = 0; i < n; i++)
    {
        for (double j = ans; j * j < number; j += precision)
        {
            ans = j;
        }
        precision = precision / 10;
    }

    cout << "sqrt : " << ans;

    return 0;
}
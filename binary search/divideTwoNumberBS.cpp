#include <bits/stdc++.h>
using namespace std;
#define long long ll

double solve(int dividend, int divisor)
{
    int s = 0;
    int e = abs(dividend);
    double ans = 0;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        // perfect solution
        if (abs(mid * divisor) == abs(dividend))
        {
            ans = mid;
            break;
        }

        // non perfect solution
        if (abs(mid * divisor) > abs(dividend))
        {
            // left
            e = mid - 1;
        }
        else
        {
            // right search
            // store ans
            ans = mid;
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }

    int n;
    cout << "Enter the number of precision after digit you want : ";
    cin >> n;

    double precision = 0.1;

    for (int i = 0; i < n; i++)
    {
        for (double j = ans; (j * abs(divisor)) <= abs(dividend); j += precision)
        {
            ans = j;
        }
        precision = precision / 10;
    }

    if ((divisor < 0 && dividend < 0) || (divisor > 0 && dividend > 0))
    {
        return ans;
    }
    else
    {
        return -ans;
    }
}

int main()
{

    // find quotient

    int dividend = 22;
    int divisor = -7;

    double ans = solve(dividend, divisor);
    cout << "Ans is :" << ans << endl;

    return 0;
}
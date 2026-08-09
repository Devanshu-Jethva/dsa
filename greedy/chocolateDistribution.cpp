#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 8;
    int m = 5;
    int a[] = {3, 4, 1, 9, 56, 7, 9, 12};

    sort(a, a + n);

    // check differences in m-size window
    long long i = 0;
    long long j = m - 1;
    long long diff = INT_MAX;

    while (j < n)
    {
        long long newDiff = a[j] - a[i];
        diff = min(diff, newDiff);
        j++;
        i++;
    }

    cout << "ans : " << diff << endl;

    return 0;
}
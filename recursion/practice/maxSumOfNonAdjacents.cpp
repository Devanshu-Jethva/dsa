#include <bits/stdc++.h>
using namespace std;
#define long long ll

void solve(vector<int> arr, int i, int sum, int &maxi)
{
    if (i >= arr.size())
    {
        maxi = max(maxi, sum);
        return;
    }

    solve(arr, i + 1, sum, maxi);
    solve(arr, i + 2, sum + arr[i], maxi);
}

int main()
{
    vector<int> arr{1, 2, 3, 5, 4};

    int sum = 0;
    int maxi = INT_MIN;
    int i = 0;

    solve(arr, i, sum, maxi);

    cout << maxi;

    return 0;
}
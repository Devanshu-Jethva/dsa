// coin change : target -> 0

#include <bits/stdc++.h>
using namespace std;
#define long long ll

int solve(vector<int> &arr, int target)
{
    // base case
    // target j 0 chhe to ene tame kai rite banavso etle return 0
    if (target == 0)
    {
        return 0;
    }
    if (target < 0)
    {
        return INT_MAX;
    }

    // let's solve 1 case
    int mini = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        int ans = solve(arr, target - arr[i]);
        cout << ans << endl;
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
        cout << mini << endl;
    }

    return mini;
}

int main()
{
    // arr[i] > 0 - arr[i] = coins
    vector<int> arr{2};
    int target = 3;
    int ans = solve(arr, target);
    if (ans == INT_MAX)
        ans = -1;
    cout << "ans : " << ans << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& coins, int i, int target, vector<int>& dp) {
    if (target == 0) {
        return 0;
    }
    if (target < 0) {
        return INT_MAX;
    }
    if (dp[target] != -1) {
        return dp[target];
    }

    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++) {
        int future = solve(coins, i, target - coins[i], dp);
        if (future != INT_MAX) {
            mini = min(mini, future + 1);
        }
    }
    return dp[target] = mini;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> dp(x + 1, -1);
    int ans = solve(coins, 0, x, dp);
    cout << (ans != INT_MAX ? ans : -1) << endl;

    return 0;
}
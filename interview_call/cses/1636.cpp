#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int solveRE(vector<int>& coins, int target, int i) {
    if (i == coins.size()) {
        return 0;
    }
    if (target == 0) {
        return 1;
    }
    if (coins[i] > target) {
        return solveRE(coins, target, i + 1);
    }
    return solveRE(coins, target - coins[i], i) + solveRE(coins, target, i + 1);
}

int solveMem(vector<int>& coins, int target, int i, vector<vector<int>>& dp) {
    if (i == coins.size()) {
        return 0;
    }
    if (target == 0) {
        return 1;
    }
    if (dp[i][target] != -1) {
        return dp[i][target];
    }
    if (coins[i] > target) {
        return dp[i][target] = solveMem(coins, target, i + 1, dp);
    }
    return dp[i][target] = solveMem(coins, target - coins[i], i, dp) +
                           solveMem(coins, target, i + 1, dp);
}

int solveTab(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int target = 1; target <= amount; target++) {
            if (coins[i] > target) {
                dp[i][target] = dp[i + 1][target];
            } else {
                dp[i][target] =
                    (dp[i][target - coins[i]] + dp[i + 1][target]) % MOD;
            }
        }
    }
    return dp[0][amount];
}
int solveTabSO(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<int> curr(amount + 1, 0);
    vector<int> next(amount + 1, 0);
    curr[0] = 1;
    next[0] = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int target = 1; target <= amount; target++) {
            if (coins[i] > target) {
                curr[target] = next[target];
            } else {
                curr[target] = (curr[target - coins[i]] + next[target]) % MOD;
            }
        }
        next = curr;
    }
    return curr[amount];
}
int solveTabSO2(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<int> curr(amount + 1, 0);
    vector<int> next(amount + 1, 0);
    curr[0] = 1;
    next[0] = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int target = 1; target <= amount; target++) {
            if (coins[i] > target) {
                curr[target] = next[target];
            } else {
                curr[target] = (curr[target - coins[i]] + next[target]) % MOD;
            }
        }
        next = curr;
    }
    return curr[amount];
}

int change(int amount, vector<int>& coins) {
    // int ans = solveRE(coins, amount, 0);

    // vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
    // int ans = solveMem(coins, amount, 0, dp);

    // int ans = solveTab(amount, coins);

    int ans = solveTabSO(amount, coins);

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << change(x, nums);

    return 0;
}
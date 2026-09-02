#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int dp[1000001];

int combinationSum(int target, vector<int>& nums) {
    if (target == 0) {
        return 1;
    }

    if (target < 0) {
        return 0;
    }

    if (dp[target] != -1) {
        return dp[target];
    }

    int ans = 0;

    for (int& it : nums) {
        ans = (0ll + ans + combinationSum(target - it, nums)) % MOD;
    }

    return dp[target] = ans;
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

    memset(dp, -1, sizeof(dp));

    cout << combinationSum(x, nums);

    return 0;
}
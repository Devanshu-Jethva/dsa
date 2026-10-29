#include <bits/stdc++.h>
using namespace std;

long long dp[5001][5001];

long long solve(vector<int>& nums, int i, int j) {
    if (i > j) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    long long left = nums[i] - solve(nums, i + 1, j);
    long long right = nums[j] - solve(nums, i, j - 1);

    return dp[i][j] = max(left, right);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);
    long long total = 0;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        total += nums[i];
    }

    memset(dp, -1, sizeof(dp));

    long long diff = solve(nums, 0, n - 1);
    long long ans = (total + diff) / 2;

    cout << ans << endl;

    return 0;
}
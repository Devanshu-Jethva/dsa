#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long>& nums, int i, long long sum1,
                long long sum2) {
    if (i == nums.size()) {
        return abs(sum1 - sum2);
    }

    return min(solve(nums, i + 1, sum1, sum2 + nums[i]),
               solve(nums, i + 1, sum1 + nums[i], sum2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << solve(nums, 0, 0, 0) << '\n';

    return 0;
}
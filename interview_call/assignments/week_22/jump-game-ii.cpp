#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int solveRE(vector<int>& nums, int index) {
        if (index >= nums.size() - 1) {
            return 0;
        }

        int mini = INT_MAX;
        for (int i = 1; i <= nums[index]; i++) {
            // +1 -> added jump to reach index + i
            int ans = solveRE(nums, index + i);
            if (ans != INT_MAX) {
                mini = min(mini, ans + 1);
            }
        }
        return mini;
    }

    int solveMem(vector<int>& nums, int index, vector<int>& dp) {
        if (index >= nums.size() - 1) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }

        int mini = INT_MAX;
        for (int i = 1; i <= nums[index]; i++) {
            // +1 -> added jump to reach (index + i)
            int ans = solveMem(nums, index + i, dp);
            if (ans != INT_MAX) {
                mini = min(mini, ans + 1);
            }
        }
        return dp[index] = mini;
    }

    int solveTab(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);

        dp[n - 1] = 0;

        for (int index = n - 2; index >= 0; index--) {
            int mini = INT_MAX;
            for (int i = 1; i <= nums[index]; i++) {
                // +1 -> added jump to reach (index + i)
                int ans = INT_MAX;
                if (index + i < n) {
                    ans = dp[index + i];
                }
                if (ans != INT_MAX) {
                    mini = min(mini, ans + 1);
                }
            }
            dp[index] = mini;
        }
        return dp[0];
    }

    int solve(vector<int>& nums) {
        int currentreach = 0;
        int currentMax = 0;
        int jump = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (i + nums[i] > currentMax) {
                currentMax = i + nums[i];
            }

            if (i == currentreach) {
                jump++;
                currentreach = currentMax;
            }
        }

        return jump;
    }

    int jump(vector<int>& nums) {
        // int ans = solveRE(nums, 0);

        // vector<int> dp(nums.size(), -1);
        // int ans = solveMem(nums, 0, dp);

        // int ans = solveTab(nums);

        int ans = solve(nums);

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
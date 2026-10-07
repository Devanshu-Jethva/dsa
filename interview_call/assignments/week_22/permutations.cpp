#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solveRE(vector<int>& nums, int i, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(nums);
        }

        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);

            solveRE(nums, i + 1, ans);

            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solveRE(nums, 0, ans);
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
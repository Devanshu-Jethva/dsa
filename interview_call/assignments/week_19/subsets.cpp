#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve(vector<int>& nums, int i, vector<int>& current,
               vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(current);
            return;
        }

        // exclude
        solve(nums, i + 1, current, ans);

        // include
        current.push_back(nums[i]);
        solve(nums, i + 1, current, ans);
        current.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        solve(nums, 0, current, ans);
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void combinationSum_helper(vector<int>& candidates, int target,
                               vector<vector<int>>& ans, vector<int>& currComb,
                               int i) {
        if (target == 0) {
            ans.push_back(currComb);
            return;
        }
        if (target < 0 || i == candidates.size()) {
            return;
        }

        currComb.push_back(candidates[i]);
        combinationSum_helper(candidates, target - candidates[i], ans, currComb,
                              i);
        currComb.pop_back();

        combinationSum_helper(candidates, target, ans, currComb, i + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currComb;

        combinationSum_helper(candidates, target, ans, currComb, 0);
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
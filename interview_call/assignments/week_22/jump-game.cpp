#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool greedy(vector<int>& nums) {
        int n = nums.size();
        int reachable = 0;

        for (int i = 0; i < n; i++) {
            if (i > reachable) return false;
            reachable = max(reachable, i + nums[i]);
        }
        return true;
    }

    bool canJump(vector<int>& nums) {
        bool ans = greedy(nums);

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        // observation:
        // 1. all positive
        // 2. even -ve
        // 3. odd -ve
        // 4. nums has zeros

        int currMax = 1;
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            currMax = currMax * nums[i];
            maxi = max(maxi, currMax);
            if (currMax == 0) {
                currMax = 1;
            }
        }
        currMax = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            currMax = currMax * nums[i];
            maxi = max(maxi, currMax);
            if (currMax == 0) {
                currMax = 1;
            }
        }
        return maxi;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
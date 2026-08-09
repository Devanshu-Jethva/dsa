#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        int mid = s + (e - s) / 2;

        int ans = INT_MAX;
        while (s <= e) {
            // checking on which part we are standing right now
            // if on the left part then update ans and elemenate the left half
            if (nums[s] <= nums[mid]) {
                ans = min(ans, nums[s]);
                s = mid + 1;
            }
            // else right part is sorted then update ans and elemenate the right
            // half
            else {
                ans = min(ans, nums[mid]);
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
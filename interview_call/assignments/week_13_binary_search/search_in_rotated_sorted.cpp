#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            // first check on which sorted part we are standing currently
            // if nums[low] <= nums[mid] -> we are at left sorted part
            if (nums[low] <= nums[mid]) {
                // now check which part to elemenate
                // if target is in this left sorted part then elemenate right
                // part
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                }
                // else elemenate left part
                else {
                    low = mid + 1;
                }
            }
            // else we are at right sorted part
            else {
                // now check which part to elemenate
                // if target is in this right sorted part then elemenate left
                // part
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                }
                // else elemenate right part
                else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        // int ans = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     int sum = nums[i];
        //     if (sum == k) ans++;
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         sum += nums[j];
        //         if (sum == k) ans++;
        //     }
        // }
        // return ans;

        // intuition is that we are doing reverse engineering
        // if prefixSum - k is present in map
        // so subarray with sum k can be found

        // good testcase for below approach:
        // nums = [1,2,3,-3,1,1,1,4,2,-3]
        // k = 3

        // let say at last index
        // prefixSum = 9 and (prefixSum - k) = 6
        // and map has entry like {6,2} and others
        // which signifis that at last index we get 2 subarrays whose sum is 3

        // [  6  ][      3       ]
        // [      6      ][   3  ]
        // [1,2,3,-3,1,1,1,4,2,-3]

        // so basically two subarrays are there having sum 3 but we found it
        // with help of prefix sum {6,2} it's reverse engineering

        int prefixSum = 0;
        int count = 0;

        unordered_map<int, int> mp;  // [prefixSum, count]

        mp[0]++;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            if (mp.find(prefixSum - k) != mp.end()) {
                count += mp[prefixSum - k];
            }

            mp[prefixSum]++;
        }
        return count;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
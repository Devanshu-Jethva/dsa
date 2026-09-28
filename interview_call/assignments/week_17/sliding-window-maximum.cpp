#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // this is same pattern as "First negative integer in every window of
        // size k" pattern we used in this question

        deque<int> dq;
        // we will store indexes in deque
        // so we can check by out of window element
        vector<int> ans;

        // process first k size window
        for (int i = 0; i < k; i++) {
            // remove smaller element than current element from back
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // insert element
            dq.push_back(i);
        }

        // ans store karlo for first window
        ans.push_back(nums[dq.front()]);

        // remaining window
        for (int i = k; i < nums.size(); i++) {
            // remove out of window element
            if (!dq.empty() && i - k >= dq.front()) {
                dq.pop_front();
            }

            // addition
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // insert element
            dq.push_back(i);

            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
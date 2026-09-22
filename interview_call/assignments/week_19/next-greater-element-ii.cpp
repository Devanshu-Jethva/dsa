#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int i = 2 * n;
        stack<int> st;
        while (i--) {
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }
            if (i < n) {
                ans[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i % n]);
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
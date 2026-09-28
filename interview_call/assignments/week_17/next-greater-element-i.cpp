#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int, int> nextGreaterElementHelper(vector<int>& arr, int n) {
        stack<int> st;
        unordered_map<int, int> ans;
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                ans[arr[i]] = -1;
            } else {
                while (!st.empty() && st.top() <= arr[i]) {
                    st.pop();
                }
                if (!st.empty()) {
                    ans[arr[i]] = st.top();
                } else {
                    ans[arr[i]] = -1;
                }
            }
            st.push(arr[i]);
        }
        return ans;
    }

   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreaterNums2 =
            nextGreaterElementHelper(nums2, nums2.size());

        vector<int> ans;
        for (int i : nums1) {
            ans.push_back(nextGreaterNums2[i]);
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
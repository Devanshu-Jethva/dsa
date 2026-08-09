
#include <bits/stdc++.h>
using namespace std;
// User function Template for C++

class Solution {
   public:
    vector<int> segTree;

    int buildTree(int nums[], int i, int l, int r) {
        if (l == r) {
            segTree[i] = nums[l];
            return segTree[i];
        }
        int mid = (l + r) / 2;
        int leftSum = buildTree(nums, 2 * i + 1, l, mid);
        int rightSum = buildTree(nums, 2 * i + 2, mid + 1, r);
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
        return segTree[i];
    }

    int query(int start, int end, int i, int l, int r) {
        // no overlap
        if (r < start || end < l) {
            return 0;
        }
        // complete overlap
        if (start <= l && r <= end) {
            return segTree[i];
        }
        // partial overlap
        int mid = (l + r) / 2;
        int leftSum = query(start, end, 2 * i + 1, l, mid);
        int rightSum = query(start, end, 2 * i + 2, mid + 1, r);
        return leftSum + rightSum;
    }

    vector<int> querySum(int n, int arr[], int q, int queries[]) {
        segTree.resize(4 * n);
        buildTree(arr, 0, 0, n - 1);

        vector<int> ans(q);
        for (int i = 0; i < q; i++) {
            int l = queries[2 * i];
            int r = queries[2 * i + 1];

            ans[i] = query(l - 1, r - 1, 0, 0, n - 1);
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
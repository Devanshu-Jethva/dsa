#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Returns a vector<int> of size 2 where:
    // [0] = minimum value in arr from index L to R (inclusive),
    // [1] = maximum value in arr from index L to R (inclusive).
    // Uses the prebuilt segTree where each node stores [min, max].
    // Segment tree indexing:
    // - For a node at idx, left child is at 2*idx + 1, right child at 2*idx
    // + 2.
    vector<int> query(vector<int>& arr, vector<vector<int>>& st, int start,
                      int end, int i, int l, int r) {
        // no overlap
        if (r < start || end < l) {
            return {INT_MAX, INT_MIN};
        }

        // full overlap
        if (start <= l && r <= end) {
            return st[i];
        }

        int mid = (l + r) / 2;
        vector<int> left = query(arr, st, start, end, 2 * i + 1, l, mid);
        vector<int> right = query(arr, st, start, end, 2 * i + 2, mid + 1, r);

        return {min(left[0], right[0]), max(left[1], right[1])};
    }

    vector<int> getMinMax(vector<int>& arr, int L, int R,
                          vector<vector<int>>& segTree) {
        return query(arr, segTree, L, R, 0, 0, arr.size() - 1);
    }

    // Updates the value at arr[index] to 'value' and updates the segTree
    // accordingly. Uses the prebuilt segTree where each node stores [min, max].
    // Segment tree indexing:
    // - For a node at idx, left child is at 2*idx + 1, right child at 2*idx
    // + 2.
    void update(int index, int value, vector<vector<int>>& st, int i, int l,
                int r) {
        if (l == r) {
            st[i] = {value, value};
            return;
        }
        int mid = (l + r) / 2;
        int leftIdx = 2 * i + 1;
        int rightIdx = 2 * i + 2;

        if (index <= mid) {
            update(index, value, st, leftIdx, l, mid);
        } else {
            update(index, value, st, rightIdx, mid + 1, r);
        }
        st[i] = {min(st[leftIdx][0], st[rightIdx][0]),
                 max(st[leftIdx][1], st[rightIdx][1])};
    }

    void updateValue(vector<int>& arr, int index, int value,
                     vector<vector<int>>& segTree) {
        update(index, value, segTree, 0, 0, arr.size() - 1);
        arr[index] = value;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
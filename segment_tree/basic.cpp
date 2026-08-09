#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
   public:
    vector<int> segTree;

    SegmentTree(int n) {
        // why 4 * n?
        // https://www.youtube.com/watch?v=3Iq5x56g_dM
        segTree.resize(4 * n);
    }

    // l and r => represent the range of the current segment
    int buildTree(vector<int>& arr, int i, int l, int r) {
        if (l == r) {
            segTree[i] = arr[l];
            return segTree[i];
        }
        int mid = (l + r) / 2;
        int leftSum = buildTree(arr, 2 * i + 1, l, mid);
        int rightSum = buildTree(arr, 2 * i + 2, mid + 1, r);

        segTree[i] = leftSum + rightSum;
        return segTree[i];
    }

    void updateTree(int idx, int val, int i, int l, int r) {
        if (l == r) {
            segTree[i] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) {
            updateTree(idx, val, 2 * i + 1, l, mid);
        } else {
            updateTree(idx, val, 2 * i + 2, mid + 1, r);
        }
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    // start and end => represent the query range
    // l and r => represent the range of the current segment
    int query(int start, int end, int i, int l, int r) {
        // No overlap
        if (start > r || end < l) {
            return 0;
        }
        // Complete overlap
        if (start <= l && end >= r) {
            // range of segment is completely inside the query range
            return segTree[i];
        }
        // Partial overlap
        int mid = (l + r) / 2;
        int leftSum = query(start, end, 2 * i + 1, l, mid);
        int rightSum = query(start, end, 2 * i + 2, mid + 1, r);
        return leftSum + rightSum;
    }

    void rangeUpdate(int start, int end, int val, int i, int l, int r) {
        vector<int> lazy(segTree.size(), 0);
        rangeUpdateHelper(start, end, val, i, l, r, lazy);
    }

    void rangeUpdateHelper(int start, int end, int val, int i, int l, int r,
                           vector<int>& lazy) {
        // If there are pending updates on this node, apply them
        if (lazy[i] != 0) {
            segTree[i] += (r - l + 1) * lazy[i];
            // If not a leaf node, propagate the update to children
            if (l != r) {
                lazy[2 * i + 1] += lazy[i];
                lazy[2 * i + 2] += lazy[i];
            }
            lazy[i] = 0;  // Clear the lazy value for the current node
        }

        // No overlap
        if (start > r || end < l) {
            return;
        }
        // Complete overlap
        if (start <= l && end >= r) {
            segTree[i] += (r - l + 1) * val;
            // If not a leaf node, propagate the update to children
            if (l != r) {
                lazy[2 * i + 1] += val;
                lazy[2 * i + 2] += val;
            }
            return;
        }

        // Partial overlap
        int mid = (l + r) / 2;
        rangeUpdateHelper(start, end, val, 2 * i + 1, l, mid, lazy);
        rangeUpdateHelper(start, end, val, 2 * i + 2, mid + 1, r, lazy);
        // Update current node after children updates
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();
    SegmentTree st(n);
    st.buildTree(arr, 0, 0, n - 1);

    cout << st.query(0, 3, 0, 0, n - 1) << "\n";  // Output: 10

    st.rangeUpdate(2, 4, 10, 0, 0, n - 1);
    return 0;
}
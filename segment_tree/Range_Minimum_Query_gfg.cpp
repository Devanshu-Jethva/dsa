#include <bits/stdc++.h>
using namespace std;

/* The functions which
builds the segment tree */

void buildTree(int* segTree, int arr[], int i, int l, int r) {
    if (l == r) {
        segTree[i] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    buildTree(segTree, arr, 2 * i + 1, l, mid);
    buildTree(segTree, arr, 2 * i + 2, mid + 1, r);

    segTree[i] = min(segTree[2 * i + 1], segTree[2 * i + 2]);
}

int* constructST(int arr[], int n) {
    int* segTree = new int[4 * n];

    buildTree(segTree, arr, 0, 0, n - 1);

    return segTree;
}

/* The functions returns the
 min element in the range
 from a and b */
int query(int st[], int start, int end, int i, int l, int r) {
    // no overlap
    if (r < start || end < l) {
        return INT_MAX;
    }
    // complete overlap
    if (start <= l && r <= end) {
        return st[i];
    }

    int mid = (l + r) / 2;
    int left = query(st, start, end, 2 * i + 1, l, mid);
    int right = query(st, start, end, 2 * i + 2, mid + 1, r);
    return min(left, right);
}

int RMQ(int st[], int n, int a, int b) { return query(st, a, b, 0, 0, n - 1); }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
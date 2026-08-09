#include <bits/stdc++.h>
using namespace std;

// Range Addition (Problem 370 - Premium)
// This is a premium-locked problem on LeetCode.
// Problem Statement: You are given an integer length and an array updates where
// updates[i] = [startIndex, endIndex, inc]. Initially, you have an array arr of
// length length filled with 0s. For each update, you should add inc to each
// element of arr in the range startIndex to endIndex (inclusive). Return the
// final arr after all updates have been applied.

// Example:
// length = 5, updates = [[1, 3, 2], [2, 4, 3], [0, 2, -2]]
// Output: [-2, 0, 3, 5, 3]

vector<int> rangeAddition(vector<int>& arr, vector<vector<int>>& queries) {
    int n = arr.size();
    for (auto it : queries) {
        int start = it[0];
        int end = it[1];
        int val = it[2];

        arr[start] += val;
        if (end + 1 < n) {
            arr[end + 1] -= val;
        }
    }

    for (int i = 1; i < n; i++) {
        arr[i] += arr[i - 1];
    }
    return arr;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int length = 5;

    vector<vector<int>> updates = {{1, 3, 2}, {2, 4, 3}, {0, 2, -2}};
    vector<int> arr(length, 0);
    vector<int> result = rangeAddition(arr, updates);

    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}
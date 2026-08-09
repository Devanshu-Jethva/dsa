#include <bits/stdc++.h>
using namespace std;

// Count number of pairs having sum <= target
int countPairs(vector<int>& arr, int target) {
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n - 1; i++) {
        // First element greater than (target - arr[i])
        int idx = upper_bound(arr.begin() + i + 1, arr.end(), target - arr[i]) -
                  arr.begin();

        // Elements from (i+1) to (idx-1) are valid
        count += idx - (i + 1);
    }

    return count;
}

// Returns kth smallest pair sum
int kthSmallestPairSum(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());

    int n = arr.size();

    int low = arr[0] + arr[1];
    int high = arr[n - 2] + arr[n - 1];

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (countPairs(arr, mid) >= k)
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

int main() {
    vector<int> arr = {1, 5, 6, 3, 2, 2, 4, 9};
    int k = 5;

    cout << kthSmallestPairSum(arr, k);

    return 0;
}
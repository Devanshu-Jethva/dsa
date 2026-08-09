#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& arr, long long maxSum, int k) {
    int subarrays = 1;
    long long currSum = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        if (currSum + arr[i] > maxSum) {
            currSum = 0;
            subarrays++;
            if (subarrays > k) {
                return false;
            }
        }
        currSum += arr[i];
    }
    return subarrays <= k;
}

long long solve(vector<int>& arr, int n, int k) {
    long long total = accumulate(arr.begin(), arr.end(), 0ll);
    long long s = *max_element(arr.begin(), arr.end());
    long long e = total;
    long long ans = -1;

    while (s <= e) {
        long long mid = s + (e - s) / 2;

        if (isPossible(arr, mid, k)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long ans = solve(arr, n, k);
    cout << ans << endl;

    return 0;
}
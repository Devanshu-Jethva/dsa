#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& arr, long long time, long long productsToMake) {
    long long totalProducts = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        totalProducts += time / arr[i];
        if (totalProducts >= productsToMake) {
            return true;
        }
    }
    return false;
}

long long solve(vector<int>& arr, int n, long long productsToMake) {
    long long s = 1;
    long long e = *max_element(arr.begin(), arr.end()) * productsToMake;
    long long ans = -1;

    while (s <= e) {
        long long mid = s + (e - s) / 2;

        if (isPossible(arr, mid, productsToMake)) {
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

    int n;
    long long productsToMake;
    cin >> n >> productsToMake;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long ans = solve(arr, n, productsToMake);
    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    long long sum = 0;
    long long mx = 0;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        sum += x;
        mx = max(mx, x);
    }

    cout << max(sum, 2 * mx) << endl;

    return 0;
}
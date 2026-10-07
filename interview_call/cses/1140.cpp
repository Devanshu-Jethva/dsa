
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n;
    cin >> n;

    vector<array<ll, 3>> projects(n);

    for (int i = 0; i < n; i++) {
        cin >> projects[i][0] >> projects[i][1] >> projects[i][2];
    }

    // Sort by ending day
    sort(projects.begin(), projects.end(),
         [](auto& a, auto& b) { return a[1] < b[1]; });

    vector<ll> ends(n);
    for (int i = 0; i < n; i++) {
        ends[i] = projects[i][1];
    }

    vector<ll> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        ll start = projects[i - 1][0];
        ll reward = projects[i - 1][2];

        // Number of previous projects ending before start
        int j = lower_bound(ends.begin(), ends.begin() + (i - 1), start) -
                ends.begin();

        // Skip or take the current project
        dp[i] = max(dp[i - 1], reward + dp[j]);
    }

    cout << dp[n] << '\n';

    return 0;
}

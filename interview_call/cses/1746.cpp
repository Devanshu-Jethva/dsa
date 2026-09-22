#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll iterativeSolution(int n, int m, vector<int>& arr) {
    vector<vector<ll>> dp(n, vector<ll>(m + 1, 0));

    // Initialize first element
    if (arr[0] == 0) {
        for (int i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }

    } else {
        dp[0][arr[0]] = 1;
    }

    // Fill DP table
    for (int i = 1; i < n; i++) {
        if (arr[i] != 0) {
            int value = arr[i];

            dp[i][value] += dp[i - 1][value];
            dp[i][value] %= MOD;

            if (value - 1 >= 1) {
                dp[i][value] += dp[i - 1][value - 1];
                dp[i][value] %= MOD;
            }

            if (value + 1 <= m) {
                dp[i][value] += dp[i - 1][value + 1];
                dp[i][value] %= MOD;
            }

        } else {
            for (int j = 1; j <= m; j++) {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= MOD;

                if (j - 1 >= 1) {
                    dp[i][j] += dp[i - 1][j - 1];
                    dp[i][j] %= MOD;
                }

                if (j + 1 <= m) {
                    dp[i][j] += dp[i - 1][j + 1];
                    dp[i][j] %= MOD;
                }
            }
        }
    }

    // Calculate answer
    ll ans = 0;

    for (int i = 1; i <= m; i++) {
        ans += dp[n - 1][i];
        ans %= MOD;
    }

    return ans;
}

ll solve(int i, int value, int n, int m, vector<int>& arr,
         vector<vector<ll>>& dp) {
    // Value must be within [1, m]
    if (value < 1 || value > m) {
        return 0;
    }

    // Current position has a fixed value
    if (arr[i] != 0 && arr[i] != value) {
        return 0;
    }

    // Last position
    if (i == n - 1) {
        return 1;
    }

    // Already calculated
    if (dp[i][value] != -1) {
        return dp[i][value];
    }

    ll ans = 0;

    // Next value = same
    ans += solve(i + 1, value, n, m, arr, dp);

    // Next value = value - 1
    ans += solve(i + 1, value - 1, n, m, arr, dp);

    // Next value = value + 1
    ans += solve(i + 1, value + 1, n, m, arr, dp);

    return dp[i][value] = ans % MOD;
}

ll recursiveSolution(int n, int m, vector<int>& arr) {
    vector<vector<ll>> dp(n, vector<ll>(m + 1, -1));

    ll ans = 0;

    // First element is unknown
    if (arr[0] == 0) {
        for (int value = 1; value <= m; value++) {
            ans += solve(0, value, n, m, arr, dp);
            ans %= MOD;
        }
    } else {  // First element is fixed
        ans = solve(0, arr[0], n, m, arr, dp);
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // ll iterativeAns = iterativeSolution(n, m, arr);

    ll recursiveAns = recursiveSolution(n, m, arr);

    // cout << iterativeAns << '\n';

    cout << recursiveAns << '\n';

    return 0;
}
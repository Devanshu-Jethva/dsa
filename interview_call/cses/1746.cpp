#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(m + 1, 0));

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

    long long ans = 0;

    for (int i = 1; i <= m; i++) {
        ans += dp[n - 1][i];
        ans %= MOD;
    }

    cout << ans << '\n';

    return 0;
}
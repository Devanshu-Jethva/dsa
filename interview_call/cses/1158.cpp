#include <bits/stdc++.h>
using namespace std;

int bookShop(int n, int x, vector<int>& price, vector<int>& pages, int i) {
    if (i >= n) {
        return 0;
    }
    int include = INT_MIN;
    int exclude = bookShop(n, x, price, pages, i + 1);
    if (price[i] < x) {
        include = pages[i] + bookShop(n, x - price[i], price, pages, i + 1);
    }
    return max(exclude, include);
}

int solveTab(int n, int x, vector<int>& price, vector<int>& pages) {
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int target = 0; target <= x; target++) {
            int include = INT_MIN;
            int exclude = dp[i + 1][target];
            if (price[i] <= target) {
                include = pages[i] + dp[i + 1][target - price[i]];
            }
            dp[i][target] = max(include, exclude);
        }
    }
    return dp[0][x];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> price(n);
    vector<int> pages(n);

    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    // cout << bookShop(n, x, price, pages, 0);
    cout << solveTab(n, x, price, pages);

    return 0;
}
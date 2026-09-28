#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int RESolve(int n) {
        if (n == 0 || n == 1) return n;
        // R.R.
        int ans = RESolve(n - 1) + RESolve(n - 1);
        return ans;
    }

    // Recursion + Memoisation
    int topDownSolve(int n, vector<int>& dp) {
        // base case
        if (n == 0 || n == 1) {
            return n;
        }
        // step 3 : check if ans already exists
        if (dp[n] != -1) {
            return dp[n];
        }
        // step 2 : replace ans with dp[n]
        dp[n] = topDownSolve(n - 1, dp) + topDownSolve(n - 2, dp);
        return dp[n];
    }

    // tabulation method
    int bottomUpSolve(int n) {
        // step 1 : create dp array
        vector<int> dp(n + 1, -1);
        // step 2 : observe base case in above solution
        dp[0] = 0;
        if (n == 0) {
            return dp[0];
        }
        dp[1] = 1;
        // step 3 : topDown approach me n kese travel kr rha hai
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    int spaceOpSolve(int n) {
        // step 2 : observe base case in above solution
        int prev2 = 0;
        int prev1 = 1;
        if (n == 0 || n == 1) return n;
        int curr;
        for (int i = 2; i <= n; i++) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }

    int fib(int n) {
        // using DP
        // step 1 : create dp array
        // vector<int> dp(n+1, -1);
        // int ans = topDownSolve(n, dp);
        // return ans;

        // return bottomUpSolve(n);

        return spaceOpSolve(n);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
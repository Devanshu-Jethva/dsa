#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    const int MOD = 1e9 + 7;

    int solveRE(vector<vector<int>>& obstacleGrid, int m, int n) {
        if (m < 0 || n < 0) {
            return 0;
        }

        if (m == 0 && n == 0) {
            return 1;
        }

        if (obstacleGrid[m][n] == 1) {
            return 0;
        }

        long long path = 0;

        path += solveRE(obstacleGrid, m - 1, n);
        path %= MOD;

        path += solveRE(obstacleGrid, m, n - 1);
        path %= MOD;

        return path;
    }

    int solveMem(vector<vector<int>>& obstacleGrid, int m, int n,
                 vector<vector<int>>& dp) {
        if (m < 0 || n < 0) {
            return 0;
        }

        if (m == 0 && n == 0) {
            return 1;
        }

        if (obstacleGrid[m][n] == 1) {
            return 0;
        }

        if (dp[m][n] != -1) {
            return dp[m][n];
        }

        long long path = 0;

        path += solveMem(obstacleGrid, m - 1, n, dp);
        path %= MOD;

        path += solveMem(obstacleGrid, m, n - 1, dp);
        path %= MOD;

        return dp[m][n] = path;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // int ans = solveRE(obstacleGrid, m - 1, n - 1);

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = solveMem(obstacleGrid, m - 1, n - 1, dp);

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char ch;
            cin >> ch;

            if (ch == '.') {
                grid[i][j] = 0;
            } else {
                grid[i][j] = 1;
            }
        }
    }

    Solution s;

    cout << s.uniquePathsWithObstacles(grid);

    return 0;
}
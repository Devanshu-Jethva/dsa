#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solveRE(vector<int>& prices, int i, int& maxi, int buy) {
        if (i == prices.size()) {
            return;
        }

        if (prices[i] - buy > maxi) {
            maxi = prices[i] - buy;
        }
        if (prices[i] < buy) {
            buy = prices[i];
        }

        solveRE(prices, i + 1, maxi, buy);
    }

    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int maxProfit = 0;

        for (int& price : prices) {
            maxProfit = max(maxProfit, price - buy);
            buy = min(buy, price);
        }
        return maxProfit;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
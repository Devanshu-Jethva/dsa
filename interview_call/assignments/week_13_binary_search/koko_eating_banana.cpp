#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    bool canEatAllBananasInMidHours(int mid, int h, vector<int>& piles) {
        long long currentHours = 0;
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            currentHours += ceil((double)piles[i] / (double)mid);
        }
        return currentHours <= h;
    }

   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = 0;
        for (int it : piles) {
            maxPile = max(maxPile, it);
        }

        int s = 1;
        int e = maxPile;
        int mid = s + (e - s) / 2;
        int ans = -1;

        while (s <= e) {
            if (canEatAllBananasInMidHours(mid, h, piles)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }

            mid = s + (e - s) / 2;
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
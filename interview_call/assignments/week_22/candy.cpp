#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int candy(vector<int>& ratings) {
        // using slope concept to solve in O(1) space complexity
        int n = ratings.size();
        int sum = 1;
        int i = 1;

        while (i < n) {
            // flat
            if (ratings[i - 1] == ratings[i]) {
                sum += 1;
                i++;
                continue;
            }

            int peak = 1;
            while (i < n && ratings[i - 1] < ratings[i]) {
                peak++;
                sum += peak;
                i++;
            }

            int down = 1;
            while (i < n && ratings[i - 1] > ratings[i]) {
                sum += down;
                down++;
                i++;
            }

            // adding difference to adjust the answer
            if (down > peak) {
                sum += down - peak;
            }
        }
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
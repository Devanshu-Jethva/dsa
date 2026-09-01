#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxArea(vector<int>& height) {
        int mostWater = 0;

        int i = 0;
        int j = height.size() - 1;
        while (i < j) {
            int minHeight = min(height[i], height[j]);
            int water = j - i;
            mostWater = max(mostWater, water * minHeight);
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return mostWater;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
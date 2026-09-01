#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });

        vector<int> previous = intervals[0];
        int n = intervals.size();
        int removed = 0;
        for (int i = 1; i < n; i++) {
            if (previous[1] > intervals[i][0]) {
                removed++;
            } else {
                previous = intervals[i];
            }
        }
        return removed;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
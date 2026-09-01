#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minMeetingRooms(vector<int>& start, vector<int>& end) {
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int i = 0;
        int j = 0;
        int n = start.size();
        int maxOverlap = 0;
        int overlap = 0;

        while (i < n && j < n) {
            if (start[i] < end[j]) {
                overlap++;
                maxOverlap = max(maxOverlap, overlap);
                i++;
            } else {
                overlap--;
                j++;
            }
        }
        return maxOverlap;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
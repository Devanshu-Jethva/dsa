#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        unordered_map<int, int> lastSeen;
        int n = s.size();
        int maxi = 0;

        while (r < n) {
            if (lastSeen.find(s[r]) != lastSeen.end() && lastSeen[s[r]] >= l) {
                l = lastSeen[s[r]] + 1;
            }
            int len = r - l + 1;
            maxi = max(maxi, len);
            lastSeen[s[r]] = r;
            r++;
        }
        return maxi;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
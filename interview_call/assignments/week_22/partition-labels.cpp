#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> lastOccur;
        for (int i = 0; i < s.size(); i++) {
            if (lastOccur.find(s[i]) != lastOccur.end()) {
                lastOccur[s[i]].second = i;
            } else {
                lastOccur[s[i]] = {i, i};
            }
        }

        vector<pair<int, int>> intervals;
        for (auto it : lastOccur) {
            intervals.push_back(it.second);
        }
        sort(intervals.begin(), intervals.end());

        vector<pair<int, int>> merged;
        merged.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].first < merged.back().second) {
                merged.back().second =
                    max(merged.back().second, intervals[i].second);
            } else {
                merged.push_back(intervals[i]);
            }
        }

        vector<int> ans;
        for (auto it : merged) {
            ans.push_back(it.second - it.first + 1);
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
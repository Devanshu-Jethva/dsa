// https://cses.fi/problemset/task/1619
#include <bits/stdc++.h>
using namespace std;

int overlapInt(vector<vector<int>>& arr) {
    int n = arr.size();

    vector<int> start;
    start.reserve(n);

    vector<int> end;
    end.reserve(n);

    for (auto& it : arr) {
        start.push_back(it[0]);
        end.push_back(it[1]);
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int i = 0;
    int j = 0;
    int maxi = 0;
    int overlap = 0;
    while (i < n && j < n) {
        if (start[i] <= end[j]) {
            overlap++;
            maxi = max(maxi, overlap);
            i++;
        } else {
            overlap--;
            j++;
        }
    }
    return maxi;
}

int overlapInt2(vector<vector<int>>& arr) {
    int n = arr.size();

    vector<pair<int, int>> pairs;
    for (auto& it : arr) {
        pairs.push_back({it[0], 1});
        pairs.push_back({it[1], -1});
    }

    sort(pairs.begin(), pairs.end(),
         [](const pair<int, int>& a, const pair<int, int>& b) {
             if (a.first == b.first) {
                 return a.second > b.second;
             }
             return a.first < b.first;
         });

    int maxOverlap = 0;
    int overlap = 0;
    for (auto& it : pairs) {
        overlap += it.second;
        maxOverlap = max(maxOverlap, overlap);
    }
    return maxOverlap;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> intervals(n);

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        intervals[i] = {start, end};
    }

    cout << overlapInt(intervals);

    return 0;
}
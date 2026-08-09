#include <bits/stdc++.h>
using namespace std;

int solve(int x, unordered_map<int, int>& mp, int& maxi, int d) {
    if (x > maxi || x < 0) {
        return 0;
    }
    int ans = mp[x];
    int first = solve(x + d - 1, mp, maxi, d - 1) + mp[x];
    int second = solve(x + d, mp, maxi, d) + mp[x];
    int third = solve(x + d + 1, mp, maxi, d + 1) + mp[x];

    return max({ans, first, second, third});
}
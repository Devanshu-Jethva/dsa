// https :  // leetcode.com/problems/rotate-string/description/
// Given two strings s and goal, return true if and only if s can become goal
// after some number of shifts on s.
// A shift on s consists of moving the leftmost character of s to the rightmost
// position.
// For example, if s = "abcde", then it will be "bcdea" after one shift.

// KMP - Knuth morrise pattern matching algo
#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    vector<int> getLps(string& s) {
        int n = s.length();

        vector<int> lps(n);  // longest prefix-suffix
        lps[0] = 0;
        int len = 0;
        int i = 1;
        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

   public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        s = s + s;

        vector<int> lps = getLps(goal);

        int i = 0;
        int j = 0;
        int n = s.length();
        int m = goal.length();

        while (i < n) {
            if (s[i] == goal[j]) {
                i++;
                j++;
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
            if (j == m) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, goal;
    cin >> s >> goal;

    Solution sol;
    cout << sol.rotateString(s, goal) << endl;

    return 0;
}
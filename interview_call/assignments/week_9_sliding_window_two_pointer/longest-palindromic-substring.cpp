#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int getMaxLengthPalindromeSubString(string s, int& low, int& high) {
        while (low >= 0 && high < s.size() && s[low] == s[high]) {
            low--;
            high++;
        }
        return high - low - 1;
    }

    string longestPalindrome(string s) {
        int maxi = INT_MIN;
        string ans = "";

        for (int i = 0; i < s.length(); i++) {
            int low = i;
            int high = i;
            int length = getMaxLengthPalindromeSubString(s, low, high);
            // cout << length << " ";
            if (length > maxi) {
                maxi = length;
                ans = s.substr(low + 1, high - low - 1);
            }
            low = i;
            high = i + 1;
            length = getMaxLengthPalindromeSubString(s, low, high);
            // cout << length << endl;
            if (length > maxi) {
                maxi = length;
                ans = s.substr(low + 1, high - low - 1);
            }
        }

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
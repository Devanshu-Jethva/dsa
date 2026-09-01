#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void toLowerCase(string& s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] - 'A' + 'a';
            }
        }
    }

    bool isPalindrome(string s) {
        toLowerCase(s);
        int i = 0;
        int j = s.length() - 1;

        while (i < j) {
            bool isLowerCase1 =
                s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9';
            bool isLowerCase2 =
                s[j] >= 'a' && s[j] <= 'z' || s[j] >= '0' && s[j] <= '9';

            if (isLowerCase1 && isLowerCase2) {
                if (s[i] != s[j]) {
                    return false;
                } else {
                    i++, j--;
                }
            } else if (!isLowerCase1) {
                i++;
            } else {
                j--;
            }
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
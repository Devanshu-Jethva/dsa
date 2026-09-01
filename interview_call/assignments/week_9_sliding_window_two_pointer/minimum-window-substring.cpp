#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string minWindow(string s, string p) {
        int len1 = s.length();
        int len2 = p.length();
        int left = 0;
        int ansIndex = -1;
        int ansLen = INT_MAX;

        int freq[256] = {0};

        // to keep track of all character of string p
        for (int i = 0; i < len2; i++) {
            freq[p[i]]++;
        }

        int count = 0;  // number of valid characters
        for (int right = 0; right < len1; right++) {
            // valid character = jo character freq positive hai, mtlb ki woh
            // initially add hua tha
            if (freq[s[right]] > 0) {
                count++;
            }
            freq[s[right]]--;

            while (count == len2) {
                // window is ready
                // minimize the window -> freq decreament, ans update, left aage
                // badhana hai ans update
                int lengthOfWindow = right - left + 1;
                if (lengthOfWindow < ansLen) {
                    ansLen = lengthOfWindow;
                    ansIndex = left;
                }
                freq[s[left]]++;
                if (freq[s[left]] > 0) {
                    count--;
                }
                left++;
            }
        }

        return ansIndex == -1 ? "" : s.substr(ansIndex, ansLen);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
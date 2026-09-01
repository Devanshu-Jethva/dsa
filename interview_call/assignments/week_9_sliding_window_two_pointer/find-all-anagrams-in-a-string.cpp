#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    bool isZero(const array<int, 26>& freq) {
        for (int count : freq) {
            if (count != 0) return false;
        }
        return true;
    }

   public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();

        if (m > n) return {};

        vector<int> result;
        array<int, 26> freq{};  // zero-initialized

        // Build frequency from pattern
        for (char c : p) {
            freq[c - 'a']++;
        }

        // Process first window
        for (int i = 0; i < m; i++) {
            freq[s[i] - 'a']--;
        }

        if (isZero(freq)) {
            result.push_back(0);
        }

        // Slide window
        for (int i = m; i < n; i++) {
            freq[s[i - m] - 'a']++;  // remove left char
            freq[s[i] - 'a']--;      // add new char

            if (isZero(freq)) {
                result.push_back(i - m + 1);
            }
        }

        return result;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
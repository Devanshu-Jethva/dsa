#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string largestNumber(vector<int>& nums) {
        vector<string> snums;
        for (auto val : nums) {
            snums.push_back(to_string(val));
        }

        sort(snums.begin(), snums.end(), [](string& a, string& b) {
            string s1 = a + b;
            string s2 = b + a;
            return s1 > s2;
        });
        if (snums[0] == "0") return "0";

        string ans = "";
        for (auto s : snums) {
            ans += s;
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
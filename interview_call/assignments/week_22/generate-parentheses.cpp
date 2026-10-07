#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solveRE(int open, int close, vector<string>& ans, string& temp) {
        if (open == 0 && close == 0) {
            ans.push_back(temp);
            return;
        }

        if (open > 0) {
            temp.push_back('(');
            solveRE(open - 1, close, ans, temp);
            temp.pop_back();
        }

        if (close > open) {
            temp.push_back(')');
            solveRE(open, close - 1, ans, temp);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        solveRE(n, n, ans, temp);
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
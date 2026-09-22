#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int evalRPN(vector<string>& s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            string ch = s[i];
            if (ch != "+" && ch != "-" && ch != "*" && ch != "/") {
                st.push(stoi(ch));
            } else {
                int secondOperand = st.top();
                st.pop();
                int firstOperand = st.top();
                st.pop();

                int result;
                if (ch == "+") {
                    result = firstOperand + secondOperand;
                } else if (ch == "-") {
                    result = firstOperand - secondOperand;
                } else if (ch == "*") {
                    result = firstOperand * secondOperand;
                } else {
                    result = firstOperand / secondOperand;
                }
                st.push(result);
            }
        }
        return st.top();
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
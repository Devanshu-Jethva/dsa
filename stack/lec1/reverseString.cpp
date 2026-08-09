#include <bits/stdc++.h>
using namespace std;
#define long long ll

int main()
{
    string s = "Devanshu";

    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
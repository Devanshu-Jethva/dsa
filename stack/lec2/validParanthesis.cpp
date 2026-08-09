#include <bits/stdc++.h>
using namespace std;

bool checkIfValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            else
            {
                char topCh = st.top();
                if (topCh == '(' && ch == ')')
                {
                    st.pop();
                }
                else if (topCh == '{' && ch == '}')
                {
                    st.pop();
                }
                else if (topCh == '[' && ch == ']')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }
    if (st.empty())
    {
        return true;
    }
    return false;
}

int main()
{

    string s = "()(){}[]{{[]}}";

    bool ans = checkIfValid(s);

    cout << "is valid : " << ans << endl;

    return 0;
}
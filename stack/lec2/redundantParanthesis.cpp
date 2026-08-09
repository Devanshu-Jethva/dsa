//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int checkRedundancy(string s)
    {
        // code here
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                st.push(ch);
            }
            else if (ch >= 97 && ch <= 122)
            {
                continue;
            }
            else
            {
                // when ch == ')'

                char topCh = st.top();
                if (topCh == '(')
                {
                    return 1;
                }
                while (!st.empty() && topCh != '(')
                {
                    if (topCh == '+' || topCh == '-' ||
                        topCh == '*' || topCh == '/')
                    {
                        st.pop();
                        topCh = st.top();
                    }
                }
                if (st.empty())
                {
                    return 1;
                }
                if (topCh == '(')
                {
                    st.pop();
                }
            }
        }
        if (st.empty())
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    printf("Enter how many test cases you want : ");
    scanf("%d", &t);
    while (t--)
    {

        string s;
        cin >> s;

        Solution obj;
        int res = obj.checkRedundancy(s);

        cout << "contains redundant paranthesis or not? : " << res << endl;
    }
}

// } Driver Code Ends
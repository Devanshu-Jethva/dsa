#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "aabc";
    string ans = "";
    int freq[26] = {0};
    queue<char> q;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        freq[ch - 'a']++;
        q.push(ch);
        while (!q.empty())
        {
            if (freq[q.front() - 'a'] > 1)
            {
                // repeating characters at front of queue
                q.pop();
            }
            else
            {
                // non repeating character
                ans.push_back(q.front());
                break;
            }
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
    }

    cout << ans << endl;

    return 0;
}
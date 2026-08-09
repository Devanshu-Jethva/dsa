#include <bits/stdc++.h>
using namespace std;
#define long long ll

int main()
{
    vector<int> v1{2, 4, 6, 8, 10};
    vector<int> v2{8, 10, 1, 3, 5};

    vector<int> ans;
    for (int i = 0; i < v1.size(); i++)
    {
        ans.push_back(v1[i]);
    }

    for (int i = 0; i < v2.size(); i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            if (v2[i] == ans[j])
            {
                v2[i] = INT_MIN;
            }
        }
        if (v2[i] == INT_MIN)
        {
            continue;
        }
        else
        {
            ans.push_back(v2[i]);
        }
    }

    for (auto val : ans)
    {
        cout << val << " ";
    }

    return 0;
}
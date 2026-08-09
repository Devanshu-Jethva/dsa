#include <bits/stdc++.h>
using namespace std;
#define long long ll

void find(string &s, char &key, int &n, int i, vector<int> &ans)
{
    if (i >= n)
    {
        return;
    }

    if (s[i] == key)
    {
        ans.push_back(i);
    }
    return find(s, key, n, i + 1, ans);
}

int main()
{

    string s = "devanshu jethva";
    int n = s.length();
    char key = 'e';
    int i = 0;
    vector<int> ans;

    // --------------------- important line --------------------------------------
    // jyare bhi koi variable or data structure pass karie k jema mare ans store karavo hoi to ene hu pass by reference karis
    // -----------------------------------------------------------------------------

    find(s, key, n, i, ans);

    for (auto i : ans)
    {
        cout << "found at : " << i << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
#include <cstring>

#include <iostream>
using namespace std;
#define long long ll

void lastOccurLTOR(string &s, char &ch, int i, int &ans)
{
    if (i >= s.length())
    {
        return;
    }

    if (s[i] == ch)
    {
        ans = i;
    }

    lastOccurLTOR(s, ch, i + 1, ans);
}

void lastOccurRTOL(string &s, char &ch, int i, int &ans)
{
    if (i < 0)
    {
        return;
    }

    if (s[i] == ch)
    {
        ans = i;
        return;
    }

    lastOccurRTOL(s, ch, i - 1, ans);
}

int main()
{

    // string str = "gabchdbg";
    // char ch = 'h';
    // int ans = -1;
    // // lastOccurLTOR(str, ch, 0, ans);
    // lastOccurRTOL(str, ch, str.length() - 1, ans);

    // cout << "index of last occurence : " << ans << endl;

    // stl function - strrchr

    char str[] = "This is a string";
    char *ch = strrchr(str, 'i');
    cout << "Index of last occurence of i: "
         << ch - str + 1;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define long long ll

void reverse(string &s, int i, int j)
{

    if (i >= j)
    {
        return;
    }

    swap(s[i], s[j]);

    reverse(s, ++i, --j);
}

int main()
{

    string s = "devanshu";
    int i = 0;
    int j = s.size() - 1;

    reverse(s, i, j);

    cout << s << endl;

    return 0;
}
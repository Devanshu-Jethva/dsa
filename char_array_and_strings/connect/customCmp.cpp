#include <bits/stdc++.h>
using namespace std;

bool cmp(char a, char b)
{
    return a > b;
}

bool compare(int a, int b)
{
    return a > b;
}

int main()
{

    string s = "babbar";
    sort(s.begin(), s.end());
    cout << s << endl;

    vector<int> v{3, 4, 5, 2, 3, 1};
    sort(v.begin(), v.end(), compare);

    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}
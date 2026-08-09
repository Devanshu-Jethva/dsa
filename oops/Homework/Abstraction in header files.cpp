#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {3, 5, 6, 32, 46, 6};
    sort(v.begin(), v.end());
    for (int i : v)
    {
        cout << i << " ";
    }

    return 0;
}
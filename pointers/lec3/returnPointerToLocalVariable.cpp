#include <bits/stdc++.h>
using namespace std;

int *solve()
{
    int a = 5;
    int *ans = &a;
    return ans; // ❌ Returning address of local variable (BAD)
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int *p = solve();
    cout << p << endl;
    cout << *p << endl; // ❌ Might print garbage or crash

    return 0;
}
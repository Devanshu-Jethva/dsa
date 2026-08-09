#include <bits/stdc++.h>
using namespace std;

bool cpmASC(int a, int b)
{
    // jonsa chota hai usko pehle rakhdo
    // comparision a and b vache chhe to
    // true mtlb a ne pehla muki do
    // false mtbl b ne pehla muki do
    if (a < b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool cmpDESC(int a, int b)
{
    // jonsa bada hai usko pehle rakhdo
    // ahiya comparision a and b vache chhe
    // to true mtlb a ko pehle rakhdo
    // and false mtlb b ko pehle rakhdo
    if (a > b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    vector<int> v{3, 4, 5, 2, 3, 1};
    sort(v.begin(), v.end(), cmpDESC);

    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
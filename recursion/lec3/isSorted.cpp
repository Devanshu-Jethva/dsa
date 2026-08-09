#include <bits/stdc++.h>
using namespace std;
#define long long ll

bool checkSorted(vector<int> &v, int &n, int i)
{

    if (i == n - 1)
    {
        return true;
    }

    if (v[i + 1] <= v[i])
    {
        return false;
    }

    checkSorted(v, n, i + 1);
}

int main()
{

    // vector<int> v{1, 1, 1, 1, 1}; // '<=' for this type of case
    vector<int> v{1, 2, 3, 4, 6, 7, 8, 9};
    int n = v.size();

    int i = 0;
    bool isSorted = checkSorted(v, n, i);

    if (isSorted)
    {
        cout << "is sorted";
    }
    else
    {
        cout << "not sorted";
    }
    return 0;
}
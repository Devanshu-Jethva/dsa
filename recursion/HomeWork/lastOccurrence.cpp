#include <bits/stdc++.h>
using namespace std;
#define long long ll

void lastOccurrence(vector<int> arr, int i, int target, int &ans)
{
    // base case
    if (i > arr.size())
    {
        return;
    }

    if (arr[i] == target)
    {
        ans = i;
    }

    return lastOccurrence(arr, i + 1, target, ans);
}

int main()
{

    // vector<int> arr{5, 6, 5, 2, 5, 6, 5};
    vector<int> arr{1, 2, 3, 4, 6, 7, 7, 9};
    int target = 5;
    int i = 0;

    int ans = -1;
    lastOccurrence(arr, i, target, ans);
    cout << "Last occurrence : " << ans << endl;

    return 0;
}
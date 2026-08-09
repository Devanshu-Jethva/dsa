#include <bits/stdc++.h>
using namespace std;
#define long long ll

bool isPossible(int rank[], int n, int mid, int paratha)
{
    int parathaCount = 0;
    int R;
    int chefParathaCount;

    for (int i = 0; i < n; i++)
    {
        R = rank[i];
        int timeTaken = 0;
        chefParathaCount = 1;
        while (timeTaken + (R * chefParathaCount) <= mid)
        {
            timeTaken += R * chefParathaCount;
            parathaCount++;
            chefParathaCount++;
        }
    }
    if (parathaCount >= paratha)
        return true;
    return false;
}

int main()
{

    int p = 10;
    int rank[] = {1, 2, 3, 4};

    int n = sizeof(rank) / sizeof(rank[0]);
    int s = 0;
    int e = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        e = max(e, rank[i] * ((p * (p + 1)) / 2));
    }
    int ans = -1;

    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (isPossible(rank, n, mid, p))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }

    cout << "minimum time required to make " << p
         << " paratha is : " << ans
         << endl;
    return 0;
}
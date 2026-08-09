#include <bits/stdc++.h>
using namespace std;
#define long long ll

bool isPossible(vector<int> arr, int bladeHeight, int requiredWood)
{

    int totalWood = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int temp = arr[i] - bladeHeight;
        if (temp > 0)
        {
            totalWood += temp;
        }
    }
    if (totalWood >= requiredWood)
    {
        return true;
    }
    return false;
}

int maxSawBladeHeight(vector<int> arr, int requiredWood)
{
    int s = 0;
    int e = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        e = max(e, arr[i]);
        // cout << e << endl;
    }
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (isPossible(arr, mid, requiredWood))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{

    int n, requiredWood;
    cout << "Enter number of trees : ";
    cin >> n;
    cout << "Enter required amount of wood : ";
    cin >> requiredWood;
    vector<int> treeHeights;
    cout << "Enter heights of tree : ";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        treeHeights.push_back(a);
    }

    cout << "Height required of machine blade to be set to get " << requiredWood
         << " amount of wood is : " << maxSawBladeHeight(treeHeights, requiredWood)
         << endl;

    return 0;
}
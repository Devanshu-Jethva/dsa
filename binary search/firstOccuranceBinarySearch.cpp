#include <bits/stdc++.h>
using namespace std;
#define long long ll

int firstOccurance(vector<int> arr, int target)
{
    int s = 0;
    int e = arr.size() - 1;
    int index = -1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[mid] == target)
        {
            index = mid;
            e = mid - 1;
        }
        else if (target < arr[mid])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return index;
}

int main()
{

    // vector<int> v{1, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 6, 7};

    vector<int> v{1, 2, 3, 4, 5, 6, 7, 7};

    int indexOfFirstOccurance = firstOccurance(v, 4);
    cout << indexOfFirstOccurance << endl;

    auto lowerBound = upper_bound(v.begin(), v.end(), 4);
    cout << lowerBound - v.begin();

    return 0;
}
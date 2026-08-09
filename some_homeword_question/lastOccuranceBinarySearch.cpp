#include <bits/stdc++.h>
using namespace std;
#define long long ll

int lastOccurance(vector<int> arr, int target)
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
            s = mid + 1;
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

    vector<int> v{1, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 6, 7};

    int indexOfLastOccurance = lastOccurance(v, 4);
    cout << indexOfLastOccurance << endl;

    vector<int>::iterator it;
    it = upper_bound(v.begin(), v.end(), 4);
    cout << it - v.begin();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define long long ll

int indexOfPivot(vector<int> arr)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;

    // while (s <= e)
    while (s < e)
    {
        // if (e == s)
        // {
        //     return mid;
        // }
        // edge cases
        if ((mid + 1) < arr.size() && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        if ((mid - 1) >= 0 && arr[mid - 1] > arr[mid])
        {
            return mid - 1;
        }

        // for left and right
        if (arr[s] > arr[mid])
        {
            e = mid - 1;
        }
        else
        {
            // s = mid + 1;
            s = mid;
        }
        mid = s + (e - s) / 2;
    }
    // return -1;
    return e;
}

int main()
{

    vector<int> nums{5, 6, 7, 1, 2, 3, 4};

    cout << "Index of pivot : " << indexOfPivot(nums);

    return 0;
}
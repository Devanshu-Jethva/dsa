#include <bits/stdc++.h>
using namespace std;

int missingElement(vector<int> arr)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        cout << s << " " << e << endl;
        if (mid - 1 >= 0 && arr[mid] == arr[mid - 1] + 2)
        {
            return mid + 1;
        }
        if (mid + 1 <= e && arr[mid] == arr[mid + 1] - 2)
        {
            return arr[mid] + 1;
        }

        if (mid == arr[mid] - 2)
        {
            e = mid - 1;
        }
        else if (mid == arr[mid] - 1)
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int main()
{
    // 1 <= arr[i] <= n
    // vector<int> arr{1, 2, 3, 4, 6, 7, 8, 9};
    // vector<int> arr{1, 3, 4, 5, 6, 7, 8, 9};
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 9};

    cout << "missing element is : " << missingElement(arr);

    return 0;
}
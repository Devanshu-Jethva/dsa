#include <bits/stdc++.h>
using namespace std;
#define long long ll

int binarySearch(vector<int> &arr, int s, int e, int key)
{
    // base case
    // case 1 -> key not found
    // s > e -> invalid array
    if (s > e)
        return -1;

    int mid = (s + e) / 2;

    // case 2 -> key found
    if (arr[mid] == key)
        return mid;

    // arr[mid] > key - left ma search
    else if (arr[mid] > key)
        binarySearch(arr, s, mid - 1, key);

    // arr[mid] < key - right ma search
    else
        binarySearch(arr, mid + 1, e, key);
}

int main()
{

    vector<int> v{1, 2, 3, 4, 6, 7, 8, 9};
    int n = v.size();

    int i = 0;
    int s = 0;
    int e = n - 1;
    int target = 4;
    int ans = binarySearch(v, s, e, target);

    cout << "target at index : " << ans << endl;

    return 0;
}
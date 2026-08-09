#include <bits/stdc++.h>
using namespace std;
#define long long ll

int partition(vector<int> &arr, int start, int end)
{
    int i = start - 1, j = start;
    // end element as a pivot element
    int pivotIndex = end;
    while (j < pivotIndex)
    {
        if (arr[j] < arr[pivotIndex])
        {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    i++;
    swap(arr[i], arr[pivotIndex]);
    return i;
}

void quickSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;

    int p = partition(arr, start, end);

    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

int main()
{

    vector<int> arr{4, 3, 5, 7, 4, 2, 6, 7};

    quickSort(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define long long ll

int partition(int arr[], int s, int e)
{
    int pivotIndex = s;
    int pivotElement = arr[s];

    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivotElement)
        {
            count++;
        }
    } // now we have correct index for pivot

    int correctIndex = s + count;
    swap(arr[pivotIndex], arr[correctIndex]);
    pivotIndex = correctIndex;

    int i = s;
    int j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= arr[pivotIndex])
            i++;
        while (arr[j] > arr[pivotIndex])
            j--;
        // 2 cases ho sakte hai
        // case 1 : found the element for swap
        // case 2 : no need for any swap
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
            i++, j--;
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
    // base case
    // s == e -> single element
    // s > e -> invalid array
    if (s >= e)
        return;

    // partition logic, returns pivot index
    int p = partition(arr, s, e);

    // recursive call
    // pivot element left
    quickSort(arr, s, p - 1);

    // pivot element right
    quickSort(arr, p + 1, e);
}

int main()
{

    int arr[] = {8, 1, 20, 30, 6, 5, 60, 5};
    // int arr[] = {8, 1, 3, 4, 20, 50, 30};
    int n = 8;

    int s = 0;
    int e = n - 1;
    quickSort(arr, s, e);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
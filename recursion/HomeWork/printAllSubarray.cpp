#include <bits/stdc++.h>
using namespace std;
#define long long ll

void printSubarrays(int arr[], int start, int n, int end)
{
    if (end > n)
    {
        return;
    }

    for (int i = start; i < end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    printSubarrays(arr, start, n, end + 1);
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    for (int start = 0; start < n; start++)
    {
        int end = start;
        printSubarrays(arr, start, n, end);
    }

    return 0;
}
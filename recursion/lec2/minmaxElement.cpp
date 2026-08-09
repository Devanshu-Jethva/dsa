#include <bits/stdc++.h>
using namespace std;
#define long long ll

void maxOfArray(int arr[], int n, int i, int &maxi)
{
    // base case
    if (i >= n)
    {
        // array agar khatam hogya, pura traverse ho gaya to vapas aa jao
        return;
    }
    // 1 case solved kardo
    // check current element
    maxi = max(maxi, arr[i]);

    // baki recursion sambhal lenga
    maxOfArray(arr, n, i + 1, maxi);
}

void minOfArray(int arr[], int n, int i, int &mini)
{
    // base case
    if (i >= n)
    {
        // array agar khatam hogya, pura traverse ho gaya to vapas aa jao
        return;
    }
    // 1 case solved kardo
    // check current element
    mini = min(mini, arr[i]);

    // baki recursion sambhal lenga
    minOfArray(arr, n, i + 1, mini);
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    int maxi = INT_MIN;
    int mini = INT_MAX;
    int i = 0;
    maxOfArray(arr, n, i, maxi);
    minOfArray(arr, n, i, mini);
    cout << "max is : " << maxi << endl;
    cout << "min is : " << mini;

    return 0;
}
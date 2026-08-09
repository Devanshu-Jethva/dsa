#include <bits/stdc++.h>
using namespace std;

int getKthLargestElement(int arr[], int n, int k)
{
    // create min heap of size k
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    // for remaining element, push only if they are greater than top
    for (int i = k; i < n; i++)
    {
        int ele = arr[i];
        if (ele > pq.top())
        {
            pq.pop();
            pq.push(ele);
        }
    }
    int ans = pq.top();
    return ans;
}

int getKthSmallestElement(int arr[], int n, int k)
{

    // create max heap of size k
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    // for remaining element, push only if they are less than top
    for (int i = k; i < n; i++)
    {
        int ele = arr[i];
        if (ele < pq.top())
        {
            pq.pop();
            pq.push(ele);
        }
    }
    int ans = pq.top();
    return ans;
}

int main()
{

    int arr[] = {10, 5, 20, 4, 15};
    int n = 5;
    int k = 2;
    int ans = getKthSmallestElement(arr, n, k);
    cout << "kth smallest element : " << ans << endl;
    ans = getKthLargestElement(arr, n, k);
    cout << "kth greatest element : " << ans << endl;

    return 0;
}
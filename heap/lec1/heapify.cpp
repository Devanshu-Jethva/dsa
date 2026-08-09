#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int index = i;
    int largest = index;
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;

    if (leftIndex <= n && arr[leftIndex] > arr[largest])
    {
        largest = leftIndex;
    }

    if (rightIndex <= n && arr[rightIndex] > arr[largest])
    {
        largest = rightIndex;
    }

    if (largest != index)
    {
        // left ya right child me se koi bada hai currentNode se
        swap(arr[index], arr[largest]);
        index = largest;
        heapify(arr, n, index);
    }
    else
    {
        return;
    }
}

void buildHeap(int arr[], int n)
{
    // (n/2 + 1) se n tak nodes leaf nodes hote hai so unko heapify karne ki jarurat nahi hai so n/2 se start karenge
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
    while (n != 1)
    {
        swap(arr[n--], arr[1]);

        // heapify
        heapify(arr, n, 1);
    }
}

int main()
{
    int arr[] = {-1, 12, 15, 13, 11, 14};
    int n = 5;
    buildHeap(arr, n);

    cout << "Printing the heap" << endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    heapSort(arr, n);

    cout << "Printing sorted heap" << endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
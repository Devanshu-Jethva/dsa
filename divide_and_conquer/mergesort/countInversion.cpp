#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(vector<int> &arr, vector<long long> &temp,
                        long long start, long long mid, long long end) {
        long long i = start;
        long long j = mid + 1;
        long long k = start;

        long long c = 0;
        while (i <= mid && j <= end) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {  // arr[i] > arr[j] // count inversion case
                temp[k++] = arr[j++];
                c += mid - i + 1;
            }
        }

        while (i <= mid) {
            temp[k++] = arr[i++];
        }
        while (j <= end) {
            temp[k++] = arr[j++];
        }

        while (start <= end) {
            arr[start] = temp[start];
            start++;
        }
        return c;
    }

    long long int mergesort(vector<int> &arr, vector<long long> &temp,
                            long long start, long long end) {
        if (start >= end) {
            return 0;
        }

        long long int c = 0;
        long long mid = start + (end - start) / 2;
        c += mergesort(arr, temp, start, mid);
        c += mergesort(arr, temp, mid + 1, end);
        c += merge(arr, temp, start, mid, end);
        return c;
    }

    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        long long int c = 0;
        int n = arr.size();
        vector<long long> temp(n, 0);
        c = mergesort(arr, temp, 0, n - 1);

        return c;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
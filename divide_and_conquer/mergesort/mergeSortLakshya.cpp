#include <bits/stdc++.h>
using namespace std;
#define long long ll

void merge(vector<int> &nums, vector<int> &temp, int start, int mid, int end)
{
    int i = start, j = mid + 1, k = start;
    // cout << "temp array" << endl;
    // for (int i = 0; i < temp.size(); i++)
    // {
    //     cout << temp[i] << " ";
    // }
    // cout << endl;
    // i = start;

    while (i <= mid && j <= end)
    {
        if (nums[i] <= nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }

    while (i <= mid)
    {
        temp[k++] = nums[i++];
    }

    while (j <= end)
    {
        temp[k++] = nums[j++];
    }
    // i = start;

    while (start <= end)
    {
        nums[start] = temp[start];
        start++;
    }

    // cout << "temp array" << endl;

    // for (int i = 0; i < temp.size(); i++)
    // {
    //     cout << temp[i] << " ";
    // }
    // cout << endl;
}

void mergeSort(vector<int> &nums, vector<int> &temp, int start, int end)
{
    // base case
    if (start >= end)
        return;
    int mid = (start + end) >> 1;

    mergeSort(nums, temp, start, mid);
    mergeSort(nums, temp, mid + 1, end);
    merge(nums, temp, start, mid, end);
}

vector<int> sortArray(vector<int> &nums)
{
    vector<int> temp(nums.size(), 0);
    mergeSort(nums, temp, 0, nums.size() - 1);
    return nums;
}

int main()
{
    ios_base::sync_with_stdio(false);

    vector<int> nums{5, 3, 6, 8, 4, 3, 7, 3};
    sortArray(nums);
    cout << "nums array" << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}
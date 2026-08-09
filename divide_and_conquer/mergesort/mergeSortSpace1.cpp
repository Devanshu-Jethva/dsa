#include <bits/stdc++.h>
using namespace std;
#define long long ll

void setPivot(vector<int> &nums, int start, int end)
{
    int pivotIndex = start;
    int pivotElement = nums[start];

    int count = 0;
    // ahiya i<=end karyu bcoz end ne already nums.size()-1 lai lidhu chhe
    for (int i = start + 1; i <= end; i++)
    {
        if (nums[i] < pivotElement)
            count++;
    }

    int correctIndex = start + count;
    int i = start;
    while (i < correctIndex)
    {
        nums[i] = nums[i + 1];
        i++;
    }
    nums[correctIndex] = pivotElement;
}

void merge(vector<int> &nums, int start, int mid, int end)
{
    int i = start, j = mid + 1;

    while (i <= mid)
    {
        if (nums[i] <= nums[j])
        {
            i++;
        }
        else
        {
            swap(nums[i], nums[j]);
            setPivot(nums, j, end);
        }
    }
}

void mergeSort(vector<int> &nums, int start, int end)
{
    // base case
    if (start >= end)
        return;
    int mid = (start + end) >> 1;

    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);
    merge(nums, start, mid, end);
}

void sortArray(vector<int> &nums)
{
    mergeSort(nums, 0, nums.size() - 1);
}

int main()
{

    vector<int> nums{10, 3, 4, 3, 5, 7, 8, 64, 2, 2, 3, 5, 7, 8, 9, 9, 6, 1, 3, 9};
    sortArray(nums);
    cout << "nums array" << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
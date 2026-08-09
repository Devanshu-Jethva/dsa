#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    void swapElementAndPutElementInNums2AtItsRightPosition(vector<int>& nums1,
                                                           vector<int>& nums2,
                                                           int i) {
        swap(nums1[i], nums2[0]);

        int pivotElement = nums2[0];
        int j = 1;
        while (j < nums2.size() && nums2[j] < pivotElement) {
            j++;
        }
        int pivotIndex = j - 1;
        j = 0;
        while (j < nums2.size() && j + 1 < nums2.size() && j <= pivotIndex) {
            nums2[j] = nums2[j + 1];
            j++;
        }
        nums2[pivotIndex] = pivotElement;
    }

   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (nums2.size() == 0) {
            return;
        }

        int i = 0;

        while (i < m) {
            if (nums1[i] <= nums2[0]) {
                i++;
            } else {
                swapElementAndPutElementInNums2AtItsRightPosition(nums1, nums2,
                                                                  i);
                i++;
            }
        }

        int j = 0;
        for (i = m; i < nums1.size(); i++) {
            nums1[i] = nums2[j++];
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
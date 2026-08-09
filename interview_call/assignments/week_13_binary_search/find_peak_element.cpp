#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findPeakElement(vector<int>& arr) {
        int s = 0;
        int e = arr.size() - 1;
        int mid = s + (e - s) / 2;

        while (s < e) {
            if (arr[mid] < arr[mid + 1]) {
                // mid can never be peak element here
                // on ascending line -> right search
                s = mid + 1;
            } else {
                // mid might be peak element here
                // on descending line -> left search
                e = mid;
            }
            mid = s + (e - s) / 2;
        }
        return s;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
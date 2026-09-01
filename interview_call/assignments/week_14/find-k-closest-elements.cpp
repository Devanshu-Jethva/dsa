#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

        if (idx == 0) return vector<int>(arr.begin(), arr.begin() + k);

        if (idx == n) return vector<int>(arr.end() - k, arr.end());

        vector<int> ans;
        int i = idx - 1;
        int j = idx;

        while (k > 0) {
            if (i < 0) {
                ans.insert(ans.end(), arr.begin() + j, arr.begin() + j + k);
                break;
            }

            if (j == n) {
                ans.insert(ans.end(), arr.begin() + (i - k + 1),
                           arr.begin() + (i + 1));
                break;
            }

            if (abs(arr[i] - x) <= abs(arr[j] - x))
                ans.push_back(arr[i--]);
            else
                ans.push_back(arr[j++]);

            k--;
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
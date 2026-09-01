#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};

        for (int i = 0; i < tasks.size(); i++) {
            char ch = tasks[i];
            freq[ch - 'A']++;
        }

        priority_queue<int> maxHeap;

        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                maxHeap.push(freq[i]);
            }
        }

        int time = 0;
        while (!maxHeap.empty()) {
            int idle = n + 1;
            vector<int> remain;

            while (idle && !maxHeap.empty()) {
                int top = maxHeap.top();
                maxHeap.pop();
                if (top > 1) {
                    remain.push_back(top - 1);
                }
                time++;
                idle--;
            }

            for (int count : remain) {
                maxHeap.push(count);
            }
            if (maxHeap.empty()) {
                break;
            }
            time += idle;
        }
        return time;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
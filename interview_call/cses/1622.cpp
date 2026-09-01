#include <bits/stdc++.h>
using namespace std;

vector<string> ans;

void perm(string& s, int idx, int n) {
    if (idx == n) {
        ans.push_back(s);
        return;
    }

    unordered_set<char> used;

    for (int i = idx; i < n; i++) {
        // Already used this character at this position
        if (used.count(s[i])) {
            continue;
        }

        used.insert(s[i]);
        swap(s[i], s[idx]);
        perm(s, idx + 1, n);
        swap(s[i], s[idx]);
    }
}

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    perm(s, 0, s.length());
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";

    for (string p : ans) {
        cout << p << "\n";
    }
}
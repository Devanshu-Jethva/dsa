#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> pos(n + 1);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pos[x] = i + 1;
    }
    // a = [4, 2, 1, 5, 3]

    // pos[1] = 3
    // pos[2] = 2
    // pos[3] = 5
    // pos[4] = 1
    // pos[5] = 4

    // To collect 1 → 2 → 3 → 4 → 5, you can collect consecutive numbers in
    // the same round if their positions are increasing.
    // - 1 at position 3
    // - 2 at position 2 → position decreased → new round
    // - 3 at position 5 → increasing → same round
    // - 4 at position 1 → decreased → new round
    // - 5 at position 4 → increasing → same round

    int rounds = 1;

    for (int i = 2; i <= n; i++) {
        if (pos[i] < pos[i - 1]) {
            rounds++;
        }
    }

    cout << rounds << endl;

    return 0;
}
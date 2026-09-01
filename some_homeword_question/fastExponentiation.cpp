#include <bits/stdc++.h>
using namespace std;
#define long long ll

int fastExponentiation(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) {
            // odd
            ans = ans * a;
        }
        a = a * a;
        b = b >> 1;  // b = b/2 => O(log b)
    }
    return ans;
}  // O(log b)

int fastExp(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    int future = fastExp(base, exponent / 2);
    if (exponent & 1) {
        return base * future * future;
    } else {
        return future * future;
    }
}
int MOD = 1e9 + 7;

int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    int half = power(base, exponent / 2);

    int result = (1ll * half * half) % MOD;
    if (exponent & 1) {
        result = (1ll * result * base) % MOD;
    }
    return result;
}

int main() {
    // cout << fastExponentiation(2, 5);

    cout << fastExp(2, 10);

    return 0;
}
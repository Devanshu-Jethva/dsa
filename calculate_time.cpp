#include <bits/stdc++.h>

#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    auto start = high_resolution_clock::now();
    // your code here
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Execution Time: " << duration.count() << " ms" << endl;

    return 0;
}
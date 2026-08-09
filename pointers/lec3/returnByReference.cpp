#include <bits/stdc++.h>
using namespace std;

// 1. Returning a Reference to a Local Variable (🚨 Dangerous)
// int &getNumber()
// {
//     int x = 10; // Local variable
//     return x;   // ❌ BAD! x will be destroyed after the function ends
// }

// int main()
// {
//     int &ref = getNumber(); // ❌ ref now refers to a destroyed variable
//     cout << ref << endl;    // ❌ Undefined behavior
//     return 0;
// }

// ----------------------------------------------------------------------------------------

// 2. Returning a Reference to a Static Variable (✅ Safe)
// int& getStaticNumber() {
//     static int x = 10;  // Static variable (lives for the entire program)
//     return x;
// }

// int main() {
//     int &ref = getStaticNumber();
//     cout << ref << endl;  // ✅ Safe, prints 10
//     ref = 20;             // ✅ Modifies x in getStaticNumber()
//     cout << getStaticNumber() << endl;  // ✅ Prints 20
//     return 0;
// }

// ----------------------------------------------------------------------------------------

// 3. Returning a Reference to a Function Parameter ✅ Safe
// int& findMax(int &a, int &b) {
//     return (a > b) ? a : b;
// }

// int main() {
//     int x = 5, y = 10;
//     int &maxRef = findMax(x, y);  // maxRef refers to y
//     cout << maxRef << endl;  // Prints 10
//     maxRef = 100;  // Changes y
//     cout << y << endl;  // Prints 100
//     return 0;
// }

// ----------------------------------------------------------------------------------------

// 4. Returning a Reference from a Class Member ✅ Safe
// class Counter {
//     int value;
// public:
//     Counter(int v) : value(v) {}

//     int& getValue() {  // Returns a reference to `value`
//         return value;
//     }
// };

// int main() {
//     Counter c(10);
//     int &ref = c.getValue();
//     ref = 20;  // Modifies `value` inside `c`
//     cout << c.getValue() << endl;  // Prints 20
//     return 0;
// }

// ----------------------------------------------------------------------------------------

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
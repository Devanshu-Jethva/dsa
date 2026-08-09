#include <bits/stdc++.h>
using namespace std;
#define long long ll

void printDigit(int n)
{
    if (n == 0)
    {
        return;
    }
    printDigit(n / 10);
    cout << n % 10 << " ";
}

int main()
{

    int n = 0b101; // binary
    // n = 0B1111;    // binary
    // n = 0X101;     // hexadecimal
    // n = 0x101;     // hexadecimal
    // n = 101;       // decimal
    // n = 0101;      // octal
    cout << "enter number : ";
    // cin >> n;

    printDigit(n);

    return 0;
}
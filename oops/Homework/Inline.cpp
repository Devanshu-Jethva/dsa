#include <bits/stdc++.h>
using namespace std;

inline void print(int n)
{
    // inline function tyare use karvama aave chhe jyare line of code in the function bv j ocha hoi
    // like bs 1-2 line no j hoi

    cout << "in print function : " << n << endl;
}

int main()
{

    // normal case ma compile time e aa print() no call jay ne ek stack ma entry thay etle stack ma 2 entry hase
    // 1 -> main() ni
    // 2 -> print() ni

    // but aam function ne inline banavathi aa print() ni alag entry nai bane and actually function no code print() call thi replace thai jse

    print(2);
    print(2);
    print(2);
    print(2);
    print(2);
    print(2);
    print(2);
    print(2);
    print(2);
    print(2);

    return 0;
}
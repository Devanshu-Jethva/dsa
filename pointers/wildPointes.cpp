#include <iostream>
using namespace std;

int main()
{

    // uninitialized pointer
    int *ptr;
    cout << *ptr << endl;

    // deleting pointer
    int *p = new int;
    delete p;
    cout << *p << endl;

    // pointer to non-existing variable
    int *ptr2 = &x;
    cout << *ptr2 << endl;

    return 0;
}
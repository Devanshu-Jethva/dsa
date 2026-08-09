#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int(*p)[5] = &arr; // Pointer to an array of 5 integers

    cout << "*p: " << *p << endl
         << endl; // Address of first element of arr

    // Using (*p)[i]
    cout << "Using (*p)[i]:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << (*p)[i] << " ";
    }
    cout << endl
         << endl;
    // (*p) gives arr, so (*p)[i] is same as arr[i]

    // Using arr[i]
    cout << "Using arr[i]:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << endl;
    // Accessing elements normally using arr[i]

    // Using i[arr] (same as arr[i])
    cout << "Using i[arr]:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i[arr] << " ";
    }
    cout << endl
         << endl;
    // i[arr] is equivalent to arr[i] because arr[i] is actually *(arr + i)

    // Using pointer arithmetic *(arr + i)
    cout << "Using *(arr + i):" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl
         << endl;
    // arr is a pointer to the first element, so *(arr + i) gives arr[i]

    // Using *p[i] (Incorrect and Undefined Behavior if i > 0)
    cout << "Using *p[i]:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << *p[i] << " "; // Undefined behavior for i > 0
    }
    cout << endl;
    /*
        *p[i] means *(p + i), where p is int (*)[5] (a pointer to an array of 5 ints).
        - p[i] moves i * (size of array) ahead, which is invalid for i > 0.
        - *p[0] is valid and equivalent to *arr (arr[0]), which prints 10.
        - *p[1] accesses out-of-bounds memory (undefined behavior).
    */
    return 0;
}
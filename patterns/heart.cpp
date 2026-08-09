#include <iostream>
using namespace std;

int main()
{
    // heart star pattern
    int size;
    cin >> size; // 6

    for (int i = size / 2; i < size; i += 2) // 3 5
    {
        // print first spaces
        for (int j = 1; j < size - i; j += 2) // 1
        {
            cout << " ";
        }
        // print first stars
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        // print second spaces
        for (int j = 0; j < size - i; j++)
        {
            cout << " ";
        }
        // print second stars
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    // lower part
    // inverted pyramid
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * size - 2 * i - 1; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}
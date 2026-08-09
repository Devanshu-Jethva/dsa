// missing elements from an array with duplicate
// size of array is n
// 1 <= arr[i] <= n - array ma element 1 to n sudhima hase including 1 and n
// catch - catch e chhe k array ma element 1 to n ma hase for example given array        [1, 2, 2, 4] or [1,3,4,2,2] or [1,3,5,3,4] or [5,3,3,3,1] or [4,3,3,1] aavu kaik hoi sake k jya element missing hase and ena replace bijo kok element repeat thato hase but but but element 1 thi n sudhima hase aavu lakhyu hoi tyare apde array na elements ne as index treat kari sakie chhie
// so array na elements ne aapde as a index treat karisu and 2 intutions nikli sakse
// 1. negative marking - hu darek elements ne as a index treat karis and e index par jaine e value negative mark karis ane jo array ma je positive value hase e values evi hase ke jya apde pochi j nai sakya eno mtlb k aapde positive element ni index + 1 karsu e aapda missing elements hase
// 2. positioning method - darek element ne eni index par pochadi devanu means 1 ne 1 par, 2 ne 2 par, ... and so on and have jo array na element != index + 1 to e element missing elements chhe

#include <bits/stdc++.h>
using namespace std;
#define long long ll

void marking(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int index = abs(arr[i]) - 1;
        if (arr[index] > 0)
        {
            arr[index] *= -1;
        }
    }

    // e bada mark thai gaya hse k je element and emni index same hoi em gothvi sakisu
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i[arr] << " ";
    // }

    // bachelo positive ans hase
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            cout << i + 1 << " ";
        }
    }
}

void swapingSorting(int arr[], int n)
{
    int i = 0;
    while (i < n)
    {
        int index = arr[i] - 1;
        if (arr[i] != arr[index])
        {
            swap(arr[i], arr[index]);
        }
        else
        {
            i++;
        }
    }

    // have bada mate ele = index - 1 hase
    // but jeni mate nai hoi e missing element kevay
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            cout << i + 1 << " ";
        }
    }
}

int main()
{

    // int arr[] = {1, 3, 4, 2, 2};
    int arr[] = {1, 3, 2, 2, 2};
    // int arr[] = {1, 2, 2, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    // marking(arr, n);

    swapingSorting(arr, n);

    return 0;
}
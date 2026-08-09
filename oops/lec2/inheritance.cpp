#include <bits/stdc++.h>
using namespace std;
#define long long ll

class Animal
{
private:
    int no;

public:
    int age;
    int weight;

    void eat()
    {
        cout << "Eating" << endl;
    }
};

// class b
// {
// };
// class Dog : public Animal, public b
// {
// };

int main()
{

    // Dog d1;
    // d1.eat();

    Animal *a = new Animal();
    cout << a->no << endl;

    return 0;
}
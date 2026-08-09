#include <bits/stdc++.h>
using namespace std;
#define long long ll

class Animal
{
private:
    int age;
    int weight;

public:
    void eat()
    {
        cout << "Eating" << endl;
    }
    int getAge()
    {
        return this->age;
    }
    void setAge(int age)
    {
        this->age = age;
    }
};

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define long long ll

class Animal
{
private:
    int weight;

public:
    // state or properties
    int age;
    string type;

    // Default Constructor
    Animal()
    {
        cout << "Constructor called" << endl;
        this->weight = 0;
        this->age = 0;
        this->type = "";
    }

    // Parameterised Constructor
    Animal(int age)
    {
        this->age = age;
        cout << "Parameterised Constructor called " << endl;
    }

    Animal(int age, int weight)
    {
        this->age = age;
        this->weight = weight;
        cout << "Parameterised Constructor 2 called " << endl;
    }

    Animal(int age, int weight, string type)
    {
        this->age = age;
        this->weight = weight;
        this->type = type;
        cout << "Parameterised Constructor 3 called " << endl;
    }

    // copy constructor
    Animal(Animal &obj)
    {
        this->age = obj.age;
        this->type = obj.type;
        this->weight = obj.weight;
        cout << "Copy Constructor called " << endl;
    }

    // behaviour
    // --> cpp -> function
    // --> java -> methods
    void eat()
    {
        cout << "Eating" << endl;
    }

    void sleep()
    {
        cout << "Sleeping" << endl;
    }
    void setWeight(int weight)
    {
        // this is pointer to the current object - ek pointer chhe pointer etle member access karva arrow(->) sathe use karyu
        this->weight = weight;

        // or
        // (*this).weight = weight;
    }
    int getWeight()
    {
        return weight;
    }

    // Destructor
    ~Animal()
    {
        cout << "Destructor called" << endl;
    }
};

int main()
{

    // cout << "size of empty class : " << sizeof(Animal) << endl;

    // Object creation

    // Static memory allocation
    // Animal ramesh;

    // ramesh.age = 12;
    // ramesh.type = "lion";
    // cout << "Age of ramesh is : " << ramesh.age << endl;
    // cout << "type of ramesh is : " << ramesh.type << endl;

    // ramesh.eat();
    // ramesh.sleep();

    // // for private members
    // ramesh.setWeight(100);
    // cout << "Weight of ramesh is : " << ramesh.getWeight() << endl;

    // Dynamic memory allocation
    // Animal *suresh = new Animal;

    // (*suresh).age = 15;
    // (*suresh).type = "Cat";

    // // alternate - dynamic
    // suresh->age = 17;
    // suresh->type = "Dog";

    // suresh->eat();
    // suresh->sleep();

    // object copy

    Animal *a = new Animal(18, 70, "Devanshu");
    Animal b = *a;
    Animal c(*a);

    Animal d(10);
    Animal e(d);
    Animal f = d;

    // deep copy Vs shallow copy - pending

    // destructor

    // in case of dynamic memory allocatin destructor callled automatically
    // cout << "a obj creation" << endl;
    // Animal a;

    // in case of dynamic memory allocatin destructor callled manually
    // cout << "b obj creation" << endl;
    // Animal *b = new Animal();
    // delete b;

    return 0;
}
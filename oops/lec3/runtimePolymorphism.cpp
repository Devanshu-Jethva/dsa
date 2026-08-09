#include <bits/stdc++.h>
using namespace std;
#define long long ll

class Animal
{
public:
    Animal()
    {
        cout << "Animal constructor" << endl;
    }
    virtual void speak()
    {
        cout << "Speaking" << endl;
    }
};

class Dog : public Animal
{
public:
    Dog()
    {
        cout << "Dog constructor" << endl;
    }
    // override
    void speak()
    {
        cout << "bhau bhau" << endl;
    }
};

int main()
{

    // Animal *a = new Animal();
    // a->speak();

    // Dog d;
    // d.speak();

    // following upcasting and downcasting are examples of runtime polymorphism

    // UpCasting
    // Animal *a = new Dog();
    // a->speak();

    // DownCasting
    // Dog *d = (Dog *)new Animal();
    // d->speak();

    // by default (downcasting karo k upcasting) virtual keyword lagaya vagar jo function call karie to pointer no function call thay

    // jo parent class na function k je child ma override thaya chhe tya virtual keyword lagayi didhu to hve behaviour change thai jse and je type no object banayo eno function call thse

    // for constructor

    // Animal *a = new Animal();

    // Animal *a = new Dog();

    // Dog *d = new Dog();

    Dog *d = (Dog *)new Animal();

    return 0;
}
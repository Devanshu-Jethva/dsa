#if !defined(BIRD_H)
#define BIRD_H
#include <iostream>

class Bird
{
public:
    virtual void eat() = 0;
    virtual void fly() = 0;
};

class Sparrow : public Bird
{
public:
    void eat()
    {
        std::cout << "Sparrow is eating\n";
    }
    void fly()
    {
        std::cout << "Sparrow is flying\n";
    }
};
class Eagle : public Bird
{
public:
    void eat()
    {
        std::cout << "Eagle is eating\n";
    }
    void fly()
    {
        std::cout << "Eagle is flying\n";
    }
};

#endif // BIRD_H

#if !defined(BIRD_H)
#define BIRD_H
#include <iostream>

class Bird
{
    // by containing only virtual method this class has become interface just like java in which first concrete class inheriting this interface have to provide this method body
    // so by doing that we are making sure that if xyz entity is bird than it must have behaviour of eating and flying
    // this are also called as pure virtual functions
public:
    virtual void eat() = 0;
    virtual void fly() = 0;
};

class sparrow : public Bird
{
private:
    void eat()
    {
        std::cout << "Sparrow is eating \n";
    }
    void fly()
    {
        std::cout << "Sparrow is flying \n";
    }
};

class eagle : public Bird
{
private:
    void eat()
    {
        std::cout << "eagle is eating \n";
    }
    void fly()
    {
        std::cout << "eagle is flying \n";
    }
};

#endif // BIRD_H

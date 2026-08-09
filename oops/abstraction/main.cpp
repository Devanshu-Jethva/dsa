#include <iostream>
#include "bird.h"
using namespace std;

void birddoessomething(Bird *bird)
{
    bird->eat();
    bird->fly();

    bird->eat();
    bird->fly();

    bird->eat();
    bird->fly();
}

int main()
{
    Bird *sp = new sparrow();
    birddoessomething(sp);

    // sparrow *sp = new sparrow();
    // sparrow->eat();

    Bird *eagl = new eagle();
    birddoessomething(eagl);

    return 0;
}
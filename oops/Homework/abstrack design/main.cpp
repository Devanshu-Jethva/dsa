#include <bits/stdc++.h>
#include "bird.h"
using namespace std;

void birdActivities(Bird *&b)
{
    b->eat();
    b->fly();
}

int main()
{

    Bird *b = new Sparrow();
    birdActivities(b);

    return 0;
}
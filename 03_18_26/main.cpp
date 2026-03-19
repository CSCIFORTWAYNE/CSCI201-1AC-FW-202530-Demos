#include <iostream>
#include <cstdlib>
#include "clock.h"

void clockTick(int &h, int &m, int &s);
Clock makeClock();

int main()
{
    Clock c(6, 9, 0);
    Clock d(12);
    d = c;
    Clock clocks[100];

    // c.clockTick();
    int hr = 23;
    int min = 59;
    int sec = 59;
    c.getTime(hr, min, sec);
    // clockTick(hr, min, sec);
    std::cout << c.printTime() << std::endl;
    if (c.equalTime(d))
    {
        std::cout << "The clocks are the same" << std::endl;
    }
    for (int i = 0; i < 100; i++)
    {
        clocks[i] = makeClock();
        std::cout << clocks[i].printTime() << std::endl;
    }
    return 0;
}

void clockTick(int &h, int &m, int &s)
{
    s++;
    if (s == 60)
    {
        s = 0;
        m++;
        if (m == 60)
        {
            m = 0;
            h++;
            if (h == 24)
            {
                h = 0;
            }
        }
    }
}

Clock makeClock()
{
    static int numClocks = 0;
    int hr = rand() % 24;
    int min = rand() % 60;
    int sec = rand() % 60;
    Clock returnClock(hr, min, sec);
    numClocks++;
    return returnClock;
}

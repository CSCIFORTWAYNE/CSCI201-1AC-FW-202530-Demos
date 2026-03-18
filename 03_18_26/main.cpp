#include <iostream>
#include "clock.h"

void clockTick(int &h, int &m, int &s);

int main()
{
    Clock c(6, 9, 0);

    // c.clockTick();
    int hr = 23;
    int min = 59;
    int sec = 59;
    c.getTime(hr, min, sec);
    // clockTick(hr, min, sec);
    std::cout << c.printTime() << std::endl;
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

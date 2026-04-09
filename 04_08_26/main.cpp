#include "twentyFourHrClock.h"
#include "twelveHrClock.h"
#include <iostream>

// M04 part b add >, >=, <, <= to the TwentyFourHrClock class. Submit your changed class and functions.

int main()
{
    int x;
    int y = 6;
    int z = 10;
    x = 4 + (z++ + ++y); // what is x, what is y, what is z

    TwentyFourHrClock clock;
    std::cout << clock << std::endl;
    clock = clock + 10;
    std::cout << clock << std::endl;
    clock = 10 + clock;
    std::cout << clock << std::endl;
    TwelveHrClock clock12;
    clock12++;
    if (clock12 == clock)
    {
        std::cout << "The clocks have the same time" << std::endl;
    }
    x = x;
    return 0;
}
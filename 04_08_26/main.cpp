#include "twentyFourHrClock.h"
#include "twelveHrClock.h"
#include <iostream>

int main()
{
    int x;
    int y = 6;
    int z = 10;
    x = 4 + (z + y);
    TwentyFourHrClock clock;
    std::cout << clock << std::endl;
    clock = clock + 10;
    std::cout << clock << std::endl;
    clock = 10 + clock;
    std::cout << clock << std::endl;
    TwelveHrClock clock12;
    if (clock == clock12)
    {
        std::cout << "The clocks have the same time" << std::endl;
    }
    return 0;
}
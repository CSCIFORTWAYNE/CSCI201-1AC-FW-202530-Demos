#include <iostream>
#include <cstdlib>
#include <limits>
#include "clock.h"

void resetStream();

int main()
{
    int *p = nullptr;
    int q = 7;
    std::cout << &q << std::endl;
    p = &q;
    std::cout << p << std::endl;
    std::cout << &p << std::endl;
    std::cout << *p << std::endl;
    int h = rand() % 24;
    int m = rand() % 60;
    int s = rand() % 60;
    Clock c(h, m, s);
    Clock *clockPtr;
    std::cout << "Enter 12 or 24: ";
    std::cin >> h;
    while (!std::cin || (h != 12 && h != 24))
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "Please enter 12 or 24: ";
        std::cin >> h;
    }
    if (h == 12)
    {
        // Clock twelve(rand() % 12 + 1, rand()%60, rand()%60, Clock::TWELVE);
        clockPtr = new Clock(rand() % 12 + 1, rand() % 60, rand() % 60, Clock::TWELVE);
    }
    else
    {
        clockPtr = new Clock(rand() % 24, rand() % 60, rand() % 60);
    }
    // twelve.clockTick();
    //
    std::cout << clockPtr->printTime() << std::endl;
    (*clockPtr)
        .clockTick();
    clockPtr->clockTick();
    clockPtr->clockTick();
    std::cout << clockPtr->printTime() << std::endl;
    Clock clocks[10];
    std::cout << "How many clocks? ";
    std::cin >> m;
    while (!std::cin || m < 1)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "How many clocks? ";
        std::cin >> m;
    }
    Clock *moreClocks = new Clock[m];
    std::cout << moreClocks[m - 1].printTime() << std::endl;
    moreClocks = new Clock;

    return 0;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

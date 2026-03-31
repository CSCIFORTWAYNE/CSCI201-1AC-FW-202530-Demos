#include <iostream>
#include <cstdlib>
#include <limits>
#include "clock.h"

void resetStream();
// lecture activity M03-A what code is needed to stop the memory leak caused by doubleArray on line 84
// explain the difference between line 38 and line 65 and line 70
Clock **makeClocks(int numClocks);
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
    // Clock clocks[10];
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

    Clock **moreClocks = new Clock *[m];
    for (int i = 0; i < m; i++)
    {
        if (rand() % 2)
        {
            moreClocks[i] = new Clock(rand() % 12 + 1, rand() % 60, rand() % 60, Clock::TWENTYFOUR, rand() % 2 ? Clock::AM : Clock::PM); // if rand()%2 then am else pm
        }
        else
        {
            moreClocks[i] = new Clock(rand() % 24, rand() % 60, rand() % 60);
        }
    }
    std::cout << (*moreClocks[m - 1]).printTime() << std::endl;
    delete clockPtr;
    clockPtr = nullptr;
    // if(clockPtr == nullptr)
    for (int i = 0; i < m; i++)
    {
        delete moreClocks[i];
    }
    delete[] moreClocks;
    moreClocks = nullptr;
    // moreClocks = new Clock;
    // delete moreClocks;
    int **doubleArray;
    doubleArray = new int *[3];
    for (int i = 0; i < 3; i++)
    {
        doubleArray[i] = new int[5];
        for (int j = 0; j < 5; j++)
        {
            doubleArray[i][j] = rand() % 100 + 1;
        }
    }
    moreClocks = nullptr;
    moreClocks = makeClocks(1000);
    for (int i = 0; i < 1000; i++)
    {
        delete moreClocks[i];
        moreClocks[i] = nullptr;
    }
    delete[] moreClocks;

    return 0;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Clock **makeClocks(int numClocks)
{
    Clock **clocks = new Clock *[numClocks];
    for (int i = 0; i < numClocks; i++)
    {
        clocks[i] = new Clock(0, 0, 0);
    }
    return clocks;
}

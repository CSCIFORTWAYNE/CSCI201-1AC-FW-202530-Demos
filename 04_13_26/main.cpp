#include <iostream>
#include <random>
#include "drink.h"
#include "twelveHrClock.h"
#include "twentyFourHrClock.h"

int max(int, int);
double max(double, double);
char max(char, char);

template <class t>
t maxTemplate(t, t);

int main()
{
    int x = 8;
    int y = 4;
    std::cout << max(x, y) << std::endl;
    std::cout << maxTemplate(x, y) << std::endl;

    drink d1(COFFEE, drink::HOT, sizeType::LARGE, "Milk", "Chocolate");
    drink d2(COFFEE, drink::ICE, sizeType::LARGE, "Milk", "Chocolate");
    std::cout << d1 << std::endl;
    std::cout << d2 << std::endl;
    std::cout << maxTemplate(d1, d2).toString() << std::endl;

    std::default_random_engine generator(time(0)); // seed is added as part of the constructor
    std::uniform_int_distribution<int> twelveHrDist(1, 12);
    std::uniform_int_distribution<int> twentyFourHrDist(0, 23);
    std::uniform_int_distribution<int> minSecDist(0, 59);
    std::uniform_int_distribution<int> partDistribution(0, 1);
    TwelveHrClock randomClock(twelveHrDist(generator), minSecDist(generator), minSecDist(generator), partDistribution(generator) ? TwelveHrClock::AM : TwelveHrClock::PM);

    std::cout << randomClock << std::endl;

    return 0;
}

int max(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

char max(char a, char b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

double max(double a, double b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

template <class t>
t maxTemplate(t a, t b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

#include <iostream>
#include "drink.h"

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

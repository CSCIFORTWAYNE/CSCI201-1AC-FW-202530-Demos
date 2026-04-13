#include <iostream>

int max(int, int);
double max(double, double);
char max(char, char);

int main()
{
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
#include <iostream>
#include <limits>
#include "person.h"
#include "employee.h"
#include "clock.h"
#include "twentyFourHrClock.h"
#include "twelveHrClock.h"

// M04 A lab Fill in the input.txt file with your own test run. You should have at least 10 clocks.
// random number generators are your friend
// add a loop to the main to print time on all of the clocks in the array
void printPerson(Person &p);
Clock *makeClock();

int getInt(std::string prompt, std::string error, bool (*valid)(int, int, int), int low = 0, int high = 0);
bool isIntInRange(int num, int low, int high);
bool isIntGT0(int num, int = 0, int = 0);
void resetStream();
bool isAorB(int num, int a, int b);
int inputClockType();
TwelveHrClock::PartOfDayType inputPartOfDay();

int main()
{
    Employee emp("Harry Potter", 13, "555-1212", "hpotter@email.com", 23000.21, "2021-12-12");
    printPerson(emp);
    std::cout << emp.toString() << std::endl;
    Clock **c;
    int numClocks = getInt("How many clocks? ", "That is an invalid number of clocks. Please enter a number greater than 0.", isIntGT0);
    c = new Clock *[numClocks];
    for (int i = 0; i < numClocks; i++)
    {
        c[i] = makeClock();
    }

    return 0;
}

void printPerson(Person &p)
{
    std::cout << p.toString() << std::endl;
}

Clock *makeClock()
{

    Clock *clockptr = nullptr;
    int type = inputClockType();
    std::string hourPrompt = "Enter the clock's hour: ";
    int hour;
    int min;
    if (type == 12)
    {
        hour = getInt(hourPrompt, "The hour must be between 1 and 12. ", isIntInRange, 1, 12);
    }
    else
    {
        hour = getInt(hourPrompt, "The hour must be between 0 and 23. ", isIntInRange, 0, 23);
    }
    min = getInt("Enter the clock's minutes: ", "The minutes must be between 0 and 59.", isIntInRange, 0, 59);
    TwelveHrClock::PartOfDayType part = TwelveHrClock::PM;
    if (type == 12)
    {
        part = inputPartOfDay();
        clockptr = new TwelveHrClock(hour, min, 0, part);
    }
    else
    {
        clockptr = new TwentyFourHrClock(hour, min, 0);
    }
    return clockptr;
}
int getInt(std::string prompt, std::string error, bool (*valid)(int, int, int), int low, int high)
{
    int num;
    std::cout << prompt;
    std::cin >> num;
    std::cout << std::endl;
    while (!std::cin || !valid(num, low, high)) //* !std::cin checks for input failure
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << error << std::endl;
        std::cout << prompt;
        std::cin >> num;
        std::cout << std::endl;
    }
    return num;
}

bool isIntInRange(int num, int low, int high)
{
    return num >= low && num <= high;
}

bool isIntGT0(int num, int, int)
{
    return num > 0;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int inputClockType()
{

    int timeInt = getInt("Is the clock 12 hour or 24 hour? ", "Please enter 12 or 24.", isAorB, 12, 24);

    return timeInt;
}

bool isAorB(int num, int a, int b)
{
    return num == a || num == b;
}

TwelveHrClock::PartOfDayType inputPartOfDay()
{
    int partInt = -1;
    std::string prompt = "Is it \n1. AM\n2. PM\n";
    partInt = getInt(prompt, "Please enter 1 or 2.", isAorB, 1, 2);
    return TwelveHrClock::parts[partInt - 1];
}
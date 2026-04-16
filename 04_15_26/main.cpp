#include <vector>
#include <random>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <stdexcept>
#include "twelveHrClock.h"
#include "twentyFourHrClock.h"

int getInt(std::string prompt, std::string error, bool (*valid)(int, int, int), int low = 0, int high = 0);
bool isIntInRange(int num, int low, int high);
bool isIntGTX(int num, int x = 0, int = 0);
void resetStream();
bool isAorB(int num, int a, int b);
TwelveHrClock::PartOfDayType inputPartOfDay();
int inputClockType();
Clock *makeClock();

int main()
{
    std::vector<int> nums;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution distribution(1, 100);
    int numberOfNums;
    numberOfNums = distribution(generator);
    for (int i = 0; i < numberOfNums; i++)
    {
        nums.push_back(distribution(generator));
    }
    int userIndex = getInt("Enter an index for the vector: ", "Please enter a number greater than or equal to 0. ", isIntGTX, -1);
    try
    {
        std::cout << nums.at(userIndex) << std::endl;
    }
    catch (std::out_of_range e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::setw(userIndex) << std::setfill('!') << "!" << std::endl;
    try
    {
        Clock *myClock = makeClock();
    }
    catch (std::invalid_argument e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
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

bool isIntGTX(int num, int x, int)
{
    return num > x;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
        hour = getInt(hourPrompt, "The hour must be between 1 and 12. ", isIntInRange, 1, 13);
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

int inputClockType()
{

    int timeInt = getInt("Is the clock 12 hour or 24 hour? ", "Please enter 12 or 24.", isAorB, 12, 24);

    return timeInt;
}
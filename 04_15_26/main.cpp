#include <vector>
#include <random>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <stdexcept>
#include "twelveHrClock.h"
#include "twentyFourHrClock.h"

int getInt(std::string prompt, std::string error, bool (*valid)(int, int, int), int low = 0, int high = 0);
int getInt(std::string prompt);
bool isIntInRange(int num, int low, int high);
bool isIntGTX(int num, int x = 0, int = 0);
void resetStream();
bool isAorB(int num, int a, int b);
TwelveHrClock::PartOfDayType inputPartOfDay();
int inputClockType();
Clock *makeClock();

// M05 part b lab change twenty four hour clock to use exceptions

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
        std::cout << *myClock << std::endl;
        delete myClock;
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

int getInt(std::string prompt)
{
    int num;
    bool validInput = false;
    while (!validInput)
    {
        std::cout << prompt;
        std::cin >> num;
        std::cout << std::endl;
        try
        {
            if (!std::cin)
            {
                throw std::runtime_error("Input Failure detected. Resetting stream.");
            }
            validInput = true;
        }
        catch (std::runtime_error e)
        {
            std::cout << e.what() << std::endl;
            resetStream();
        }
    }

    return num;
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
    int sec;
    bool validHour = false;
    bool validMin = false;
    bool validSec = false;
    bool validAM = false;
    bool retry = true;
    while (retry)

    {
        if (!validHour)
        {
            hour = getInt(hourPrompt);
            validHour = true;
        }
        if (!validMin)
        {
            min = getInt("Enter the clock's minutes: ");
            validMin = true;
        }
        if (!validSec)
        {
            sec = getInt("Enter the clock's seconds: ");
            validSec = true;
        }
        TwelveHrClock::PartOfDayType part = TwelveHrClock::PM;
        try
        {
            if (type == 12)
            {
                if (!validAM)
                {
                    part = inputPartOfDay();
                    validAM = true;
                }
                clockptr = new TwelveHrClock(hour, min, sec, part);
            }
            else
            {
                clockptr = new TwentyFourHrClock(hour, min, sec);
            }
            retry = false;
        }
        catch (invalid_hour e)
        {
            std::cout << e.what() << std::endl;
            validHour = false;
        }
        catch (invalid_min e)
        {
            std::cout << e.what() << std::endl;
            validMin = false;
        }
        catch (invalid_sec e)
        {
            std::cout << e.what() << std::endl;
            validSec = false;
        }
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
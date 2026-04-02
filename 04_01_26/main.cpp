#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include "pointers.h"
#include "arrayListType.h"

int getInt(std::string prompt, std::string error, bool (*valid)(int, int, int), int low = 0, int high = 0);
bool isIntInRange(int num, int low, int high);
bool isIntGT0(int num, int = 0, int = 0);
void resetStream();

int main()
{
    int guess = getInt("Enter a number between 1 and 100: ", "That is not a number between 1 and 100.", isIntInRange, 1, 100);
    int copy(guess);
    std::cout << "You guessed " << guess << std::endl;
    guess = getInt("Enter a number greater than 0 ", "Invalid input", isIntGT0);
    pointerClass p1(guess);
    p1.addItem(43);
    {
        pointerClass p2(p1);
        p2.addItem(22);
    }
    p1.addItem(236);
    int size = getInt("Please enter the list size between 1 and 10: ", "That is not a valid number.", isIntInRange, 1, 10);
    arrayListType myarray(size);
    for (int i = 0; i < size; i++)
    {
        myarray.insert(rand() % 900 + 1);
    }
    myarray.insert(rand() % 1000 + 900);

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

bool isIntGT0(int num, int, int)
{
    return num > 0;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
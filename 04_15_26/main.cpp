#include <vector>
#include <random>
#include <iostream>
#include <iomanip>
#include <chrono>

int getInt(std::string prompt, std::string error, bool (*valid)(int, int, int), int low = 0, int high = 0);
bool isIntInRange(int num, int low, int high);
bool isIntGTX(int num, int x = 0, int = 0);
void resetStream();

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
    std::cout << nums.at(userIndex) << std::endl;
    std::cout << std::setw(userIndex) << std::setfill('!') << "!" << std::endl;
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
#ifndef MOVIE_H
#define MOVIE_H
#include "clock.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <limits>

class MovieTimes
{
public:
    MovieTimes(std::string title, int runtime, std::string rating);
    MovieTimes(const MovieTimes &);
    void enterTimes();
    std::string tostring() const;
    std::string getTitle() const;
    int getRuntime() const;
    std::string getRating() const;
    void addTime(Clock timeAdd);
    ~MovieTimes();
    void clearTimes();

private:
    std::string title;
    int runtime;
    std::string rating;
    Clock **showTimes;
    int numTimes;
    void copyMovie(const MovieTimes &);
};

int getInt(std::string prompt, std::string error, bool (*valid)(int, int, int), int low = 0, int high = 0);
bool isIntInRange(int num, int low, int high);
bool isIntGT0(int num, int = 0, int = 0);
void resetStream();
Clock *makeClock();
bool isAorB(int num, int a, int b);
Clock::ClockType inputClockType();
Clock::PartOfDayType inputPartOfDay();
#endif

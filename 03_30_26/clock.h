#ifndef CLOCK_H
#define CLOCK_H
#include <string>
#include <sstream>
#include <iomanip>

class Clock
{
public:
    enum ClockType
    {
        TWELVE,
        TWENTYFOUR
    };
    enum PartOfDayType
    {
        AM,
        PM
    };
    Clock(int = 0, int = 0, int = 0, ClockType = TWENTYFOUR, PartOfDayType = AM);
    void setTime(int, int = 0, int = 0);
    void setHour(int);
    void setMinute(int);
    void setSecond(int);
    void getTime(int &, int &, int &) const;
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    std::string printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const Clock &) const;
    void clockTick();

private:
    int hr;
    int min;
    int sec;
    ClockType type;
    PartOfDayType timeOfDay;
};

#endif
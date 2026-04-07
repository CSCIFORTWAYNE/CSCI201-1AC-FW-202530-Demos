#ifndef TCLOCK_H
#define TCLOCK_H
#include <string>
#include <sstream>
#include <iomanip>
#include "clock.h"
class TwelveHrClock : public Clock
{
public:
    enum PartOfDayType
    {
        AM,
        PM
    };
    static const PartOfDayType parts[2]; //{partType::AM, partType::PM};
    static const std::string partToStr[2];
    TwelveHrClock(int h = 12, int m = 0, int s = 0, PartOfDayType part = AM);
    void setHour(int hour);
    void incrementHours();
    void setPartOfDay(PartOfDayType part);
    std::string getPartOfDayStr() const;
    PartOfDayType getPartOfDayType() const;
    std::string printTime() const;

private:
    PartOfDayType partOfDay;
};

#endif
#include "twelveHrClock.h"

const TwelveHrClock::PartOfDayType TwelveHrClock::parts[2] = {TwelveHrClock::AM, TwelveHrClock::PM};
const std::string TwelveHrClock::partToStr[] = {"AM", "PM"};

TwelveHrClock::TwelveHrClock(int h, int m, int s, PartOfDayType part)
{
    setTime(h, m, s);
    setPartOfDay(part);
}

void TwelveHrClock::setHour(int hour)
{

    if (hour < 1 || hour > 12)
    {
        hour = 12;
    }

    hr = hour;
}

void TwelveHrClock::incrementHours()
{
    hr++;
    if (hr == 12)
    {
        if (partOfDay == TwelveHrClock::AM)
        {
            partOfDay = TwelveHrClock::PM;
        }
        else
        {
            partOfDay = TwelveHrClock::AM;
        }
    }

    if (hr > 12)
    {
        hr = 1;
    }
}

void TwelveHrClock::setPartOfDay(PartOfDayType part)
{
    partOfDay = part;
}

std::string TwelveHrClock::getPartOfDayStr() const
{
    return partToStr[partOfDay];
}

TwelveHrClock::PartOfDayType TwelveHrClock::getPartOfDayType() const
{
    return partOfDay;
}

std::string TwelveHrClock::printTime() const
{
    std::string out = Clock::printTime() + " " + getPartOfDayStr();
    return out;
}

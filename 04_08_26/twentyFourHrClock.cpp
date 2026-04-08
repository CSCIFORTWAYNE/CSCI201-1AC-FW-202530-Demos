#include "twentyFourHrClock.h"

TwentyFourHrClock::TwentyFourHrClock(int h, int m, int s)
{
    setTime(h, m, s);
}

void TwentyFourHrClock::setHour(int hour)
{
    if (hour < 0 || hour > 23)
    {
        hour = 0;
    }
    hr = hour;
}

void TwentyFourHrClock::incrementHours()
{
    hr++;
    if (hr == 24)
    {
        hr = 0;
    }
}

TwentyFourHrClock TwentyFourHrClock::operator+(int minutesToAdd)
{
    TwentyFourHrClock newClock = *this;
    for (int i = 0; i < minutesToAdd; i++)
    {
        newClock.incrementMinutes();
    }
    return newClock;
}

bool TwentyFourHrClock::operator==(TwentyFourHrClock rightClock)
{
    return this->hr == rightClock.hr && this->min == rightClock.min && this->sec == rightClock.sec;
}

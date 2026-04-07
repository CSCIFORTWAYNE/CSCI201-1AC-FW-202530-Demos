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

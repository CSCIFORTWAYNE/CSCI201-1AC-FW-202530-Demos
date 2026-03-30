#include "clock.h"

void Clock::setTime(int h, int m, int s)
{
    setHour(h);
    setMinute(m);
    setSecond(s);
}

void Clock::setHour(int h)
{
    if (type == TWENTYFOUR)
    {
        if (h < 0 || h > 23)
        {
            h = 0;
        }
    }
    else
    {
        if (h < 1 || h > 12)
        {
            h = 12;
        }
    }
    hr = h;
}

void Clock::setMinute(int m)
{
    if (m < 0 || m > 59)
    {
        m = 0;
    }
    min = m;
}
void Clock::setSecond(int s)
{
    if (s < 0 || s > 59)
    {
        s = 0;
    }
    sec = s;
}

Clock::Clock(int h, int m, int s, ClockType t, PartOfDayType part) : type(t), timeOfDay(part)
{
    setTime(h, m, s);
}

void Clock::getTime(int &h, int &m, int &s) const
{
    h = hr;
    m = min;
    s = sec;
}

int Clock::getHour() const
{
    return hr;
}

int Clock::getMinute() const
{
    return min;
}

int Clock::getSecond() const
{
    return sec;
}

std::string Clock::printTime() const
{
    std::ostringstream out;
    out << std::setfill('0');
    out << std::setw(2) << hr << ":" << std::setw(2) << min << ":" << std::setw(2) << sec;
    if (type == TWELVE)
    {
        if (timeOfDay == AM)
        {
            out << " AM";
        }
        else
        {
            out << " PM";
        }
    }
    // std::string out;
    // out = out + std::to_string(hr) + ":" + std::to_string(min) + ":" + std::to_string(sec);
    return out.str();
}

void Clock::incrementSeconds()
{
    sec++;
    if (sec == 60)
    {
        sec = 0;
        incrementMinutes();
    }
}

void Clock::incrementMinutes()
{
    min++;
    if (min == 60)
    {
        min = 0;
        incrementHours();
    }
}

void Clock::incrementHours()
{
    hr++;
    if (hr == 24)
    {
        hr = 0;
    }
}

bool Clock::equalTime(const Clock &otherClock) const
{
    return hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec;
}

void Clock::clockTick()
{
    incrementSeconds();
}
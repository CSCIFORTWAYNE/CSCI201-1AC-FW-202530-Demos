#ifndef TFCLOCK_H
#define TFCLOCK_H
#include <string>
#include <sstream>
#include <iomanip>
#include "clock.h"

class TwentyFourHrClock : public Clock
{
public:
    TwentyFourHrClock(int h = 0, int m = 0, int s = 0);
    void setHour(int hour);
    void incrementHours();
};

#endif

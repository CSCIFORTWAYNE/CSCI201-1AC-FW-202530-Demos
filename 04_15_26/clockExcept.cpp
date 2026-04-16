#include "clockExcept.h"

invalid_hour::invalid_hour() : invalid_argument("The hour given is invalid.")
{
}

invalid_hour::invalid_hour(int x) : invalid_argument(std::to_string(x) + " is not a valid hour")
{
}

invalid_min::invalid_min() : invalid_argument("The minute given is invalid.")
{
}

invalid_min::invalid_min(int x) : invalid_argument(std::to_string(x) + " is not a valid minute")
{
}

invalid_sec::invalid_sec() : invalid_argument("The seconds given are invalid.")
{
}

invalid_sec::invalid_sec(int x) : invalid_argument(std::to_string(x) + " are not a valid seconds")
{
}

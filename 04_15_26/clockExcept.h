#ifndef CLOCKE_H
#define CLOCKE_H
#include <stdexcept>

class invalid_hour : public std::invalid_argument
{
public:
    invalid_hour();
    invalid_hour(int);
};

class invalid_min : public std::invalid_argument
{
public:
    invalid_min();
    invalid_min(int);
};

class invalid_sec : public std::invalid_argument
{
public:
    invalid_sec();
    invalid_sec(int);
};

#endif
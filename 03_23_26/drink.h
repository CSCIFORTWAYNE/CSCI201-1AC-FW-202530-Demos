#ifndef DRINK_H
#define DRINK_H
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

enum baseType
{
    COFFEE,
    TEA,
    CREAM
};
enum class sizeType
{
    SMALL,
    MED,
    LARGE
};

class drink
{
public:
    enum tempType
    {
        HOT,
        ICE,
        BLEND
    };
    drink(baseType b, tempType t, sizeType s, std::string dairy, std::string flavor);
    std::string getBaseStr() const;
    std::string getTemperature() const;
    std::string getSize() const;
    std::string getDairy() const;
    std::string getFlavor() const;
    double getPrice() const;
    void setBase(baseType b);
    void setTemperature(tempType t);
    void setSize(sizeType s);
    void setDairy(std::string d);
    void setFlavor(std::string f);
    std::string toString() const;
    const static std::string baseStr[];
    const static std::string tempStr[];
    const static std::string sizeStr[];
    const static baseType bases[];
    const static tempType temps[];
    const static sizeType sizes[];

private:
    baseType base;
    tempType temp;
    sizeType size;
    std::string dairy;
    std::string flavor;
};

#endif
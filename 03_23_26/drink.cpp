#include "drink.h"

drink::drink(baseType b, tempType t, sizeType s, std::string dairy, std::string flavor) : product(22, "drink", 1)
{
    setBase(b);
    setTemperature(t);
    setSize(s);
    setDairy(dairy);
    setFlavor(flavor);
    setPrice(getPrice());
}

drink::drink(baseType b, tempType t, sizeType s, std::string dairy, std::string flavor, int pn, std::string desc) : product(pn, desc, 1)
{
    setBase(b);
    setTemperature(t);
    setSize(s);
    setDairy(dairy);
    setFlavor(flavor);
    setPrice(getPrice());
}

void drink::setBase(baseType b)
{
    base = b;
}

void drink::setTemperature(tempType t)
{
    temp = t;
}

void drink::setSize(sizeType s)
{
    size = s;
}

void drink::setDairy(std::string d)
{
    dairy = d;
}

void drink::setFlavor(std::string f)
{
    flavor = f;
}
std::string drink::getBaseStr() const
{
    return baseStr[base];
}

std::string drink::getTemperature() const
{
    return tempStr[temp];
}

std::string drink::getSize() const
{
    return sizeStr[static_cast<int>(size)];
}

std::string drink::getDairy() const
{
    return dairy;
}

std::string drink::getFlavor() const
{
    return flavor;
}

double drink::getPrice() const
{
    double price = 0;
    switch (size)
    {
    case sizeType::SMALL:
        price = 2;
        break;
    case sizeType::MED:
        price = 3;
        break;
    case sizeType::LARGE:
        price = 4;
        break;
    }
    switch (base)
    {
    case COFFEE:
        price += 2.75;
        break;
    case TEA:
        price += 1.75;
        break;
    case CREAM:
        break;
    }
    switch (temp)
    {
    case HOT:
        break;
    case ICE:
        price += .5;
        break;
    case BLEND:
        price += .75;
        break;
    }
    price += .5;
    std::string lowerD = dairy;
    std::transform(lowerD.begin(), lowerD.end(), lowerD.begin(), ::tolower);
    if (lowerD == "whole milk")
    {
        price += .75;
    }
    else if (lowerD == "skim milk")
    {
        price += .75;
    }
    else if (lowerD == "cream")
    {
        price += 1.5;
    }
    else if (lowerD == "oat milk")
    {
        price += 2;
    }
    else if (lowerD == "almond milk")
    {
        price += 2;
    }
    else
    {
        price += .5;
    }

    return price;
}

std::string drink::toString() const
{
    std::ostringstream out;
    out << std::setprecision(2) << std::fixed << std::showpoint;
    out << product::toString() << std::endl;
    out << "Size: " << getSize() << std::endl;
    out << "Base: " << getBaseStr() << std::endl;
    out << "Temperature: " << getTemperature() << std::endl;
    out << "Flavor: " << getFlavor() << std::endl;
    out << "Dairy: " << getDairy() << std::endl;
    out << "Price: $" << getPrice() << std::endl;

    return out.str();
}

const std::string drink::baseStr[] = {"Coffee", "Tea", "Cream"};
const std::string drink::tempStr[] = {"Hot", "Iced", "Blended"};
const std::string drink::sizeStr[] = {"Small", "Medium", "Large"};
const baseType drink::bases[] = {COFFEE, TEA, CREAM};
const drink::tempType drink::temps[] = {tempType::HOT, tempType::ICE, tempType::BLEND};
const sizeType drink::sizes[] = {sizeType::SMALL, sizeType::MED, sizeType::LARGE};
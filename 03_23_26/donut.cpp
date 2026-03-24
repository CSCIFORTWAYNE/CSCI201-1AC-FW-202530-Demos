#include "donut.h"

donut::donut(std::string icing, std::string topping, std::string drizzle) : product(56, "donut", 2.50)
{

    setIcing(icing);
    setTopping(topping);
    setDrizzle(drizzle);
}

donut::donut(int pn, std::string desc, double price, std::string icing, std::string topping, std::string drizzle) : product(pn, desc, price)
{
    setIcing(icing);
    setTopping(topping);
    setDrizzle(drizzle);
}

icingType donut::getIcing()
{
    return icing;
}

toppingType donut::getTopping()
{
    return topping;
}

drizzleType donut::getDrizzle()
{
    return drizzle;
}

void donut::setIcing(std::string i)
{
    int it;
    std::transform(i.begin(), i.end(), i.begin(), ::tolower);

    for (it = 0; it < 7; it++)
    {
        std::string ice = iceStr[it];
        std::transform(ice.begin(), ice.end(), ice.begin(), ::tolower);
        if (ice == i)
        {
            this->icing = static_cast<icingType>(it);
            break;
        }
    }
    if (it == 7)
    {
        std::cout << "You have entered an invalid icing choice. Your icing will be set to none." << std::endl;
        this->icing = NOICE;
    }
}

void donut::setTopping(std::string t)
{
    int i;
    std::transform(t.begin(), t.end(), t.begin(), ::tolower);
    for (i = 0; i < 16; i++)
    {
        std::string top = topStr[i];
        std::transform(top.begin(), top.end(), top.begin(), ::tolower);

        if (top == t)
        {
            this->topping = static_cast<toppingType>(i);
            break;
        }
    }
    if (i == 16)
    {
        std::cout << "You have entered an invalid topping choice. Your topping will be set to none." << std::endl;
        this->topping = NOTOP;
    }
}

void donut::setDrizzle(std::string d)
{
    int i;
    std::transform(d.begin(), d.end(), d.begin(), ::tolower);

    for (i = 0; i < 6; i++)
    {
        std::string driz = drizzleStr[i];
        std::transform(driz.begin(), driz.end(), driz.begin(), ::tolower);
        if (driz == d)
        {
            this->drizzle = static_cast<drizzleType>(i);
            break;
        }
    }
    if (i == 6)
    {
        std::cout << "You have entered an invalid drizzle choice. Your drizzle will be set to none." << std::endl;
        this->drizzle = NODRIZZLE;
    }
}

std::string donut::toString() const
{
    std::string out = product::toString();
    out += " Icing: " + iceStr[icing] + " Topping: " + topStr[topping] + " Drizzle: " + drizzleStr[drizzle];
    return out;
}

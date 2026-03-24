#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

class product
{
public:
    product(int pn, std::string desc, double p, int q = 1);
    double getPrice() const;
    std::string getDescription() const;
    int getProdNum() const;
    int getQuantity() const;
    void setPrice(double p);
    void setDescription(std::string desc);
    void setQuantity(int q);
    std::string toString() const;

protected:
    double price;
    std::string description;
    int prodNum;
    int quantity;
};
#endif
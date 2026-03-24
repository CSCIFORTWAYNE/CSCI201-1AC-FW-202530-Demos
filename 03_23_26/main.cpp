#include <iostream>
#include <iomanip>
#include "person.h"
#include "employee.h"
#include "product.h"
#include "drink.h"
#include "donut.h"

// Lecture activity M02-a
//  create another class to inherit from product
//  make sure you properly invoke the product constructor
//  include a toString that calls the product toString
//  create an object for you new class in the main
//  print the toString for your object

int main()
{
    Person p("Harry Potter", 12, "111-2222", "email@aol.com");
    Employee e;
    //  p.name;
    e.getName();
    std::cout << p.toString() << std::endl;
    std::cout << std::setfill('-');
    std::cout << std::setw(60) << "-" << std::endl;
    std::cout << e.toString() << std::endl;

    product prod(3, "the first product", 3.99, 18);
    donut d;
    drink myDrink(COFFEE, drink::HOT, sizeType::LARGE, "dairy", "flavor");
    std::cout << prod.toString() << std::endl;
    std::cout << d.toString() << std::endl;
    std::cout << myDrink.toString() << std::endl;

    return 0;
}
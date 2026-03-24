#include <iostream>
#include <iomanip>
#include "person.h"
#include "employee.h"

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

    return 0;
}
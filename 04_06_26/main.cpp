#include <iostream>
#include "person.h"
#include "employee.h"

void printPerson(Person &p);

int main()
{
    Employee emp("Harry Potter", 13, "555-1212", "hpotter@email.com", 23000.21, "2021-12-12");
    printPerson(emp);
    std::cout << emp.toString() << std::endl;

    return 0;
}

void printPerson(Person &p)
{
    std::cout << p.toString() << std::endl;
}

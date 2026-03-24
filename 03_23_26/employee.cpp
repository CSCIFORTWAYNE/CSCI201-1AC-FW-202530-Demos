#include "employee.h"

Employee::Employee() : Person("Harry Potter", 12, "555-1212", "hpotter@aol.com"), preferredDrink(COFFEE, drink::ICE, sizeType::MED, "None", "None")
{
    salary = 6000;
    hireDate = "2020-01-01";
}

Employee::Employee(std::string n, int a, std::string p, std::string e, double s, std::string h, drink d) : Person(n, a, p, e), preferredDrink(d)
{
    setSalary(s);
    setHireDate(h);
}

void Employee::setSalary(double s)
{
    if (s < 6000)
    {
        s = 6000;
    }
    salary = s;
}

void Employee::setHireDate(std::string h)
{
    hireDate = h;
}

double Employee::getSalary() const
{
    return salary;
}

std::string Employee::getHireDate() const
{
    return hireDate;
}

std::string Employee::toString() const
{
    std::ostringstream out;
    out << Person::toString();
    out << "Salary: " << salary << std::endl;
    out << "Hire Date: " << hireDate << std::endl;
    return out.str();
}
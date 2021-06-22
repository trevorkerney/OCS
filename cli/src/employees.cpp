#include "../inc/employees.h"

Employee::Employee(string& p_name)
{
    this -> name = p_name;
}

Employee::~Employee()
{

}

void Employee::set_name(string& p_name)
{
    this -> name = p_name;
}

string Employee::get_name() const
{
    return this -> name;
}



Employees::Employees()
{

}

Employees::~Employees()
{
    
}

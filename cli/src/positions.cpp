#include "../inc/positions.h"

Position::Position(string& p_name, string& p_filename, vector<Employee>& p_employees)
{
    this -> name = p_name;
    this -> filename = p_filename;
    this -> employees = p_employees;
}

Position::~Position()
{

}

void Position::set_name(string& p_name)
{
    this -> name = p_name;
}

string Position::get_name() const
{
    return this -> name;
}

void Position::set_filename(string& p_filename)
{
    this -> filename = p_filename;
}

string Position::get_filename() const
{
    return this -> filename;
}

void Position::set_employees(vector<Employee>& p_employees)
{
    this -> employees = p_employees;
}

vector<Employee> Position::get_employees() const
{
    return this -> employees;
}

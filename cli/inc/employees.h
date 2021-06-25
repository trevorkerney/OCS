#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class Position;
class Employee
{
private:

    string name;
    vector<Position*> positions;

public:

    Employee(string& p_name);
    ~Employee();

    void set_name(string& p_name);
    string get_name() const;
    
};

class Employees
{
private:

    vector<Employee*> employees;

public:

    Employees();
    ~Employees();



};

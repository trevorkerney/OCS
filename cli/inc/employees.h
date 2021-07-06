#pragma once

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include "../deps/include/nlohmann/json.hpp"
using json = nlohmann::json;

class ScheduleEntry;
class Position;

class Employee
{
private:

    string name;
    int scheduled_count;
    vector<Position*> positions;
    vector<ScheduleEntry*> scheduled_entries;

public:

    Employee(string& p_name, int& p_scheduled_count);
    ~Employee();

    // return name of employee
    string get_name() const;
    // return scheduled count of employee
    int get_scheduled_count() const;
    
};

class Employees
{
private:

    const string filename = "employees.json";
    string relative_datapath;
    vector<Employee*> employees;

    // loads employees from disk
    void read_employees();
    // saves employees to disk
    void write_employees() const;
    // get employees file path
    string get_path() const;

public:

    Employees(string& p_relative_datapath);
    ~Employees();

    // returns reference to list of employees
    vector<Employee*>& get_employees();

};

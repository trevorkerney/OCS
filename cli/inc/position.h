#ifndef _OCS_POSITION
#define _OCS_POSITION

#include "employee.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

class Position
{
private:

    string name;
    string filename;
    vector<Employee> employees;

public:

    Position(string& p_name, string& p_filename, vector<Employee>& p_employees);
    ~Position();

    void set_name(string& p_name);
    string get_name() const;

    void set_filename(string& p_filename);
    string get_filename() const;

    void set_employees(vector<Employee>& p_employees);
    vector<Employee> get_employees() const;

};

#endif

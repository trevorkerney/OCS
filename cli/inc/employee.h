#ifndef _OCS_EMPLOYEE
#define _OCS_EMPLOYEE

#include <string>
#include <vector>

using std::string;
using std::vector;

class Employee
{
private:

    string name;

public:

    Employee(string& p_name);
    ~Employee();

    void set_name(string& p_name);
    string get_name() const;
    
};

#endif

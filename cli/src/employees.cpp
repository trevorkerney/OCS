#include "../inc/employees.h"

Employee::Employee(string& p_name, int& p_scheduled_count)
{
    this -> name = p_name;
    this -> scheduled_count = p_scheduled_count;
}

Employee::~Employee()
{

}

string Employee::get_name() const
{
    return this -> name;
}

int Employee::get_scheduled_count() const
{
    return this -> scheduled_count;
}



Employees::Employees(string& p_relative_datapath)
{
    this -> relative_datapath = p_relative_datapath;
    this -> read_employees();
}

Employees::~Employees()
{
    for (Employee* employee : this -> employees)
    {
        delete employee;
    }
}

void Employees::read_employees()
{
    string test = this -> get_path();
    ifstream employees_file(this -> get_path());

    if (employees_file.is_open())
    {
        if (json::accept(employees_file))
        {
            employees_file.seekg(0);

            json employees_json;

            try
            {
                employees_json = json::parse(employees_file);
            }
            catch (json::parse_error& e)
            {
                std::cout << e.what() << std::endl;
                return;
            }

            json employees = employees_json["employees"];
            
            for (int _i = 0; _i < employees.size(); _i++)
            {
                string name = employees[_i]["name"];
                int scheduled_count = employees[_i]["scheduled count"];

                Employee* employee = new Employee(name, scheduled_count);
                this -> employees.push_back(employee);
            }
        }
        else
        {
            this -> write_employees();
        }
    }
    else
    {
        cout << "Couldn't open employees file.";
    }
}

void Employees::write_employees() const
{
    ofstream employees_file(this -> get_path());

    if (employees_file.is_open())
    {
        json employees_json;
        employees_json["#"] = "   Editing this file is discouraged unless you're sure of what you're doing.   ";
        employees_json["employees"] = json::array();

        for (int _i = 0; _i < this -> employees.size(); _i++)
        {
            json employee;

            employee["name"] = this -> employees.at(_i) -> get_name();
            employee["scheduled count"] = this -> employees.at(_i) -> get_scheduled_count();

            employees_json["employees"].push_back(employee);
        }

        employees_file << employees_json.dump(4);
    }
    else
    {
        cout << "Couldn't open employees file.";
    }
}

string Employees::get_path() const
{
    return this -> relative_datapath + this -> filename;
}

vector<Employee*>& Employees::get_employees()
{
    return this -> employees;
}

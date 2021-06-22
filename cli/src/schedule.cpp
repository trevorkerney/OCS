#include "../inc/schedule.h"

ScheduleEntry::ScheduleEntry(vector<Employee>& p_employees, time_t p_timestamp = time(0))
{
    this -> employees = p_employees;
    this -> timestamp = p_timestamp;
}

ScheduleEntry::~ScheduleEntry()
{

}

void ScheduleEntry::set_employees(vector<Employee>& p_employees)
{
    this -> employees = p_employees;
}

vector<Employee> ScheduleEntry::get_employees() const
{
    return this -> employees;
}

void ScheduleEntry::set_timestamp(time_t& p_timestamp)
{
    this -> timestamp = p_timestamp;
}

time_t ScheduleEntry::get_timestamp() const
{
    return this -> timestamp;
}



Schedule::Schedule()
{

}

Schedule::~Schedule()
{

}

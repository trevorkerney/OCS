#ifndef _OCS_SCHEDULE
#define _OCS_SCHEDULE

#include "positions.h"

#include <string>
#include <vector>
#include <ctime>

using std::string;
using std::vector;

class ScheduleEntry;
class Schedule;
class Schedules;

class ScheduleEntry
{
private:

    vector<Employee> employees;
    time_t timestamp;

public:

    ScheduleEntry(vector<Employee>& p_employees, time_t p_timestamp);
    ~ScheduleEntry();

    void set_employees(vector<Employee>& p_employees);
    void set_timestamp(time_t& p_timestamp);

    vector<Employee> get_employees() const;
    time_t get_timestamp() const;

};

class Schedule
{
private:

    vector<ScheduleEntry> schedule;

public:

    Schedule();
    ~Schedule();

};

class Schedules
{
private:

    vector<Schedule> schedules;

public:

    Schedules();
    ~Schedules();

};

#endif

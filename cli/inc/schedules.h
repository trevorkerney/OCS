#pragma once

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <iomanip>
using std::get_time;

#include <sstream>
using std::istringstream;

#include <vector>
using std::vector;

#include <ctime>

#include <fstream>
using std::ifstream;
using std::ofstream;

#include "positions.h"

#if defined(_WIN32)

    #include "../deps/include/tronkko/dirent.h"

#else

    #include <filesystem>
    namespace filesystem = std::filesystem;

#endif

#include "../deps/include/nlohmann/json.hpp"
using json = nlohmann::json;

class Employee;
class Employees;

class ScheduleEntry
{
private:

    vector<Employee*> employees;
    time_t timestamp;

public:

    ScheduleEntry(vector<Employee*>& p_employees, time_t p_timestamp);
    ~ScheduleEntry();

};

enum time_unit
{
    hour, week, month, year
};

enum selection_method
{
    ordered, randomized
};

class Schedule
{
private:

    string filename;
    string name;

    int* start;

    int entry_length;
    time_unit entry_unit;

    bool autoregen;
    int autoregen_advance;

    vector<Position*> positions;

    vector<ScheduleEntry*> schedule;

    // load schedule from disk
    void write_schedule() const;

public:

    Schedule(string& p_filename, string& p_name, int p_start[], int p_entry_length, time_unit p_entry_unit, bool& p_autoregen, int& p_autoregen_advance, vector<Position*> p_positions, vector<ScheduleEntry*> p_schedule);
    ~Schedule();

};

class Schedules
{
private:

    string relative_datapath;
    vector<Schedule*> schedules;
    Positions* positions;
    Employees* employees;

    // loads schedules from disk
    void read_schedules();
    // gets list of schedule filenames
    vector<string> get_schedule_files();

public:

    Schedules(string& p_relative_datapath, Positions& p_positions, Employees& p_employees);
    ~Schedules();

};

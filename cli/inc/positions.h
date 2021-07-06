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

#include "employees.h"

#if defined(_WIN32)

    #include "../deps/include/tronkko/dirent.h"

#else

    #include <filesystem>
    namespace filesystem = std::filesystem;

#endif

#include "../deps/include/nlohmann/json.hpp"
using json = nlohmann::json;

class Schedule;

class Position
{
private:

    string relative_datapath;
    string filename;
    string name;
    string plural;
    vector<Employee*> employees;
    vector<Schedule*> schedules;

    
    // get position file path
    string get_path() const;

public:

    Position(string& p_relative_path, string& p_filename, string& p_name, string& p_plural, vector<Employee*>& p_employees);
    ~Position();

    // saves position to disk
    void write_position() const;
    // return name of employee
    string get_name() const;
};

class Positions
{
private:

    string relative_datapath;
    vector<Position*> positions;
    Employees* employees;

    // loads positions from disk
    void read_positions();
    // gets list of position filenames
    vector<string> get_position_files();

public:

    Positions(string& p_relative_datapath, Employees& p_employees);
    ~Positions();

    vector<Position*>& get_positions();
};

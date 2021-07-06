#include "../inc/schedules.h"

ScheduleEntry::ScheduleEntry(vector<Employee*>& p_employees, time_t p_timestamp = time(0))
{
    this -> employees = p_employees;
    this -> timestamp = p_timestamp;
}

ScheduleEntry::~ScheduleEntry()
{
    
}



Schedule::Schedule(string& p_filename, string& p_name, int p_start[], int p_entry_length, time_unit p_entry_unit, bool& p_autoregen, int& p_autoregen_advance, vector<Position*> p_positions, vector<ScheduleEntry*> p_schedule)
{
    this -> filename = p_filename;
    this -> name = p_name;

    this -> start = p_start;

    this -> entry_length = p_entry_length;
    this -> entry_unit = p_entry_unit;

    this -> autoregen = p_autoregen;
    this -> autoregen_advance = p_autoregen_advance;
}

Schedule::~Schedule()
{
    
}



Schedules::Schedules(string& p_relative_datapath, Positions& p_positions, Employees& p_employees)
{
    this -> relative_datapath = p_relative_datapath;
    this -> positions = &p_positions;
    this -> employees = &p_employees;
    this -> read_schedules();
}

Schedules::~Schedules()
{
    for (Schedule* schedule : this -> schedules)
    {
        delete schedule;
    }
}

void Schedules::read_schedules()
{
    vector<string> files = this -> get_schedule_files();

    for (string filename : files)
    {
        ifstream schedule_file(this -> relative_datapath + filename);

        if (schedule_file.is_open())
        {
            if (json::accept(schedule_file))
            {
                schedule_file.seekg(0);

                json schedule_json;

                try
                {
                    schedule_json = json::parse(schedule_file);
                }
                catch (json::parse_error& e)
                {
                    std::cout << e.what() << std::endl;
                }

                string name = schedule_json["name"];

                int start[4] = {
                    schedule_json["initial start"]["hour"],
                    schedule_json["initial start"]["day"],
                    schedule_json["initial start"]["week"],
                    schedule_json["initial start"]["month"]
                };

                int entry_length = schedule_json["entry"]["length"];
                time_unit entry_unit = time_unit(schedule_json["entry"]["unit"]);

                bool autoregen = schedule_json["automatic regeneration"]["autoregen"];
                int autoregen_advance = schedule_json["automatic regeneration"]["regeneration advance"];

                json schedule_positions_json = schedule_json["positions"];

                vector<Position*> schedule_positions;
                schedule_positions.reserve(schedule_positions_json.size());

                for (int _i = 0; _i < schedule_positions_json.size(); _i++)
                {
                    string schedule_position = schedule_json["positions"][_i];

                    bool found = false;
                    for (int _j = 0; _j < this -> positions -> get_positions().size(); _j++)
                    {
                        if (schedule_position == this -> positions -> get_positions().at(_j) -> get_name())
                        {
                            found = true;
                            schedule_positions.push_back(this -> positions -> get_positions().at(_j));
                            break;
                        }
                    }
                    if (!found)
                    {
                        cout << "Position not found." << endl;
                    }
                }

                json schedule_entries_json = schedule_json["entries"];

                vector<ScheduleEntry*> schedule_entries;
                schedule_entries.reserve(schedule_entries_json.size());

                for (int _i = 0; _i < schedule_entries_json.size(); _i++)
                {
                    struct std::tm tm;
                    string str = schedule_entries_json["time"];
                    istringstream ss(str);
                    ss >> get_time(&tm, "%Y%m%d%H");


                    char timestamp_buffer[80];
                    cout << strftime(
                        timestamp_buffer,
                        80,
                        "%Y %b %d %a %I:%M %p",
                        &tm
                    );
                }

                /*
                Schedule* schedule = new Schedule(
                    filename,
                    name,
                    start,
                    entry_length, entry_unit,
                    autoregen, autoregen_advance,
                    schedule_positions,

                );

                this -> schedules.push_back(schedule);
                */
            }
            else
            {
                // temp
                cout << "Schedule not parsable";
            }
        }
        else
        {
            cout << "Couldn't open employees file.";
        }
    }
    
}

vector<string> Schedules::get_schedule_files()
{
    #if defined(_WIN32) // until the MinGW devs fix <filesystem>, this is the workaround.

        struct dirent **sfiles;
        string test = this -> relative_datapath;
        int n = scandir(this -> relative_datapath.c_str(), &sfiles, NULL, alphasort);

        if (n < 0) 
        {
            cout << "Cannot open " << this -> relative_datapath;

            exit(EXIT_FAILURE);
        }

        vector<string> files;
        files.reserve(n);

        for (int _i = 0; _i < n; _i++)
        {
            struct dirent *ent = sfiles[_i];

            if (ent -> d_type == DT_REG && (string(ent -> d_name).rfind("schedule_", 0)) == 0)
            {
                files.push_back(ent -> d_name);
            }
        }

        for (int i = 0; i < n; i++) {
            free(sfiles[i]);
        }
	    free(sfiles);

        return files;

    #else

        vector<string> files;

        for (const filesystem::directory_entry& entry : filesystem::directory_iterator(this -> relative_datapath))
        {
            string file = string(entry.path()).substr(this -> relative_datapath.length(), string(entry.path()).length());

            if (file.rfind("schedule_", 0) == 0)
            {
                files.push_back(file);
            }
        }

        return files;

    #endif
}

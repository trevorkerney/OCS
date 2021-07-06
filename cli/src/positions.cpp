#include "../inc/positions.h"

Position::Position(string& p_relative_datapath, string& p_filename, string& p_name, string& p_plural, vector<Employee*>& p_employees)
{
    this -> relative_datapath = p_relative_datapath;
    this -> filename = p_filename;
    this -> name = p_name;
    this -> plural = p_plural;
    this -> employees = p_employees;
}

Position::~Position()
{
    
}

void Position::write_position() const
{
    ofstream position_file(this -> get_path());

    if (position_file.is_open())
    {
        json positions_json;
        positions_json["#"] = "   Editing this file is discouraged unless you're sure of what you're doing.   ";
        positions_json["name"] = this -> name;
        positions_json["plural"] = this -> plural;
        positions_json["employees"] = json::array();

        for (int _i = 0; _i < this -> employees.size(); _i++)
        {
            positions_json["employees"].push_back(this -> employees.at(_i) -> get_name());
        }

        position_file << positions_json.dump(4);
    }
}

string Position::get_path() const
{
    return this -> relative_datapath + this -> filename;
}

string Position::get_name() const
{
    return this -> name;
}



Positions::Positions(string& p_relative_datapath, Employees& p_employees)
{
    this -> relative_datapath = p_relative_datapath;
    this -> employees = &p_employees;
    this -> read_positions();
}

Positions::~Positions()
{
    for (Position* position : this -> positions)
    {
        delete position;
    }
}

void Positions::read_positions()
{
    vector<string> files = this -> get_position_files();

    for (string filename : files)
    {
        ifstream position_file(this -> relative_datapath + filename);

        if (position_file.is_open())
        {
            if (json::accept(position_file))
            {
                position_file.seekg(0);

                json position_json;

                try
                {
                    position_json = json::parse(position_file);
                }
                catch (json::parse_error& e)
                {
                    std::cout << e.what() << std::endl;
                    return;
                }

                string name = position_json["name"];
                string plural = position_json["plural"];

                json position_employees_json = position_json["employees"];

                vector<Employee*> position_employees;

                // for each employee in position json
                for (int _i = 0; _i < position_employees_json.size(); _i++)
                {
                    string employee = position_employees_json[_i];
                    
                    bool found = false;
                    // for every employee
                    for (int _j = 0; _j < this -> employees -> get_employees().size(); _j++)
                    {
                        if (employee == this -> employees -> get_employees().at(_j) -> get_name())
                        {
                            found = true;
                            position_employees.push_back(this -> employees -> get_employees().at(_j));
                            break;
                        }
                    }
                    if (!found)
                    {
                        cout << "Employee not found." << endl;
                    }
                }

                Position* position = new Position(
                    this -> relative_datapath, filename,
                    name, plural,
                    position_employees
                );

                this -> positions.push_back(position);
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

vector<string> Positions::get_position_files()
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

            if (ent -> d_type == DT_REG && (string(ent -> d_name).rfind("position_", 0)) == 0)
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

        for (const filesystem::directory_entry& entry : filesystem::directory_iterator(this -> datapath))
        {
            string file = string(entry.path()).substr(this -> datapath.length(), string(entry.path()).length());

            if (file.rfind("schedule_", 0) == 0)
            {
                files.push_back(file);
            }
        }

        return files;

    #endif
}

vector<Position*>& Positions::get_positions()
{
    return this -> positions;
}

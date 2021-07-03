#include <iostream>
#include <ctime>
#include <string>
#include <cstring>

#include "../inc/schedules.h"

using std::string;
using std::cout;
using std::endl;

string get_formatted_timestamp(time_t p_timestamp = time(0), const char* p_format = "%Y %b %d %a %I:%M %p" /* https://en.cppreference.com/w/cpp/chrono/c/strftime */)
{
    const int timestamp_size = 80;
    char timestamp_buffer[timestamp_size];
    time_t timestamp = p_timestamp;
    tm* timeinfo = localtime(&timestamp);
    strftime(
        timestamp_buffer,
        timestamp_size,
        p_format,
        timeinfo
    );

    return string(timestamp_buffer);
}

string get_data_path()
{
    #if defined(_DEBUG)

        return "../data/";

    #else
        #if defined(_WIN32)

            /*wchar_t* datapath = 0;
            SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, NULL, &datapath);
            std::wstring ws(datapath);
            string str(ws.begin(), ws.end());
            return str;

            PWSTR path[MAX_PATH];
            SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, *path);

            return std::wstring(path);*/
            
        #elif defined(__APPLE__)



        #elif defined(__linux__)


        
        #else

            return "";

        #endif
    #endif
}

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        cout << "On-Call Scheduler" << endl;
        cout << get_formatted_timestamp() << endl;

        

        cout << endl << "Press enter to continue..."; std::cin.get();
        return 0;
    }
    else
    {
        for (int _i = 1; _i < argc; _i++)
        {
            cout << argv[_i] << " ";
        }
        //cout << "Usage: ocs-cli [create/edit/delete] [schedule/position/employee]" << endl;
        cout << endl << "Usage: ocs-cli (no options)";

        cout << endl << "Press enter to continue..."; std::cin.get();
        return 1;
    }
}

#include <iostream>
#include <ctime>
#include <string>
#include <cstring>

#include "../inc/schedule.h"

using std::string;
using std::cout;
using std::endl;

#ifdef _WIN32

    #include "windows.h"

    void attach_gui()
    {

    }

    void run_gui()
    {
        /*
        STARTUPINFOA si;
        PROCESS_INFORMATION pi;

        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);
        ZeroMemory(&pi, sizeof(pi));

        CreateProcessA(
            "E:\\Dev\\projects\\OCS\\gui\\src-tauri\\target\\debug\\app.exe",
            NULL,
            NULL,
            NULL,
            false,
            0,
            NULL,
            NULL,
            &si,
            &pi
        );

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
        */
    }

#else

    void attach_gui()
    {
    
    }

    void run_gui()
    {
        
    }

#endif

string get_formatted_timestamp(time_t p_timestamp = time(0), const char* p_format = "%Y %b %d %a %I:%M %p") // https://en.cppreference.com/w/cpp/chrono/c/strftime
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

int main(int argc, char* argv[])
{
    if (argc == 3)
    {
        string command = string(argv[1]) + ' ' + string(argv[2]);
        if (command == "create schedule")
        {
            
        }
        else if (command == "create position")
        {

        }
        else if (command == "create employee")
        {
            
        }
        else if (command == "edit schedule")
        {

        }
        else if (command == "edit position")
        {

        }
        else if (command == "edit employee")
        {
            
        }
        else if (command == "delete schedule")
        {

        }
        else if (command == "delete position")
        {

        }
        else if (command == "delete employee")
        {
            
        }

        return 0;
    }

    cout << "On-Call Scheduler" << endl;
    cout << "Usage: ocs [create/edit/delete] [schedule/position/employee]" << endl;
    return 1;
}

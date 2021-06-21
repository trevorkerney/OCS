#include <iostream>
#include <ctime>
#include <string>
#include <cstring>

#include "../inc/schedule.h"

using std::string;

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

string get_formatted_timestamp()
{
    const int timestamp_size = 80;
    char timestamp_buffer[timestamp_size];
    time_t timestamp = time(0);
    tm* timeinfo = localtime(&timestamp);
    strftime(
        timestamp_buffer,
        timestamp_size,
        "%Y %b %d %a %I:%M %p", // https://en.cppreference.com/w/cpp/chrono/c/strftime
        timeinfo
    );

    return string(timestamp_buffer);
}

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        std::cout << "On-Call Scheduler";
    }
    else
    {
        /*
        CREATE
            SCHEDULE
                
        ADD
            EMPLOYEE
            POSITION
        EDIT
            SCHEDULE
            EMPLOYEE
            POSITION
        DELETE
            SCHEDULE
            EMPLOYEE
            POSITION
        */

        if (strcmp(argv[1], "create") == 0)
        {
            
        }
        else if (strcmp(argv[1], "add") == 0)
        {

        }
        else if (strcmp(argv[1], "edit") == 0)
        {

        }
        else if (strcmp(argv[1], "delete") == 0)
        {

        }
        else
        {
            std::cout << "Invalid option(s)." << std::endl;
            return 1;
        }
    }

    return 0;
}

#include <iostream>
#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>

void main()
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    wchar_t processname[] = L"notepad.exe";
    DWORD exitcode;

    // Start the child process. 
    if (!CreateProcess(NULL,   // No module name (use command line)
        processname,        // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory 
        &si,            // Pointer to STARTUPINFO structure
        &pi)           // Pointer to PROCESS_INFORMATION structure
        )
    {
        printf("CreateProcess failed (%d).\n", GetLastError());
        return;
    }
    else
    {
        printf("CreateProcess successfull. Checking application.\n");
        Sleep(5000);
        if (!GetExitCodeProcess(pi.hProcess, &exitcode))
        {
            printf("GetExitCodeProcess failed (%d).\n", GetLastError());
            return;
        }
        else
        {
            if (exitcode != 259)
            {
                printf("Application exited with code (%d).\n", exitcode);
            }
            else
            {
                printf("Application is running correctly. Exiting.\n");
                TerminateProcess(pi.hProcess, 0);
            }
        }
    }



    // Wait until child process exits.
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Close process and thread handles. 
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}



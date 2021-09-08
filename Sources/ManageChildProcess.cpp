//
// Created by VictorHamon on 07/09/2021.
//

#include <iostream>
#include "ManageChildProcess.hpp"


#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)

#include "Windows.h"

int ManageChildProcess::CreateChildProcess(const char *pathname, char **args, char **env, char *rawline) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );
    // Start the child process.
    if( !CreateProcess( NULL,   // No module name (use command line)
                         rawline,        // Command line
                        NULL,           // Process handle not inheritable
                        NULL,           // Thread handle not inheritable
                        FALSE,          // Set handle inheritance to FALSE
                        0,              // No creation flags
                        NULL,           // Use parent's environment block
                        NULL,           // Use parent's starting directory
                        &si,            // Pointer to STARTUPINFO structure
                        &pi )           // Pointer to PROCESS_INFORMATION structure
            )
    {
        // Close process and thread handles.
        CloseHandle( pi.hProcess );
        CloseHandle( pi.hThread );
        return -1;
    }

    // Wait until child process exits.
    WaitForSingleObject( pi.hProcess, INFINITE );

    // Close process and thread handles.
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
    return 0;
}

#else

#include <unistd.h>
#include <sys/wait.h>

int ManageChildProcess::CreateChildProcess(const char *pathname, char **args, char **env, char *rawline) {
    pid_t c_pid = fork();

    if (c_pid == -1) {
        perror("fork");
    } else if (c_pid > 0) {
        wait(nullptr);
    } else {
        return execve(pathname, args, env);
    }
    return 0;
}
#endif

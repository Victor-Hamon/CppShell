#include <iostream>
#include "Sources/Shell.hpp"

int main(int ac, char**av, char**envp) {
    Shell sh(envp);
#if defined(WIN32)
    std::cout << "In windows version" << std::endl;
#else
    std::cout << "In UNIX version" << std::endl;
#endif
    sh.StartShell();
    return 0;
}


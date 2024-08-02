#include <cstdio>
#include <thread>
#include <iostream>


// Linux
// BUFSIZ: 8192
// stdout: _IOLBF (line buffered)
// stderr: _IONBF (unbuffered) must be unbuffered
// fopen: _IOFBF (fully buffered)

// cout: _IOLBF 1 (line buffered)
// cerr: _IONBF 2 (unbuffered) must be unbuffered
// clog: _IOLBF 2 (unbuffered)
// fstream: _IOFBF (fully buffered)

// Windows
// BUFSIZ: 512
// stdout: _IONBF (unbuffered)
// stderr: _IONBF (unbuffered) must be unbuffered
// fopen: _IOFBF (fully buffered)

// C语言标准要求stdout可以行缓冲，stderr必须无缓冲

static char buf[BUFSIZ];

int main() {
    setvbuf(stdout, buf, _IONBF, sizeof buf);

    fprintf(stdout, "Hello, ");
    fflush(stdout);

    std::this_thread::sleep_for(std::chrono::seconds(1));

    fprintf(stdout, "world!\n");

    std::this_thread::sleep_for(std::chrono::seconds(1));

    fprintf(stdout, "Exiting...\n");


}
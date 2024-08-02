#include <cstdio>
#include <unistd.h>
#include <thread>

struct OStream {
    int fd;
    char buf[BUFSIZ]{};
    size_t pos = 0;
    int mode = _IOLBF;

    OStream(int fd_, int mode_ = _IOLBF) : fd(fd_), mode(mode_) {
        ::setvbuf(stdout, buf, mode_, sizeof buf);
    }

    ~OStream() {
        flush();
    }

    void setbuf(char *buf_, size_t size) const {
        ::setvbuf(stdout, buf_, mode, size);
    }

    void flush() {
        ::write(1, buf, pos);
        pos = 0;
    }

    void putchar(char c) {
        if (pos == sizeof buf) flush();
        buf[pos++] = c;
        if (mode == _IONBF || (mode == _IOLBF && c == '\n')) flush();
    }

    // overload operator<<
    OStream &operator<<(char const *s) {
        while (*s) putchar(*s++);
        return *this;
    }

    OStream &operator<<(char c) {
        putchar(c);
        return *this;
    }
};

OStream mout{STDOUT_FILENO, _IOLBF};
OStream merr{STDERR_FILENO, _IONBF};

int main() {
    OStream os(_IOLBF);
    os << "Hello, ";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    os << "world!";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    os << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(1));
    os << "Exiting..." << '\n' << "AAA";
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
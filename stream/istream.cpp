#include <cstdio>
#include <termios.h>
#include <unistd.h>
#include <vector>

static int fuck_stdin = ( [] {
    if (isatty(STDIN_FILENO)) {
        struct termios tc{};
        tcgetattr(STDIN_FILENO, &tc);
        tc.c_lflag &= ~ICANON;
        tc.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &tc);
    }
}(), 0);

#define MAX_BUF_SIZE 1024

int main() {
    char buf[MAX_BUF_SIZE];
    size_t pos = 0;
    fprintf(stderr, "请输入密码: ");
    fflush(stderr);
    while (true) {
        int c = getchar();
        if (c == EOF || c == '\n' || c == '\r') {
            putchar('\n');
            break;
        } else if (c == '\b' || c == '\x7f') {
            if (pos) {
                --pos;
                putchar('\b');
                putchar(' ');
                putchar('\b');
            }
        } else {
            if (pos < MAX_BUF_SIZE) {
                buf[pos++] = c;
                putchar('*');
            }
        }
    }
    buf[pos] = 0;
    fprintf(stderr, "您输入的密码为 %s\n", buf);
}



















#include <iostream>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cmath>

int main() {
    int fd;

    int N = 8, sum = 0;
    std::string out;

    mkfifo("/tmp/PProcess", 0666);

    char in[80];

    fd = open("/tmp/PProcess", O_RDONLY);
    read(fd, in, 80);

    char *next = nullptr;
    char *ptr = strtok_r(in, " ", &next);
    out = "";

    sum += std::atoi(ptr);

    while (ptr != NULL) {
        sum += std::atoi(ptr);
        ptr = strtok_r(NULL, " ", &next);
    }
    out = std::to_string(sum);

    out += '\n';

    fd = open("/tmp/SProcess", O_WRONLY);
    write(fd, out.c_str(), strlen(out.c_str()) + 1);

    return 0;
}

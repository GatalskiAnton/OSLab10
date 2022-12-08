#include <iostream>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cmath>

int main() {

    int fd;

    int N = 8;
    std::string out;

    mkfifo("/tmp/AProcess", 0666);

    char in[80];

    fd = open("/tmp/AProcess", O_RDONLY);
    read(fd, in, 80);


    char *next = nullptr;
    char *ptr = strtok_r(in, " ", &next);
    out = "";

    out += std::to_string(std::pow(std::atoi(ptr), 3));
    while (ptr != NULL) {
        out += " " + std::to_string(std::pow(std::atoi(ptr), 3));
        ptr = strtok_r(NULL, " ", &next);
    }
    out += '\n';

    fd = open("/tmp/PProcess", O_WRONLY);
    write(fd, out.c_str(), strlen(out.c_str()) + 1);

    return 0;
}

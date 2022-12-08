#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string>

int main(int argc, char *argv[]) {
    int fd;

    std::string out;
    out += std::to_string(std::atoi(argv[1]) * 7);
    for (int i = 2; i < argc; ++i) {
        out += " " + std::to_string(std::atoi(argv[i]) * 7);
    }
    out += '\n';

    mkfifo("/tmp/MProcess", 0666);

    fd = open("/tmp/MProcess", O_WRONLY);

    write(fd, out.c_str(), strlen(out.c_str()) + 1);
    close(fd);
}
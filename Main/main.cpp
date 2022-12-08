#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd;

    mkfifo("/tmp/SProcess", 0666);

    char res[80];

    fd = open("/tmp/SProcess", O_RDONLY);
    read(fd, res, 80);

    printf("Result: %s\n", res);
    close(fd);
}

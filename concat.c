#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
int main(int argc, char *argv[4])
{
    char str[512];
    int sz;
    int fd = open(argv[1], O_RDONLY);
    int fd1 = open(argv[2], O_RDONLY);
    int fd2 = open(argv[3], O_CREATE | O_RDWR);
    while ((sz = read(fd, str, 512)) > 0)
        write(fd2, str, sz);

    while ((sz = read(fd1, str, 512)) > 0)
        write(fd2, str, sz);

    close(fd);
    close(fd1);
    close(fd2);
    exit();
}
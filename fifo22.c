#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

long factorial(int n) {
    if (n == 0) return 1;
    long res = 1;
    for (int i = 1; i <= n; i++) res *= i;
    return res;
}

int main() {
    int fd;
    int num;
    long res;

    fd = open("PIPE02", O_RDONLY);
    read(fd, &num, sizeof(num));
    close(fd);

    res = factorial(num);

    fd = open("PIPE02", O_WRONLY);
    write(fd, &res, sizeof(res));
    close(fd);

    return 0;
}

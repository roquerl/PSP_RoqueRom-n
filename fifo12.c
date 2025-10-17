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
    int fd1, fd2;
    int num;
    long res;

    // Leer número desde FIFO1
    fd1 = open("FIFO1", O_RDONLY);
    read(fd1, &num, sizeof(num));
    close(fd1);

    res = factorial(num);

    // Escribir resultado en FIFO2
    fd2 = open("FIFO2", O_WRONLY);
    write(fd2, &res, sizeof(res));
    close(fd2);

    return 0;
}

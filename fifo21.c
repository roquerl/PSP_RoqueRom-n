#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main() {
    int fd;
    int num, res;

    mkfifo("PIPE02", 0666);

    srand(time(NULL));
    num = rand() % 11;
    printf("fifo21 genera el número %d y lo escribe en PIPE02\n", num);

    fd = open("PIPE02", O_WRONLY);
    write(fd, &num, sizeof(num));
    close(fd);

    fd = open("PIPE02", O_RDONLY);
    read(fd, &res, sizeof(res));
    printf("El factorial calculado por fifo22: %d! = %d\n", num, res);
    close(fd);

    unlink("PIPE02");

    return 0;
}

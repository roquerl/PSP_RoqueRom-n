#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main() {
    int fd1, fd2;
    int num, res;

    // Crear pipes
    mkfifo("FIFO1", 0666);
    mkfifo("FIFO2", 0666);

    srand(time(NULL));
    num = rand() % 11; // Número entre 0 y 10
    printf("fifo11 genera el número %d y lo escribe en FIFO1\n", num);

    // Escribir número en FIFO1
    fd1 = open("FIFO1", O_WRONLY);
    write(fd1, &num, sizeof(num));
    close(fd1);

    // Leer factorial de FIFO2
    fd2 = open("FIFO2", O_RDONLY);
    read(fd2, &res, sizeof(res));
    printf("El factorial calculado por fifo12: %d! = %d\n", num, res);
    close(fd2);

    // Eliminar pipes
    unlink("FIFO1");
    unlink("FIFO2");

    return 0;
}

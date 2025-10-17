#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int fd[2];
    pid_t pid;
    char buffer[20];
    pipe(fd);
    pid = fork();

    if (pid == 0) { // HIJO
        close(fd[1]);
        int suma = 0;
        int nbytes;
        while ((nbytes = read(fd[0], buffer, sizeof(buffer))) > 0) {
            if (buffer[0] == '+') {
                printf("Recibido carácter +\n");
                break;
            }
            int num = atoi(buffer);
            printf("Numero a sumar: %d\n", num);
            suma += num;
        }
        printf("La suma total es igual a: %d\n", suma);
        close(fd[0]);
    } else { // PADRE
        close(fd[0]);
        char *nums[] = {"25", "18", "67", "+"};
        for (int i = 0; i < 4; i++) {
            write(fd[1], nums[i], strlen(nums[i]) + 1);
        }
        close(fd[1]); // Muy importante → avisa al hijo que ya no habrá más datos
    }

    return 0;
}

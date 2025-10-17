#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int pipe1[2], pipe2[2];
    pid_t pid;
    char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";

    pipe(pipe1);
    pipe(pipe2);
    pid = fork();

    if (pid == 0) { // HIJO
        close(pipe1[0]);
        close(pipe2[1]);
        int dni;
        printf("Introduce el número de tu DNI: ");
        scanf("%d", &dni);
        write(pipe1[1], &dni, sizeof(dni));
        char letra;
        read(pipe2[0], &letra, sizeof(letra));
        printf("la letra del NIF es %c\n", letra);
        close(pipe1[1]);
        close(pipe2[0]);
    } else { // PADRE
        close(pipe1[1]);
        close(pipe2[0]);
        int dni;
        read(pipe1[0], &dni, sizeof(dni));
        int resto = dni % 23;
        char letra = letras[resto];
        write(pipe2[1], &letra, sizeof(letra));
        close(pipe1[0]);
        close(pipe2[1]);
    }
    return 0;
}

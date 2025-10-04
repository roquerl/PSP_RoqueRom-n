#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int acumulado = getpid(),valor,valor4,valor5; // P1 define acumulado
    pid_t pid,p4,p5;

    printf("Soy P1 (pid=%d), acumulado inicial = %d\n", getpid(), acumulado);

    // Crear P2
    pid = fork();
    if (pid == 0) {
        // Estamos en P2
        valor = (getpid() % 2 == 0) ? acumulado + 10 : acumulado - 100;
        printf("Soy P2 (pid=%d), acumulado modificado = %d\n", getpid(), valor);

        // Crear P5
        p5 = fork();
        if (p5 == 0) {
            valor5 = (getpid() % 2 == 0) ? acumulado + 10 : acumulado - 100;
            printf("Soy P5 (pid=%d), acumulado modificado = %d\n", getpid(), valor5);
            exit(0);
        }
        wait(NULL); // P2 espera a P5
        exit(0);
    }

    // Crear P3
    pid = fork();
    if (pid == 0) {
        // Estamos en P3
        valor = (getpid() % 2 == 0) ? acumulado + 10 : acumulado - 100;
        printf("Soy P3 (pid=%d), acumulado modificado = %d\n", getpid(), valor);

        // Crear P4
        p4 = fork();
        if (p4 == 0) {
            valor4 = (getpid() % 2 == 0) ? acumulado + 10 : acumulado - 100;
            printf("Soy P4 (pid=%d), acumulado modificado = %d\n", getpid(), valor4);
            exit(0);
        }
        wait(NULL); // P3 espera a P4
        exit(0);
    }

    // P1 espera a P2 y P3
    wait(NULL);
    wait(NULL);
}


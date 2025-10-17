#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
    pid_t p1,p2,p3,p4,p5;

    // P1
    printf("Soy P1, mi pid es %d (no tengo abuelo)\n", getpid());

    p1 = fork(); 
    if (p1 == 0) {  
        // P2
        printf("Soy P2, mi pid es %d, mi abuelo es %d\n", getpid(), getppid());

        p2 = fork();
        if (p2 == 0) { 
            // P3
            printf("Soy P3, mi pid es %d, mi abuelo es %d\n", getpid(), getppid());

            p3 = fork();
            if (p3 == 0) { 
                // P5
                printf("Soy P5, mi pid es %d, mi abuelo es %d\n", getpid(), getppid());
                exit(0);
            }
            wait(NULL); // P3 espera a P5
            exit(0);
        }

        p4 = fork();
        if (p4 == 0) {
            // P4
            printf("Soy P4, mi pid es %d, mi abuelo es %d\n", getpid(), getppid());

            pid_t p5 = fork();
            if (p5 == 0) {
                // P6
                printf("Soy P6, mi pid es %d, mi abuelo es %d\n", getpid(), getppid());
                exit(0);
            }
            wait(NULL); // P4 espera a P6
            exit(0);
        }

        // P2 espera a P3 y P4
        wait(NULL);
        wait(NULL);
        exit(0);
    }

    // P1 espera a P2
    wait(NULL);
}

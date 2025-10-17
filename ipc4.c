#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

long factorial(int n) {
    if (n == 0) return 1;
    long res = 1;
    for (int i = 1; i <= n; i++) res *= i;
    return res;
}

int main() {
    int pipe1[2], pipe2[2];
    pid_t pid;
    pipe(pipe1);
    pipe(pipe2);
    pid = fork();

    srand(time(NULL));

    if (pid == 0) { // HIJO
        close(pipe1[1]);
        close(pipe2[0]);
        int num;
        read(pipe1[0], &num, sizeof(num));
        long res = factorial(num);
        write(pipe2[1], &res, sizeof(res));
        close(pipe1[0]);
        close(pipe2[1]);
    } else { // PADRE
        close(pipe1[0]);
        close(pipe2[1]);
        int num = rand() % 11;
        printf("El proceso padre genera el numero %d en el pipe1\n", num);
        write(pipe1[1], &num, sizeof(num));
        long res;
        read(pipe2[0], &res, sizeof(res));
        printf("El factorial calculado por el proceso hijo: %d != %ld\n", num, res);
        close(pipe1[1]);
        close(pipe2[0]);
    }
    return 0;
}

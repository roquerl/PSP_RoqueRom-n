#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_INTENTOS 100

char registros[MAX_INTENTOS][50];
int contador = 0;

void manejador(int sig) {
    if (contador < MAX_INTENTOS) {
        time_t ahora = time(NULL);
        struct tm *t = localtime(&ahora);
        snprintf(registros[contador], sizeof(registros[contador]),
                 "Señal SIGINT recibida a las %02d:%02d:%02d",
                 t->tm_hour, t->tm_min, t->tm_sec);
        contador++;
    }
}

void terminar(int sig) {
    FILE *f = fopen("salidas.txt", "w");
    if (f == NULL) {
        perror("Error al crear el fichero");
        exit(1);
    }

    printf("\nFichero salidas.txt\n");
    for (int i = 0; i < contador; i++) {
        printf("%s\n", registros[i]);
        fprintf(f, "%s\n", registros[i]);
    }

    fclose(f);
    printf("…\n");
    exit(0);
}

int main() {
    signal(SIGINT, manejador);  
    signal(SIGTSTP, terminar);  
    while (1) {
        pause(); // Esperar señales
    }

    return 0;
}

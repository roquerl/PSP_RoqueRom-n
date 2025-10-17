#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void mostrarFecha(const char *mensaje){
	time_t t;
	struct tm *tmInfo;
	char buffer[80];
	
	time(&t);
	tmInfo = localtime(&t);
	strftime(buffer,sizeof(buffer),"%d %m %Y %H:%M:%S", tmInfo);
	
	printf("%s %d: %s \n", mensaje,getpid(),buffer);
	fflush(stdout);
	
	
	}

void manejador(int numsig){
	
	mostrarFecha("Fin del proceso");
	exit(0);
	
	
	
	}

int main()
{
	signal(SIGINT,manejador);
	
	mostrarFecha("Iniciamos el proceso");
	
	while(1){
		pause();
	
	}
	
	return 0;
}


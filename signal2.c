#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int s = 0;

void manejador (int sig){
	
	s += 5;
	printf("Han transcurrido %d segundos\n",s);
	
	//Forzamos impresion inmediata
	fflush(stdout);
	
	//Programamos la siguiente alarma
	alarm(5);
	
	}

int main(){
	
	signal(SIGALRM,manejador);
	alarm(5);
	
	while(1){
		
		pause();
	
	}

	return 0;
}


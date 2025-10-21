#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int repeticiones;
int intervalo;
int contador = 0;

void manejador_alarma(int sig){
	
	time_t ahora = time(NULL);
	struct tm *t = localtime(&ahora);
	
	printf("Señal de alarma recibida a las %02d:%02d:%02d\n",t->tm_hour,t->tm_min,t->tm_sec);
	
	fflush(stdout);
	
	contador++;
	
	
	if(contador < repeticiones){
		alarm(intervalo);
		
	
	}else{
		
		printf("Alarma desactivada\n");
		exit(0);
		
		
	}

}



int main(){
	
	printf("¿Cuántas veces sonará la alarma?:");
	scanf("%d",&repeticiones);
	
	printf("¿Cada cuántos segundos se repetirá la alarma?:");
	scanf("%d",&intervalo);
	
	signal(SIGALRM,manejador_alarma);
	
	printf("Alarma activada\n");
	alarm(intervalo);
	
	while(1){
		
		pause();
	
	}
	
	return 0;
}

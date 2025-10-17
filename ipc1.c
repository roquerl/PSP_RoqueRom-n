#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
	
	int fd[2]
	pid_t p1;
	char buffer[100];
	time_t hora;
	char *fecha;
	
	
	pipe(fd);
	
	p1 = fork();
	
	if(p1 == 0){//P2
		
		close(fd[1]); //Cerramos escritura
		read(fd[0],buffer,sizeof(buffer);
		printf("Yo soy el proceso hijo mi poid es: %d\n",getpid());
		printf("Fecha/hora %s\n",buffer);
		close(fd[0]);
		
	}else{//P1
	
		clase[fd[0]]; // Cierro lectura
		time(&hora);
		fecha = ctime(&hora);
		write(fd[1],fecha,100);
		close(fd[1]);
	}
	
}

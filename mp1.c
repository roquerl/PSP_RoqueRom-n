#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
	
	pid_t p1;
	
	p1 = fork();
	
	if(p1 == 0){//P2
		printf("Yo soy el proceso hijo mi poid es: %d y el de mi padre es: %d",getpid(),getppid());
		printf("Muestro el nombre del alumno: Roque Román\n");
		
	}else{//P1
	
	    wait(NULL);
		printf("Yo soy el proceso padre mi pid es %d y el Pid de mi hijo es: %d", getpid(),getppid());
		exit(0);
	
	}
	
	
	
	
}

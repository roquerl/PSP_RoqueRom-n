#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


void main(){
	
	pid_t p1,p2;
	
	p1 = fork();
	
	
	if (p1 == 0){
		printf("Voy a dormir 10 s");
		sleep(10);
		printf("Despierto");
		printf("Soy el proceso P2, Despierto. Mi PID es: %d, mi padre es: %d\n", getpid(), getppid());
      
	
	
	}else{
		
		p2 = fork();
		
		if(p2 == 0){
			printf("Soy el proceso P3, mi pid es: %d y el de mi padre es: %d",getpid(),getppid());
		
		}else{
			p1 = wait(NULL);
			p2 = wait(NULL);
			printf("Soy el P1, mi pid es: %d y el hijo P3 es: %d \n", getpid(),p2);
		    printf("Soy el P1, mi pid es: %d y el hijo P2 es: %d \n", getpid(),p1);
			
			
		}
	
	
	}
	
	
	
}


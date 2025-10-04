#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


void main(){
	
	pid_t p1,p2;
	
	p1 = fork();

	if(p1 == 0){//P2
		
		p2 = fork();
		
		if(p2 == 0){//P3
			printf("Yo soy el proceso P3, mi PID es: %d y el de mi padre es: %d\n",getpid(),getppid());
		
			
		
		}else{
			p2 = wait(NULL);
			printf("Yo soy el proceso P2, mi PID es: %d y el de mi padre es: %d\n",getpid(),getppid());
			
		}
			
	
	}else{//P1
		p1 = wait(NULL);
		printf("Yo soy el proceso P1, mi PID es: %d y el de mi hijo (P2) es: %d\n", getpid(), p1);
		
	
	
	
	}	
	
	
}


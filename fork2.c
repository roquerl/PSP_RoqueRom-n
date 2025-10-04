#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
	
	pid_t p1,p2,p3;
	
	p1 = fork();
	
	if(p1 == 0){//P2
		
		p2 = fork();
		
		if(p2 == 0){ //P3
			
			p3 = fork();
			
			if(p3 == 0){ //P4
				
				printf("Soy el P4, mi pid es: %d y el padre es: %d. La suma es %d",getpid(),getppid(),getpid() + getppid())
				exit(0);
			
				
			}else{
			
				wait(NULL);
				printf("Soy el P3, mi pid es: %d y padre es: %d. La suma es %d",getpid(),getppid(),getpid() + getppid());
				exit(0);
				
			}
			
		
		}else{
		
			wait(NULL);
			printf("Soy el P2, mi pid es: %d y padre es: %d. La suma es %d",getpid(),getppid(),getpid() + getppid();
			exit(0);
		
		}
		
		
	}else{//P1
	
	    wait(NULL);
		printf("Yo soy el proceso padre mi pid es %d y el Pid de mi hijo es: %d. La suma es %d",getpid(),getppid(),getpid() + getppid();
		exit(0);
	
	}
	
	
	
	
}

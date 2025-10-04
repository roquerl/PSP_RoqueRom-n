#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


void main(){
	
	pid_t p1,p2,p3;
	
	p1 = fork(); // Crea P2
	
	
	if (p1 == 0){
		
		//Estoy en el hijp p2
		
		if(getpid() % 2 == 0){
		
			printf("Soy P2 (Par). Mi pid es: %d y hijo es: %d", getpid(),getppid());
			
	    }else{
		
			printf("Soy P2 (Impar). Mi pid es : %d y el hijo es: %d",getpid());
			
		}
		
		p2 = fork(); // Creo P3 desde P2
		
		if (p2 == 0){
	    
			// Estamos en P3
			if(getpid() % 2 == 0){
			
				printf("Soy P3 (Par). Mi pid es: %d y hijo es: %d", getpid(),getppid());
				
			}else{
				
				printf("Soy el P3 (Impar). Mi pid es: %d", getpid());
			
			}
			
			p3 = fork();
			
			 if (p3 == 0){
				//Estamos en P4
				if(getpid() % 2 == 0){
					
					printf("Soy el P4 (Par). Mi pid es: %d y PPI es: %d",getpid(),getppid());
				
				}else{
				
					printf("Soy el P4 (Impar). Mi pid es: %d",getpid());
				
				}
				
				exit(0); //Termina el P4

			}else{
				
				//P3 espera P4
				wait(NULL);
				exit(0);
			
			}
	    
	    }else{
			
			//P2 espera P3
			wait(NULL);
			exit(0);
		
		}
	}else{
		
		//P1 espera P2
		wait(NULL);
		
	}
		
}

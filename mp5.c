#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
	
	 pid_t pid1, pid2; 
 
	 printf("AAA \n"); 
 
     pid1 = fork(); 
 
   if (pid1==0) { 
 
      printf("BBB \n"); 
      exit(0);
 
   } 
   else { 
 
      pid2 = fork(); 
      
      if(pid2 == 0){
		printf("CCC \n"); 
		ext(0);
	  }
	  
	  wait(NULL); 
      wait(NULL);
      printf("CCC \n"); 
 
   } 
 
  exit(0);
	
}
	

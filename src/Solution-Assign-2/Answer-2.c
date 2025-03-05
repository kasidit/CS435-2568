#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
	int status, i; 
	pid_t pid[100]; 
	int n = 6;
        int j = 0; 

	for(i=0; i < n; i++){
          if (i % 2 == 0){ 
             pid[j] = fork(); 
	     if (pid [j] != 0){ 
                printf("at i = %d this pid (%ld) fork a child (%ld)\n", i, (long)getpid(), (long)pid[j]);	
	        fflush(stdout); 
             }
             j++;
          }
	}

        sleep(20); 
}

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  fork(); 
  printf("PID=%ld (PPID=%ld)\n", (long) getpid(),
		                 (long) getppid()); 
}




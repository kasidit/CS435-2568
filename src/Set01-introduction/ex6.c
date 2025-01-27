#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[]){
  int status;
  pid_t wait_pid;

  printf("PID=%ld (PPID=%ld)\n", (long) getpid(),
		                 (long) getppid()); 
  wait_pid = wait(&status); 

  if (wait_pid == -1) {
     if (errno == ECHILD) {
        printf("No child processes to wait for.\n");
     } else {
        perror("wait failed");
        return 1;
     }
  }
}




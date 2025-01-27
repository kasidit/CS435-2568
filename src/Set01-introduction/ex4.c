#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process (PID: %d)\n", getpid());
        sleep(2); 
        exit(0); 
    } else if (pid > 0) {
        // Parent process
        wait(NULL); 
        printf("Parent done (PID: %d)\n", getpid());
    }
    return 0;
}



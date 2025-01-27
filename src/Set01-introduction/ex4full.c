#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d)\n", getpid());
        sleep(2); 
        exit(0); 
    } else {
        // Parent process
        int status;
        pid_t waited_pid = waitpid(pid, &status, 0); 

        if (waited_pid == -1) {
            perror("waitpid failed");
            return 1;
        }
        if (WIFEXITED(status)) {
            printf("Child (PID: %d) exited with status %d.\n", pid, WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child (PID: %d) terminated by signal %d.\n", pid, WTERMSIG(status));
        }
    }
    return 0;
}

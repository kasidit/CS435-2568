#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(int argc, char * argv[]) {
    int pipefd[2];
    int fw[2];
    pid_t pid;
    char child_message[BUFFER_SIZE];
    char line[BUFFER_SIZE];
    int status;

    if (pipe(pipefd) == -1) {
        perror("pipe failed");
        return 1;
    }

    // Create a child process
    pid = fork();

    if (pid == -1) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) { // Child process
        close(pipefd[1]);

	dup2(pipefd[0],STDIN_FILENO);
        close(pipefd[0]);

	char *prog = "/usr/local/bin/ollama";
	char *argv0 = "ollama";
	char *param1 = "run";
	char *param2 = "deepseek-r1:7b";
	execl(prog, argv0, param1, param2, (char *)0); 

        close(fw[0]);

        exit(0); // Child process exits successfully
    } else { // Parent process
        close(pipefd[0]);

        write(pipefd[1], argv[1], strlen(argv[1])); // +1 for null terminator
        printf("Parent process send  message: %s size %ld\n", argv[1], strlen(argv[1]));

        close(pipefd[1]);

        waitpid(pid, &status, 0);  //Check the exit status if needed.

        printf("Child process exited with status: %d\n", WEXITSTATUS(status)); //Example of checking status.

    }

    return 0;
}


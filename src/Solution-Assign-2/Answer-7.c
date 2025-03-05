#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int status, i;
    pid_t pid;

    if((pid = fork()) == 0){
      int fd = open("/bin/ls", O_RDONLY | O_EXCL);
      if (fd == -1) {
        perror("open /bin/ls");
        exit(EXIT_FAILURE);
      }

      // Arguments for the ls program (argv)
      char *cmdargv[] = { "ls", "-l", "-r", "-g", "-k", "-i", "-t", "-R", NULL };

      // Environment variables (envp)
      char *cmdenvp[] = { NULL }; // No environment variables passed

      // Execute /bin/cat using fexecve
      if (fexecve(fd, cmdargv, cmdenvp) == -1) {
        perror("fexecve");
        close(fd); // Close the file descriptor if fexecve fails
        exit(EXIT_FAILURE);
      }
    }
    waitpid(pid, &status, 0);
    printf("Parent done\n"); 
    exit(0);
}

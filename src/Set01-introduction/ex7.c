#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main() {

    if (execlp("ls", "ls", "-l", NULL) == -1) {
        // execlp only returns if an error occurs
        perror("execlp failed");
        return 1; // Indicate failure
    }

    // This line will only be reached if execlp fails
    printf("This line should not be printed if execlp is successful.\n");

    // This return statement is technically unreachable if execlp succeeds
    return 0; 
}



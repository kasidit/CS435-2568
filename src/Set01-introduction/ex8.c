#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main() {

    printf("Before execlp()\n");

    execlp("ls", "ls", "-l", NULL);

    printf("After execlp()\n");
    return 0; 
}



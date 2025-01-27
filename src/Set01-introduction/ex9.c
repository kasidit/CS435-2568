#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main() {

    printf("Before execlp()\n");

    execlp("ex9", "ex9", NULL, NULL);

    printf("After execlp()\n");
    return 0; 
}



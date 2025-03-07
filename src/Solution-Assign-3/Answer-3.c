#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

int main(int argc, char* argv[]){
 
    char *ptr = malloc(50*sizeof(char)); 
    char *nptr; 

    memset(ptr, 'a', 10); 

    printf("%s\n", ptr);

    char *ptr2 = calloc(50, sizeof(char)); 

    int clear_cnt = 0;
    int i; 

    for(i=0;i < 10; i++){
	    if(*(ptr2+i) == 0) clear_cnt++; 
    }
    printf("clear_cnt = %d\n", clear_cnt);

    int newsize = 50; 

    nptr = realloc(ptr, newsize); 

    printf(" nptr = %ld, ptr = %ld\n", (long)nptr, (long)ptr); 
    if (nptr == ptr) 
      printf("The existing memory block staring at ptr (%ld) can \
         be extended to support the new size (%d)\n", (long)ptr, newsize); 
    else
      printf("Realloc() has to find a new memory block at  nptr (%ld)  \
         to support the new size (%d)\n", (long)nptr, newsize); 

}

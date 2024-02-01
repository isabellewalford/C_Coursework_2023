#include <stdio.h>

int printBytes (void *p, int);

// main 
int main(void) {
    

    return 0;
}

// Question 1
int printBytes (void *p, int bytes)
{
    for (i=0; i<b; i++)
    {
        printf("00%d : %d", i+1, *(int *)p);
        p = ((char*)p) + 1;
    }
}
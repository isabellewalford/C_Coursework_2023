#include <stdio.h>

int printBytes (void *p, int);

int main(void) {

    char arr[4] = {'A','B','C','D'};
    printBytes(&arr, 4);

    return 0;
}

int printBytes (void *p, int bytes)
{
    int i;
    printf("Starting at memory address: %p\n", p);
    for (i=0; i<bytes; i++)
    {
        printf("00%d : %d\n", i+1, *(char *)p);
        p = ((char*)p) + 1;
    }
}
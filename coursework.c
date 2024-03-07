#include <coursework.h>

int main(int argc, char **argv) {

    printf("Question 1:\n");
    char arr[4] = {'A','B','C','D'};
    printf("arr[4] = %c, %c, %c, %c\n",arr[0],arr[1],arr[2],arr[3]);
    printBytes(arr, 4);

    printf("\nQuestion 2:\n");
    char *reverse = NULL;

    reverseText(argv[1],getCount(argv[1]),&reverse);
    writeText(argv[2],reverse);
    
    return 0;
}

/*Question 1*/
int printBytes (void *p, int bytes)
{
    int i;

    if (bytes == 0)
    {
        fprintf(stderr,"Cannot print 0 bytes\n");
        exit(1);
    }
    
    printf("Starting at memory address: %p\n", p);
    for (i=0; i<bytes; i++)
    {
        /*cast to char to get one byte of memory*/
        printf("00%d : %d\n",i+1, *(char *)p);
        p++;
    }
    return 0;
} 
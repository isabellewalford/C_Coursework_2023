#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int printBytes (void *, int);
int reverseText(char [], char []);


int main(int argc, char **argv) {

/*
    printf("Question 1:\n");
    char arr[4] = {'A','B','C','D'};
    printBytes(&arr, 4);
*/
    printf("Question2:\n");
    reverseText(argv[1],argv[2]);

    return 0;
}


/*Question 1*/
int printBytes (void *p, int bytes)
{
    int i;
    printf("Starting at memory address: %p\n", p);
    for (i=0; i<bytes; i++)
    {
        printf("00%d : %d\n",i+1, *(int *)p);
        p= ((unsigned char *)p)+ 1;
    }
    return 0;
}

/*Question 2*/
int reverseText(char fileIn[], char fileOut[])
{
    FILE *fpIn;
    FILE *fpOut;
    char ch;
    int count;

    if ((fpIn = fopen(fileIn, "r")) == NULL)
    {
        printf("Unable to read file: %d: %s\n", errno, strerror(errno));
        exit(1);
    }
    else
    {
        printf("input file found");
    }
/*   
    while ( !feof(fpIn) )
    {
        ch = fgetc(fpIn);
        if( ch == EOF || ch == '\n' )
        {
            break;
        }
        ++count;
    }
    printf("character count: %d", count);
   

    malloc reverse with size count * char
    reverse = strrev(fgets(fileIn));
*/
    fclose(fpIn);
/*
    if ((fpOut = fopen(fileOut, "r")) == NULL)
    {
        fclose(fpOut);
        fpOut = fopen(fileOut, "w");
        printf("output file created");
    }
    else 
    {
        fclose(fpOut);
        fpOut = fopen(fileOut, "a");
        printf("output file found");
    }

    fputs(reverse, fpOut);

    fclose(fpOut);
*/

    return 0;

}


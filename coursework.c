#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int printBytes (void *, int);
int reverseText(char [], char []);


int main(int argc, char **argv) {

    printf("Question 1:\n");

    char arr[4] = {'A','B','C','D'};
    printBytes(&arr, 4);

    return 0;
}


/*Question 1*/
int printBytes (void *p, int bytes)
{
    int i;
    printf("Starting at memory address: %p\n", p);
    for (i=0; i<bytes; i++)
    {
        printf("00%d : %d\n",i+1, *(unsigned char *)p);
        p= ((char *)p)+ 1;
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
    
    while ( !feof(fp) )
    {
        ch = fgetc(fp);
        if( ch == EOF || ch == '\n' )
        {
            break;
        }
        ++count;
    }

    char reverse[count] = strrev(fgets(fileIn));
    fputs(reverse, fpOut);


    fclose(fpIn);
    fclose(fpOut);
    return 0;
}


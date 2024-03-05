#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int printBytes(void *, int);

char *reverseStr(char *);
int getCount(char [], int *);
int reverseText(char [], int, char **);
int writeText(char[], char[]);

int main(int argc, char **argv) {

    printf("Question 1:\n");
    char arr[4] = {'A','B','C','D'};
    printf("arr[4] = %c, %c, %c, %c\n",arr[0],arr[1],arr[2],arr[3]);
    printBytes(arr, 4);


    printf("Question 2:\n");
    int count = 0;
    char *reverse = NULL;

    getCount(argv[1], &count);
    reverseText(argv[1],count,&reverse);
    writeText(argv[2],reverse);
    
    return 0;
}


/*Question 1*/
int printBytes (void *p, int bytes)
{
    int i;
    printf("Starting at memory address: %p\n", p);
    for (i=0; i<bytes; i++)
    {
        /*cast to char to get one byte of memory*/
        printf("00%d : %d\n",i+1, *(char *)p);
        p++;
    }
    return 0;
}

/*Question 2*/

/* swap each char to reverse string*/
char *reverseStr(char *str)
{
    if (!str || ! *str)
        return str;

    int i = strlen(str) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}

int getCount(char fileIn[],int *charCount)
{
    FILE *fpIn;
    char ch;
    int count;
    

    if ((fpIn = fopen(fileIn, "r")) == NULL)
    {
        printf("Unable to read file\n");
        fprintf(stderr," error:%d: %s\n", errno, strerror(errno));
        exit(1);
    }
    else 
    {
        printf("Input file found\n");
    }
  
    /*count characters in the file until reaching a new line or end of file*/
    while ( !feof(fpIn) )
    {
        ch = fgetc(fpIn);
        if( ch == EOF || ch == '\n' )
        {
            break;
        }
        count++;
    }

    /*set the value of count for reverseText to use*/
    *charCount = count;
    fclose(fpIn);
    return 0;
}

int reverseText(char fileIn[], int count, char **reverse)
{
    FILE *fpIn;

    /*assign and check memory for an array that is the size of the characters in the first line*/
    if (!(*reverse = (char *)malloc(count*sizeof(char)))){
        printf("Out of memory\n");
        fprintf(stderr," error:%d: %s\n", errno, strerror(errno));
        exit(1); 
    }

    /*set file pointer and check it has opened*/
    if ((fpIn = fopen(fileIn, "r")) == NULL)
    {
        printf("Unable to read file\n");
        fprintf(stderr," error:%d: %s\n", errno, strerror(errno));
        exit(1);
    }
    
    /*get first line*/
    fgets(*reverse, count, fpIn);
    printf("Line read as: %s\n",*reverse);

    /*reverse characters*/
    reverseStr(*reverse);
    printf("Reversed line: %s\n",*reverse);
    fclose(fpIn);

    return 0;
}

int writeText(char fileOut[], char reverse[])
{
    FILE *fpOut;

    /*check is output file exists*/
    if ((fpOut = fopen(fileOut, "w")) == NULL)
    {
        printf("Error opening file\n");
        fprintf(stderr," error:%d: %s\n", errno, strerror(errno));
        exit(1);
    }

    /*writes reversed line to output and closes file*/
    if (! fputs(reverse, fpOut))
    {
        printf("Error writing to file\n");
        fprintf(stderr," error:%d: %s\n", errno, strerror(errno));
        exit(1);
    }
    else 
    {
        printf("Write successful\n");
    }
    
    /*close file ans free memory*/
    fclose(fpOut);
    free(reverse);
    return 0;
}


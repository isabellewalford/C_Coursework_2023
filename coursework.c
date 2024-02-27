#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int printBytes(void *, int);
char *strrev(char *);
int getCount(char [], int *);
int reverseText(char [], char [], int, char *);


int main(int argc, char **argv) {

    printf("Question 1:\n");
    char arr[4] = {'A','B','C','D'};
    printf("arr[4] = %d, %d, %d, %d\n",arr[0],arr[1],arr[2],arr[3]);
    printBytes(arr, 4);


    printf("Question2:\n");
    int count = 0;
    char *reverse = NULL;

    getCount(argv[1], &count);
    reverseText(argv[1],argv[2],count,reverse);

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

/*strrev is not available with some compilers so manually added*/
char *strrev(char *str)
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

int getCount(char fileIn[],int *c)
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
        printf("input file found\n");
    }
  
    while ( !feof(fpIn) )
    {
        ch = fgetc(fpIn);
        if( ch == EOF || ch == '\n' )
        {
            break;
        }
        count++;
        printf("character count: %d\n", count);
    }
    *c = count;
    printf("character count: %d\n", *c);
    fclose(fpIn);

    return 0;
}

int reverseText(char fileIn[], char fileOut[], int count, char *reverse)
{
    FILE *fpIn;
    FILE *fpOut;
    
    if (!(reverse = (char *)malloc(count*sizeof(char)))){
        printf("Out of memory\n");
        fprintf(stderr," error:%d: %s\n", errno, strerror(errno));
        exit(1); 
    }

    if ((fpIn = fopen(fileIn, "r")) == NULL)
    {
        printf("Unable to read file\n");
        fprintf(stderr," error:%d: %s\n", errno, strerror(errno));
        exit(1);
    }
    
    fgets(reverse, count, fpIn);
    strrev(reverse);
    printf("Reversed characters: %s\n",&reverse);
    fclose(fpIn);
    

    return 0;
}




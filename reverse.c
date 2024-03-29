#include <reverse.h>

/*Question 2

swap each char to reverse string*/
extern char *reverseStr(char *str)
{

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

/*gets the number of characters in the first line of a file*/
extern int getCount(char fileIn[])
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
    fclose(fpIn);
    return count;
}

/*gets the first line and reverses it*/
extern int reverseText(char fileIn[], int count, char **reverse)
{
    FILE *fpIn;

    /*assign and check memory for an array that is the size of the characters in the first line*/
    if (!(*reverse = (char *)malloc(count*sizeof(char)))){
        fprintf(stderr,"Out of memory\n");
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

/*writes the reversed line to file*/
extern int writeText(char fileOut[], char reverse[])
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


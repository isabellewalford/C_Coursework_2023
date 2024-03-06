#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>

typedef void * msString;

msString  msSetString     (char *);
char     *msGetString     (msString);

/*
extern void      msCopy          (msString *, msString);
extern void      msConcatenate   (msString *, msString);
extern long int  msLength        (msString);
extern int       msCompare       (msString, msString);
extern int       msCompareString (msString, char *);
static void      msError         (char *);
*/

struct msString
{
    long int length;
    char *str;
};

int main()
{
    msString ms = msSetString (" Hello ");
    msString ms2 = msSetString (" World !");
    printf("ms set as %s\n", msGetString(ms));

}

msString msSetString(char *str)
{
    struct msString *string = (struct msString *)malloc(sizeof(struct msString));
    if (string == NULL){
        printf("Out of memory\n");
        fprintf(stderr," error:%d: %s\n", errno, strerror(errno));
        exit(1); 
    }

    string->length = strlen(str);

    if (!(string->str = (char *)malloc(string->length*sizeof(char)))){
        printf("Out of memory\n");
        fprintf(stderr," error:%d: %s\n", errno, strerror(errno));
        free(string);
        exit(1); 
    }

    string->str = str;
    return (msString)(string);
}

char *msGetString(msString msStr)
{
    struct msString *string = (struct msString *)msStr;
    return string->str;
}

/*

extern void      msCopy          (msString *, msString);
extern void      msConcatenate   (msString *, msString);
extern long int  msLength        (msString);
extern int       msCompare       (msString, msString);
extern int       msCompareString (msString, char *);
static void      msError         (char *);
*/
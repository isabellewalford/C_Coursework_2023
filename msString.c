#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>

typedef void * msString;

msString  msSetString     (char *);

/*
char     *msGetString     (msString);
void      msCopy          (msString *, msString);

extern void      msConcatenate   (msString *, msString);
extern long int  msLength        (msString);
extern int       msCompare       (msString, msString);
extern int       msCompareString (msString, char *);
static void      msError         (char *);
*/

struct msString
{
    long int length;
    char *chars;
};

int main()
{
    msString ms = msSetString (" Hello ");
    msString ms2 = msSetString (" World !");

}

msString msSetString(char *str)
{
    int i;
    struct msString *msStruct = (struct msString *)malloc(sizeof(struct msString));
    if (msStruct == NULL){
        printf("Out of memory\n");
        fprintf(stderr," error:%d: %s\n", errno, strerror(errno));
        exit(1); 
    }

    msStruct->length = strlen(str);

    if (!(msStruct->chars = (char *)malloc(msStruct->length*sizeof(char)))){
        printf("Out of memory\n");
        fprintf(stderr," error:%d: %s\n", errno, strerror(errno));
        free(msStruct);
        exit(1); 
    }

    memcpy(msStruct->chars,str,msStruct->length);
    printf("set\n");

    return (msString)(msStruct);
}





/*

char *msGetString(msString msStr)
{
    struct msString *msStruct = (struct msString *)msStr;
    char *str;
    long int length = msStruct->length;

    if (!(str = (char *)malloc((length + 1)*sizeof(char)))){
        printf("Out of memory\n");
        fprintf(stderr," error:%d: %s\n", errno, strerror(errno));
        exit(1); 
    }
    memcpy(str,msStruct->chars,length);
    str[length] = '\0';

    return str;
}

extern void      msCopy          (msString *, msString);
extern void      msConcatenate   (msString *, msString);
extern long int  msLength        (msString);
extern int       msCompare       (msString, msString);
extern int       msCompareString (msString, char *);
static void      msError         (char *);
*/
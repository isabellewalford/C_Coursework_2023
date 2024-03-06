#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>

typedef void * msString;

extern msString  msSetString     (char *);
/*
extern char     *msGetString     (msString);
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
    
    prinf("set ms as:\nlength: %ld\nstr: %s\n",ms->length, ms->str);
    msString ms2 = msSetString (" World !");
    prinf("set ms2 as:\nlength: %ld\nstr: %s\n",ms2->length, ms2->str);

}

extern msString msSetString(char *str)
{
    if (!(struct msString *msStr = (struct msString *)malloc(sizeof(struct msString)))){
        printf("Out of memory\n");
        fprintf(stderr," error:%d: %s\n", errno, strerror(errno));
        exit(1); 
    }

    msStr->length = strlen(str);

    if (!(msStr->str = (char *)malloc(msStr->length*sizeof(char)))){
        printf("Out of memory\n");
        fprintf(stderr," error:%d: %s\n", errno, strerror(errno));
        free(msStr);
        exit(1); 
    }

    msStr->str = str;
    return msStr;
}


/*
extern char     *msGetString     (msString);
extern void      msCopy          (msString *, msString);
extern void      msConcatenate   (msString *, msString);
extern long int  msLength        (msString);
extern int       msCompare       (msString, msString);
extern int       msCompareString (msString, char *);
static void      msError         (char *);
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void * msString;

msString  msSetString     (char *);
char     *msGetString     (msString);
void      msCopy          (msString *, msString);
void      msConcatenate   (msString *, msString);
long int  msLength        (msString);
int       msCompare       (msString, msString);
int       msCompareString (msString, char *);
static void      msError         (char *);


struct msString
{
    long int length;
    char *chars;
};

int main()
{
    msString ms = msSetString("Hello");
    msString ms2 = msSetString(" World!");
    msString mscopy = NULL ;
    int i;
    char *str = NULL;

    /* msGetString requires the user to free the memory after */
    str = msGetString(ms);
    printf("String |%s| is % ld characters long (%p).\n",str, msLength(ms), ms);
    free(str);
    msCopy(&mscopy , ms);
    str = msGetString(mscopy);
    printf("Copied string |%s| is % ld characters long (%p).\n" ,str, msLength(mscopy), mscopy);
    free(str);
    
    printf("Compare ms with mscopy : %d\n", msCompare(ms, mscopy));
    printf("Compare ms with ms2 : %d\n", msCompare(ms, ms2));
    printf("Compare ms with Hello : % d\n", msCompareString(ms,"Hello"));
    printf("Compare ms with HelloX : %d\n", msCompareString(ms,"HelloX"));
    printf("Compare ms with Hella : %d\n", msCompareString(ms,"Hella"));
    msConcatenate(&mscopy, ms2);

    str = msGetString(mscopy);
    printf("Concatenated string |%s| is %ld characters long (%p).\n" ,str, msLength(mscopy), mscopy);
    free(str);

    /*
    msStrings memory must be freed after msSetString or msCopy is called.
    a delete function to free the memory used by the structure would be useful
    */
    struct msString *msS = (struct msString *)ms;
    struct msString *ms2S = (struct msString *)ms2;
    struct msString *mscopyS = (struct msString *)mscopy;

    free(msS->chars);
    free(msS);
    free(ms2S->chars);
    free(ms2S);
    free(mscopyS->chars);
    free(mscopyS);
}


msString msSetString(char *str)
{
    if(str == NULL || strlen(str)== 0)
    {
        msError("cannot set an empty string\n");
    }
    int i;
    struct msString *msStruct = (struct msString *)malloc(sizeof(struct msString));
    if (msStruct == NULL){
        msError("Out of memory\n"); 

    }

    msStruct->length = strlen(str);

    if (!(msStruct->chars = (char *)malloc(msStruct->length*sizeof(char)))){
        msError("Out of memory\n"); 

    }

    memcpy(msStruct->chars,str,msStruct->length);
    return (msString)(msStruct);
}


char *msGetString(msString msStr)
{
    struct msString *msStruct = (struct msString *)msStr;
    char *str;
    long int length = msStruct->length;

    if (!(str = (char *)malloc((length + 1)*sizeof(char)))){
        msError("Out of memory\n"); 
    }
    memcpy(str,msStruct->chars,length);
    str[length] = '\0';

    return str;
}

void msCopy(msString *copiedStr, msString msStr)
{
    struct msString *msStruct = (struct msString *)msStr;
    struct msString *copiedStruct = (struct msString *)*copiedStr;

    copiedStruct = (struct msString *)malloc(sizeof(struct msString));
    if (msStruct == NULL){
        msError("Out of memory\n"); 
    }
    copiedStruct->length = msStruct->length;
    if (!(copiedStruct->chars = (char *)malloc(msStruct->length*sizeof(char)))){
        msError("Out of memory\n"); 
    }
    memcpy(copiedStruct->chars,msStruct->chars,msStruct->length);
    *copiedStr = (msString)copiedStruct;

}

void msConcatenate(msString *msStr, msString addedStr)
{
    if(msStr == NULL || addedStr == NULL)
    {
        msError("null pointer passed to function\n");
    }
    struct msString *msStruct = (struct msString *)*msStr;
    struct msString *addedStruct = (struct msString *)addedStr;
    int i;
    int j = 0;

    long int newLength = msStruct->length+addedStruct->length;
    if (!(msStruct->chars = realloc(msStruct->chars, (newLength*sizeof(char)))))
    {
        msError("Out of memory\n"); 
    }

    for (i = msStruct->length; i < newLength;i++)
    {
        msStruct->chars[i]= addedStruct->chars[j];
        j++;
    }
    msStruct->length = newLength;


}

long int msLength(msString msStr)
{
    struct msString *msStruct = (struct msString *)msStr;
    return msStruct->length;
}

int msCompare(msString firStr, msString secStr)
{
    int i;
    if(firStr == NULL || secStr == NULL)
    {
        msError("null pointer passed to function\n");
    }
    struct msString *firStruct = (struct msString *)firStr;
    struct msString *secStruct = (struct msString *)secStr;
    if (firStruct->length==secStruct->length)
    {
        i = memcmp(firStruct->chars, secStruct->chars,firStruct->length);
        if (i==0)
        {return 0;}
        else
        {return 1;}
    }
    else
    {return 1;}
}

int msCompareString(msString msStr, char *str)
{
    int i;
    if(msStr == NULL || str == NULL)
    {
        msError("null pointer passed to function\n");
    }
    struct msString *msStruct = (struct msString *)msStr;
    if (msStruct->length==strlen(str))
    {
        i = memcmp(msStruct->chars, str, msStruct->length);
        if (i==0)
        {return 0;}
        else
        {return 1;}
    }
    else
    {return 1;}
}

static void msError(char *message)
{
    fprintf(stderr,"%s",message);
    exit(1);
}
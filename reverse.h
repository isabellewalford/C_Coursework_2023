#ifndef __REVERSE__
#define __REVERSE__

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

extern char *reverseStr (char *);
extern int  getCount    (char []);
extern int  reverseText (char [], int, char **);
extern int  writeText   (char[], char[]);

#endif
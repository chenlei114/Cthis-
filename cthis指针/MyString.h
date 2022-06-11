#ifndef STRING_H
#define STRING_H

#include "stdio.h"
#include "string.h"
#include "malloc.h"

#include "This.h"


typedef struct String{
    char*   str;
    int     length;

    struct String* (*setThis)(struct String* string);
    int     (*indexOf)(struct String* T);
    boolean (*equals) (struct String* T);
}*String;

String createString(char* str);

#endif 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readfile.h"

FILE *open_file(char *filename, char *mode)
{
    fptr = fopen(filename, "r");
    if (fptr == NULL) 
    {
        printf("Error opening file");
        //retirn error,
    }

    else
    {
        return fptr;
        //return error
    }
}

void close_file(FILE *ft)
{
    fclose(ft);
}

void read_int(char *filename)
{
    //Coming soon!
}

void read_string(char *filename)
{
    //Coming soon!
}


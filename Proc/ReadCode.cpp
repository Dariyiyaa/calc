#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "error.h"
#include "header.h"


int SizeofFile(const char *const file_ptr)
{
    struct stat buff;
    stat(file_ptr, &buff);

    return buff.st_size;
}

errorReturn ReadCode(struct File* code_file, struct Processor* proc)
{
    if(code_file -> ptr == NULL)
    {
        CREATE_RETURNING_VALUE(NullFilePointer)
    }

    if(proc -> code == NULL)
    {
        CREATE_RETURNING_VALUE(NullDataPointer)
    }

    proc -> size_of_code = SizeofFile(code_file -> name)/sizeof(int);

    if( proc -> size_of_code == 0)
    {
        CREATE_RETURNING_VALUE(EmptyFile)
    }
    
    int* proc_code_ptr = (int*)calloc(proc -> size_of_code, sizeof(int));

    if(proc_code_ptr == NULL)
    {
        CREATE_RETURNING_VALUE(NullDataPointer)
    }

    proc -> code = proc_code_ptr;

    fread(proc -> code, sizeof(int), proc -> size_of_code, code_file -> ptr);
}
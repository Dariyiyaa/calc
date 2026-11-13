#include "stdio.h"
#include <stdlib.h>
#include "error.h"
#include "ComandCode.h"


#define INIT_SIZE 64



errorReturn LogCommandToDump(struct Compile* Comp, struct Comand* cmp);
errorReturn WriteInLableArr(struct Compile* Comp, const char* command);
errorReturn WriteFromLableArr(int* lable_ptr, char* value, char* lable, size_t lable_size);



struct Comand
{
    enum ProcessorCommand code_command;
    const char* name_command = 0;
    int code_value = 0;
    char* value = 0;
    int arg_matched = 0;
};



struct File
{
    FILE* ptr;
    const char* name;
};



struct Compile
{
    int pc = 0;
    int* lable_ptr = (int*)calloc(INIT_SIZE, sizeof(int));
    struct File input  = {};
    struct File output = {};
    struct File debug  = {};
};
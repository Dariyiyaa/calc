#include <stdio.h>
#include "header.h"
#include "stack.h"

#define CAPACITY 5

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        fprintf(stdout, "Wrong input data\n");
        return 1;
    }

    FILE* byte_code_ptr = fopen(argv[1], "rb");

    struct File byte_code_file = {byte_code_ptr, argv[1]};

    struct Processor proc = {};

    ReadCode(&byte_code_file, &proc);
    
    struct Stack_t stk = {};

    StackInit(&stk, CAPACITY);

    ExecuteCode(&proc);
}
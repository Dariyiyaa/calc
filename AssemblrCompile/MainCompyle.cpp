#include <stdio.h>
#include "Hash.h"
#include "header.h"
#include "mainHeader.h"

//TO DO hash table -> switch -> bytecode

int main(int argc, char* argv[])
{  
    if(argc != 3)
    {
        printf("Wrong input data in main");
        return 1;
    }

    FILE* asmblr_file_ptr = fopen(argv[1], "r");

    FILE* code_file_ptr = fopen(argv[2], "wb");

    struct File inputFile{asmblr_file_ptr, argv[1]};
    struct File outputFile{code_file_ptr, argv[2]};
    

    CompileAsmblr(&inputFile, &outputFile);

    fclose(asmblr_file_ptr);
    fclose(code_file_ptr);

    return 0;
}
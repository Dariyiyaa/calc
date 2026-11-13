#include <stdio.h>
#include "Hash.h"
#include "header.h"
#include "mainHeader.h"
#include <assert.h>

#define DEBUG

int main(int argc, char* argv[])
{  
    
    if(argc != 4)
    {
        fprintf(stdout, "Wrong input data in main\n");
        return 1;
    }


    FILE* asmblr_file_ptr = fopen(argv[1], "r");
    assert(asmblr_file_ptr);

    FILE* code_file_ptr = fopen(argv[2], "wb");
    assert(code_file_ptr);

    struct Compile Comp = {};

    Comp.input.ptr  = asmblr_file_ptr;
    Comp.input.name = argv[1];

    Comp.output.ptr  = code_file_ptr;
    Comp.output.name = argv[2];

    #ifdef DEBUG

    FILE* debug_file_ptr = fopen(argv[3], "w");
    assert(debug_file_ptr);

    Comp.debug.ptr = debug_file_ptr;
    Comp.debug.name = argv[3];

    WriteDumpHeader(&Comp);

    #endif

    struct errorReturn ret_val = {};
    
    FILE* trash_file = fopen("NUL", "w");
    
    Comp.output.ptr = trash_file;
    Comp.debug.ptr = trash_file;

    ReturnValueCheck(&(ret_val = CompileAsmblr(&Comp)));
    fseek(Comp.input.ptr, 0, SEEK_SET);

    Comp.output.ptr = code_file_ptr;
    Comp.debug.ptr = debug_file_ptr;
    Comp.pc = 0;
    
    ReturnValueCheck(&(ret_val = CompileAsmblr(&Comp)));

    fclose(asmblr_file_ptr);
    fclose(code_file_ptr);
    fclose(debug_file_ptr);
    fclose(trash_file);

    return 0;
}
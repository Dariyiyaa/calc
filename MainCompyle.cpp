#include <stdio.h>
#include <assert.h>
#include "ReadFile.cpp"
#include "CompileAs.cpp"
#include "stackCommands.cpp"


int main(int argc, char* argv[])
{
    if (argc != 3)
    {
       fprintf(stderr, "argc != 3\n"); 
       return 0;
    }

    char* file_output_name = argv[2];

    assert(file_output_name);

    FILE* file_output_ptr = fopen(file_output_name, "w");


    char* file_input_name = argv[1];

    assert(file_input_name);

    FILE* file_input_ptr = fopen(file_input_name, "r");


    size_t nchar = IndexCount(file_input_name);

    char*  text  = (char*)calloc(nchar, sizeof(char));
    char** lines_ptr = (char**)calloc(nchar, sizeof(char*));

    int nlines = ReadFile(file_input_ptr, text, lines_ptr);

    for(int i = 0; i < nlines; i++)
    {
        CompileAsmblr(file_output_ptr, lines_ptr[i]);
    }

    fclose(file_input_ptr);
    fclose(file_output_ptr);
    free(text);
    free(lines_ptr);

    return 0;
}
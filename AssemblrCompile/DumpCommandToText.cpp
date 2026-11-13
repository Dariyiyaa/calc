#include <stdio.h>
#include <stdint.h>
#include <error.h>
#include "header.h"
#include "ComandCode.h"


void ByteToBinStr(int byte, char *out_str, int byte_count);
errorReturn WriteDumpHeader(struct Compile* Comp);


void ByteToBinStr(int byte, char *out_str, int byte_count)
{
    for (int i = byte_count - 1; i >= 0; i--)
    {
        out_str[byte_count - 1 - i] = ((byte >> i) & 1) ? '1' : '0';
        
        // snprintf(out_str, out_str_size, "%b", byte);
    }
}


errorReturn WriteDumpHeader(struct Compile* Comp)
{
    if(Comp -> debug.ptr == NULL)
    {
        CREATE_RETURNING_VALUE(NullDataPointer)
    }

    fprintf(Comp -> debug.ptr, "+-+-- PROCESSOR PROGRAM DEBUG DUMP --+-+ <3\n");
    fprintf(Comp -> debug.ptr, "From file: %s\n", Comp -> input.name);
    fprintf(Comp->debug.ptr, "PC  | BIN CODE | BIN ARG  | NAME | ARG  |\n");
    fprintf(Comp->debug.ptr, "----+----------+----------+------+------+\n");

    fflush(Comp -> debug.ptr);

    CREATE_RETURNING_VALUE(Success)
}


errorReturn LogCommandToDump(struct Compile* Comp, struct Comand* cmd)
{
    if (Comp -> debug.ptr == NULL)
    {
        CREATE_RETURNING_VALUE(NullFilePointer)
    }

    char cmd_byte_code[33] = {};
    ByteToBinStr(cmd -> code_command, cmd_byte_code, 8);

    if(cmd -> arg_matched == 1)
    {
        fprintf(Comp -> debug.ptr, "%-3d | %-8s | %-8d | %-4s | %-4s |\n", 
            Comp -> pc, 
            cmd_byte_code, 
            0x000, 
            cmd -> name_command, 
            " "
        );
    }

    if(cmd -> arg_matched == 2)
    {
        char val_byte_code[33] = {};
        ByteToBinStr(cmd -> code_value, val_byte_code, 8);

        fprintf(Comp -> debug.ptr, "%-3d | %-8s | %-8s | %-4s | %-4s |\n", 
            Comp -> pc, 
            cmd_byte_code, 
            val_byte_code, 
            cmd -> name_command, 
            cmd -> value
        );
    }

    CREATE_RETURNING_VALUE(Success)

}
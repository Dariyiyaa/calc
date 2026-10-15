#include <stdio.h>
#include <string.h>
#include "C:\Users\Daryia\DED\stack\Stack_t\StackInit.cpp"
#include "PrintFile.cpp"

#define MAXLINE 64

errorReturn CompileAsmblr(FILE* file_output_ptr, char* lines_ptr);
int my_strcat(char* string_ptr1, char* string_ptr2);


int my_strcat(char* string_ptr1, char* string_ptr2)
{
    while(*string_ptr1 != '\0')
    {
        string_ptr1++;
    }

    *string_ptr1++ = ' ';

    while(*string_ptr2 != '\0')
    {
        *string_ptr1 = *string_ptr2;
        string_ptr1++;
        string_ptr2++;
    }

    return 0;
}


errorReturn CompileAsmblr(FILE* file_output_ptr, char* lines_ptr)
{
    char line_asmblr[MAXLINE] = {};
    char value[MAXLINE] = {}; 
    
    int ret = sscanf(lines_ptr, "%s %s", line_asmblr, value);

    if(ret == 0)
    {
        CREATE_RETURNING_VALUE(WrongDataFile)
    }

    if(ret == 1)
    {
        if(strcmp(line_asmblr, "ADD") == 0)
        {
            char line_byte[] = "1";
            PrintString(file_output_ptr, line_byte);
        }

        if(strcmp(line_asmblr, "SUB") == 0)
        {
            char line_byte[] = "2";
            PrintString(file_output_ptr, line_byte);
        }

        if(strcmp(line_asmblr, "DIV") == 0)
        {
            char line_byte[] = "3";
            PrintString(file_output_ptr, line_byte);
        }

        if(strcmp(line_asmblr, "POP") == 0)
        {
            char line_byte[] = "4";
            my_strcat(line_byte, value);
            PrintString(file_output_ptr, line_byte);
        }

        if(strcmp(line_asmblr, "OUT") == 0)
        {
            char line_byte[] = "5";
            my_strcat(line_byte, value);
            PrintString(file_output_ptr, line_byte);

        }

        if(strcmp(line_asmblr, "HLT") == 0)
        {
            char line_byte[] = "6";
            my_strcat(line_byte, value);
            PrintString(file_output_ptr, line_byte);

        }
    }

    if(ret == 2)
    {
        if(strcmp(line_asmblr, "PUSH") == 0)
        {
            if(value == "AX")
            {
                char line_byte[] = "7";
                my_strcat(line_byte, value);
                PrintString(file_output_ptr, line_byte);
            }

            else
            {
                char line_byte[] = "8";
                my_strcat(line_byte, value);
                PrintString(file_output_ptr, line_byte);
            }

        }

        if(strcmp(line_asmblr, "POP") == 0)
        {
            char line_byte[] = "9";
            my_strcat(line_byte, value);
            PrintString(file_output_ptr, line_byte);
        }

        if(strcmp(line_asmblr, "JMP") == 0)
        {
            char line_byte[] = "10";
            my_strcat(line_byte, value);
            PrintString(file_output_ptr, line_byte);
        }

        if(strcmp(line_asmblr, "JA") == 0)
        {
            char line_byte[] = "11";
            my_strcat(line_byte, value);
            PrintString(file_output_ptr, line_byte);
        }

        if(strcmp(line_asmblr, "JAE") == 0)
        {
            char line_byte[] = "12";
            my_strcat(line_byte, value);
            PrintString(file_output_ptr, line_byte);
        }

        if(strcmp(line_asmblr, "JB") == 0)
        {
            char line_byte[] = "13";
            my_strcat(line_byte, value);
            PrintString(file_output_ptr, line_byte);
        }

        if(strcmp(line_asmblr, "JBE") == 0)
        {
            char line_byte[] = "14";
            my_strcat(line_byte, value);
            PrintString(file_output_ptr, line_byte);
        }

        if(strcmp(line_asmblr, "JE") == 0)
        {
            char line_byte[] = "15";
            my_strcat(line_byte, value);
            PrintString(file_output_ptr, line_byte);
        }

        if(strcmp(line_asmblr, "JNE") == 0)
        {
            char line_byte[] = "16";
            my_strcat(line_byte, value);
            PrintString(file_output_ptr, line_byte);
        }
    }

    CREATE_RETURNING_VALUE(Success)
}
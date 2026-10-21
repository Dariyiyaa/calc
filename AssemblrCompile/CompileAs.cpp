#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "C:\Users\Daryia\DED\stack\Stack_t\error.h"
#include "Hash.h"
#include "ComandCode.h"
#include "Print.cpp"

#define MAXLINE 64

errorReturn PrintInFileCode(FILE* output_ptr, enum ProcessorCommand command, char* value);
errorReturn CompileAsmblr(struct File* input, struct File* output);
unsigned long long HashDjb(const char* command);

unsigned long long HashDjb(const char* command)
{
    unsigned long long hash = 5381;
    int c = 0;
    while ((c = *command++) != '\0')
    {
        hash = (hash << 5) + hash + c;
    }

    return hash;
}

errorReturn PrintInFileCode(FILE* output_ptr, enum ProcessorCommand command, char* value)
{
    fwrite(&command, sizeof(uint8_t), 1, output_ptr);
    fwrite(value, sizeof(uint8_t), 1, output_ptr);

    CREATE_RETURNING_VALUE(Success)
}

errorReturn CompileAsmblr(struct File* input, struct File* output)
{
    char buf[2*MAXLINE] = {};

    while (fgets(buf, sizeof(buf), input -> ptr))
    {
        char command[MAXLINE] = {};
        char value[MAXLINE] = {};

        int arg_matched = sscanf(buf, "%s %s", command, value);

        if (arg_matched == 0)
        {
            CREATE_RETURNING_VALUE(ArgumentsHasntMatched)    
        }

        unsigned long long hash_command = HashDjb(command);

        if (arg_matched == 1)
        {
            switch (hash_command)
            {
                case hshHLT:
                    PrintInFileCode(output -> ptr, pcHLT, value);
                    break;
                
                case hshADD:
                    PrintInFileCode(output -> ptr, pcADD, value);
                    break;
                
                case hshSUB:
                    PrintInFileCode(output -> ptr, pcSUB, value);
                    break;
                
                case hshDIV:
                    PrintInFileCode(output -> ptr, pcDIV, value);
                    break;

                case hshMUL:
                    PrintInFileCode(output -> ptr, pcMUL, value);
                    break;

                case hshOUT:
                    PrintInFileCode(output -> ptr, pcOUT, value);
                    break;

                default: 
                    CREATE_RETURNING_VALUE(WrongInput)
            }
        }


        // if (arg_matched == 2)
        // {
        //     switch(hash_command)
        //     {
        //         case hshPUSH:
        //             if (strcmp(value, "CX"))
        //             {
        //                 PrintInFileCode()
        //                 break;
        //             }
                
        //         case hshPOP:
        //             PrintInFileCode()
        //             break;
                
        //         default:
        //             CREATE_RETURNING_VALUE(WrongInput)
        //     }
        // }
    }
    CREATE_RETURNING_VALUE(Success)
}
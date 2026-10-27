#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#include "Hash.h"
#include "ComandCode.h"
#include "C:\Users\Daryia\DED\stack\Stack_t\error.h"
#include "header.h"


errorReturn PrintInFileCode(FILE* output_ptr, enum ProcessorCommand command, char* value);
errorReturn CompileAsmblr(struct File* input, struct File* output);
void WriteToFile(FILE* file, uint32_t value);

#define MAXLINE 128

errorReturn CompileAsmblr(struct File* input, struct File* output)
{
    // putchar('\n');

    if (input -> ptr == NULL)
    {
        // putchar('\n');
        CREATE_RETURNING_VALUE(NullDataPointer)
    }

    char buf[MAXLINE] = {};
    
    // putchar('\n');
    
    while (fgets(buf, sizeof(buf), input -> ptr))
    {
        putchar('\n');
        char command[MAXLINE] = {};
        char value[MAXLINE] = {};

        int arg_matched = sscanf(buf, "%s %s", command, value);

        if (arg_matched == 0)
        {
            // putchar('\n');
            CREATE_RETURNING_VALUE(ArgumentsHasntMatched)    
        }

        unsigned int hash_command = HashDjb2(command);

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
                    CREATE_RETURNING_VALUE(ArgumentsHasntMatched)
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




errorReturn PrintInFileCode(FILE* output_ptr, enum ProcessorCommand command, char* value)
{
    if (output_ptr == NULL)
    {
        CREATE_RETURNING_VALUE(NullFilePointer)
    }

    fwrite(&command, sizeof(uint8_t), 4, output_ptr);

    if (value == NULL)
    {
        CREATE_RETURNING_VALUE(NullDataPointer)
    }

    if (value[0] != '\0')
    {
        int val_num = 0;

        if (sscanf(value, "%d", &val_num) == 1) 
        {
            fwrite(&val_num, sizeof(uint8_t), 4, output_ptr); 
        }
    }

    CREATE_RETURNING_VALUE(Success)
}
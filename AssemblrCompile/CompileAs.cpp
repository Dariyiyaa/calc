#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>

#include "Hash.h"
#include "ComandCode.h"
#include "error.h"
#include "header.h"


errorReturn PrintInFileCode(struct Compile* Comp, struct Comand* cmd, char* value);
errorReturn CompileAsmblr(struct Compile* Comp);
int         ValueIsReg(char* value);


#define MAXLINE 128


errorReturn CompileAsmblr(struct Compile* Comp)
{
    if ((Comp -> input).ptr == NULL)
    {
        
        CREATE_RETURNING_VALUE(NullDataPointer)
    }

    char buf[MAXLINE] = {};
    
    
    while (fgets(buf, sizeof(buf), (Comp -> input).ptr))
    {
        putchar('\n');
        char command[MAXLINE] = {};
        char value[MAXLINE] = {};

        int arg_matched = sscanf(buf, "%s %s", command, value);

        if (arg_matched <= 0)
        {   
            continue;
        }
        
        unsigned int hash_command = HashDjb2(command);

        if (arg_matched == 1)
        {
            if(command[0] == ':')
            {
                WriteInLableArr(Comp, command);
                continue;
            }

            switch (hash_command)
            {
                case hshHLT:
                {
                    Comp -> pc += 1; 

                    struct Comand HLT = {pcHLT, "HLT", 0, value, 1};

                    PrintInFileCode(Comp, &HLT, value);
                    
                    break;
                }

                case hshADD:
                {
                    Comp -> pc += 1; 

                    struct Comand ADD = {pcADD, "ADD", 0, value, 1};

                    PrintInFileCode(Comp, &ADD, value);
                    
                    break;
                }
                
                case hshSUB:
                {
                    Comp -> pc += 1;

                    struct Comand SUB = {pcSUB, "SUB", 0, value, 1};

                    PrintInFileCode(Comp, &SUB, value);
                    break;
                }

                case hshDIV:
                {
                    Comp -> pc += 1;
                    
                    struct Comand DIV = {pcDIV, "DIV", 0, value, 1};

                    PrintInFileCode(Comp, &DIV, value);
                    break;  
                }

                case hshMUL:
                {
                    Comp -> pc += 1;

                    struct Comand MUL = {pcMUL, "MUL", 0, value, 1};
                    
                    PrintInFileCode(Comp, &MUL, value);
                    break;
                }

                case hshOUT:
                {
                    Comp -> pc += 1;
                    
                    struct Comand OUT = {pcOUT, "OUT", 0, value, 1};

                    PrintInFileCode(Comp, &OUT, value);
                    break;
                }

                default: 
                    CREATE_RETURNING_VALUE(CommandHasntMatched)
            }
        }


        if (arg_matched == 2)
        {
            int reg = xEMPTY;
            int consta = 0;

            switch(hash_command)
            {
                case hshPUSH:
                    Comp -> pc += 1;
                    if (sscanf(value, "%d", &consta) == 1)
                    {
                        struct Comand PUSHc = {pcPUSHc, "PUSH", 0, value, 2};

                        PrintInFileCode(Comp, &PUSHc, value);
                    }
                    
                    else if(value[0] == '[')
                    {
                        char inside_value[MAXLINE] = {};
                        int j = 0;
                        for (int i = 1; value[i] && value[i] != ']' && j < MAXLINE - 1; ++i)
                        {
                            inside_value[j++] = value[i];
                        }
                        
                        struct Comand PUSHm = {pcPUSHm, "PUSH", 0, value, 2};

                        PrintInFileCode(Comp, &PUSHm, inside_value);
                    }

                    else if((reg = ValueIsReg(value)) != xEMPTY)
                    {
                        struct Comand PUSHr = {pcPUSHr, "PUSH", 0, value, 2};

                        PrintInFileCode(Comp, &PUSHr, value);
                    }
                    
                    else
                    {
                        CREATE_RETURNING_VALUE(ValueHasntMatched)
                    }
                    
                    break;

                case hshPOP:
                    Comp -> pc += 1;
                    if (sscanf(value, "%d", &consta) == 1)
                    {
                        struct Comand POPc = {pcPOPc, "POP", 0, value, 2};

                        PrintInFileCode(Comp, &POPc, value);
                    }
                    
                    else if(value[0] == '[')
                    {
                        char inside_value[MAXLINE] = {};
                        int j = 0;
                        for (int i = 1; value[i] && value[i] != ']' && j < MAXLINE - 1; ++i)
                        {
                            inside_value[j++] = value[i];
                        }

                        struct Comand POPm = {pcPOPm, "POP", 0, inside_value, 2};

                        PrintInFileCode(Comp, &POPm, inside_value);
                    }

                    else if((reg = ValueIsReg(value)) != xEMPTY)
                    {
                        struct Comand POPr = {pcPOPr, "POP", 0, value, 2};

                        PrintInFileCode(Comp, &POPr, value);
                    }
                    
                    else
                    {
                        CREATE_RETURNING_VALUE(ValueHasntMatched)
                    }

                    break;

                case hshJMP:
                    Comp -> pc += 1;
                    {
                        char lable_buf[32] = {};
                        WriteFromLableArr(Comp->lable_ptr, value, lable_buf, sizeof(lable_buf));

                        struct Comand JMP = {pcJMP, "JMP", 0, lable_buf, 2};
                        PrintInFileCode(Comp, &JMP, lable_buf);
                    }
                    break;
                
                default:
                    CREATE_RETURNING_VALUE(CommandHasntMatched)
            }
        }
    }

    CREATE_RETURNING_VALUE(Success)
}


errorReturn PrintInFileCode(struct Compile* Comp, struct Comand* cmd, char* value)
{
    if (Comp -> output.ptr == NULL)
    {
        CREATE_RETURNING_VALUE(NullFilePointer)
    }


    if (value == NULL)
    {
        CREATE_RETURNING_VALUE(NullDataPointer)
    }

    if (value[0] != '\0')
    {
        
        int code = (int)cmd->code_command;
        fwrite(&code, sizeof(int), 1, Comp -> output.ptr);

        //check if const
        int val_num = 0;

        if (sscanf(value, "%d", &val_num) == 1) 
        {
            fwrite(&val_num, sizeof(int), 1, Comp -> output.ptr);

            cmd -> code_value = val_num;
            LogCommandToDump(Comp, cmd);

            // LogCommandToDump();
        }

        //check if reg
        int reg = xEMPTY;

        if((reg = ValueIsReg(value)) != xEMPTY)
        {
            fwrite(&reg, sizeof(int), 1, Comp -> output.ptr);
            
            cmd -> code_value = reg;
            LogCommandToDump(Comp, cmd);
        }
    }

    else
    {  
        int code = (int)cmd->code_command;
        fwrite(&code, sizeof(int), 1, Comp->output.ptr);
        LogCommandToDump(Comp, cmd);
    }

    CREATE_RETURNING_VALUE(Success)
}


int  ValueIsReg(char* value)
{
    const char* RegsNames[] =
    {
        "AX",   "BX",   "CX",   "DX",
        "EX",   "FX",   "GX",   "HX",
        "IX",   "JX",   "KX",   "LX",
        "MX",   "NX",   "OX",   "PX",
    };

    for(int i = 0; i < 16; i++)
    {
        if(strcmp(RegsNames[i], value) == 0)
        {
            return i + 1;
        }
    }

    return xEMPTY;
}
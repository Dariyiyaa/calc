#include <stdio.h>
#include "error.h"
#include "header.h"
#include "stack.h"
#include "ComandCode.h"



#define INIT_FUNC(execNAME, op)                                             \
    errorReturn execNAME(struct Processor* proc)                            \
    {                                                                       \                                                    
        double num1 = 0;                                                    \
        double num2 = 0;                                                    \
                                                                            \        
        StackPop(&proc -> stk, &num1);                                      \
        StackPop(&proc -> stk, &num2);                                      \ 
                                                                            \
        double result = num2 op num1;                                       \
                                                                            \
        StackPush(&proc -> stk, result);                                    \
                                                                            \
        CREATE_RETURNING_VALUE(Success)                                     \
    }                                                                       \
\



INIT_FUNC(execADD, +)
INIT_FUNC(execSUB, -)
INIT_FUNC(execMUL, *)
INIT_FUNC(execDIV, /)



errorReturn execHLT(struct Processor* proc)
{
    fprintf(stdout, "The end of code execution\n");
    StackDestroy(&proc -> stk);
    
    CREATE_RETURNING_VALUE(Success)
}




errorReturn execPUSHc(struct Comand* cmdPUCHc, struct Processor* proc)
{
    StackPush(&proc -> stk, cmdPUCHc -> value);

    CREATE_RETURNING_VALUE(Success)
}


errorReturn execPUSHr(struct Comand* cmdPUCHc, struct Processor* proc)
{

}
    



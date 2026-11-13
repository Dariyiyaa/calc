#include <stdio.h>
#include "error.h"
#include "header.h"
#include "ComandCode.h"

errorReturn ExecuteCode(struct Processor* proc)
{
    while(proc -> pc < proc -> size_of_code)
    {
        int opCode = proc -> code[proc -> pc++];

        switch(opCode)
        {
            case(pcHLT):
                execHLT(proc);
                break;
                
            case(pcADD):
                execADD(proc);
                break;
                
            case(pcSUB):
                execSUB(proc);
                break;
            
            case(pcMUL):
                execMUL(proc);
                break;
            
            case(pcDIV):
                execDIV(proc);
                break;
            
            case()
        }
    }
}
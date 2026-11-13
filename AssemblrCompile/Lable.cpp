#include <stdio.h>
#include "error.h"
#include "header.h"

#define SIZE_OF_LABLE_ARR 64



errorReturn WriteInLableArr(struct Compile* Comp, const char* command)
{
    if (Comp -> lable_ptr == NULL)
    {
        CREATE_RETURNING_VALUE(NullDataPointer)
    }

    int lable = 0;
    if(sscanf(command + 1, "%d", &lable) == 1)
    {
        if(lable >= 0 && lable < SIZE_OF_LABLE_ARR)
        {
            (Comp -> lable_ptr)[lable] = Comp -> pc;
        }

        else
        {
            CREATE_RETURNING_VALUE(LableOverflow)
        }
    }
    else
    {
        CREATE_RETURNING_VALUE(LableHasntMatched)
    }

    CREATE_RETURNING_VALUE(Success)
}


errorReturn WriteFromLableArr(int* lable_ptr, char* value, char* lable, size_t lable_size)
{
    if(lable_ptr == NULL || value == NULL || lable == NULL)
    {
        CREATE_RETURNING_VALUE(NullDataPointer)
    }
    
    int lable_num = 0;
    
    if (sscanf(value, "%d", &lable_num) != 1) 
    {
        CREATE_RETURNING_VALUE(ValueHasntMatched)
    }
    
    int lable_adrr = lable_ptr[lable_num];

    snprintf(lable, lable_size, "%d", lable_adrr);

    CREATE_RETURNING_VALUE(Success)
}
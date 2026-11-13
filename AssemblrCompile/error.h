#ifndef ERROR

#define ERROR

#include <stdio.h>
#include "stddef.h"


void ReturnValueCheck(struct errorReturn* ret_val);


#define CREATE_RETURNING_VALUE(errorCode){  \
    struct errorReturn ret_val= {};         \
    ret_val.error = errorCode;              \
    ret_val.line = __LINE__;                \
    ret_val.file_name = __FILE_NAME__;      \
    return ret_val;                         \
                                            \
}


enum Error
{
    //StackErrors

    Success                     =   0,
    NullStackPointer            =   1,
    NullDataPointer             =   2,
    CantAllocateMemory          =   3,
    CapacityIsSmallerThanSize   =   4, 
    NoElementsLeft              =   5,

    //FileErrors


    ArgumentsHasntMatched       =   6,
    CommandHasntMatched         =   7,
    ValueHasntMatched           =   8,
    NullFilePointer             =   9,

    //AssErrors

    LableOverflow               =   10,
    LableHasntMatched           =   11,

};


struct errorReturn
{
    Error error;
    int line;
    const char* file_name;
};

#endif
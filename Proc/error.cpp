#include <stddef.h>
#include <stdio.h>
#include "error.h"


void ReturnValueCheck(struct errorReturn* ret_val)
{
    switch(ret_val -> error)
    {
        case Success:
            break;
        
        case NullStackPointer:
            fprintf(stderr, "Failed to make a pointer at Stack at line %d, in file %s\n", ret_val -> line, ret_val -> file_name);
            break;
        
        case NullDataPointer:
            fprintf(stderr, "Failed to make a pointer at Data at line %d, in file %s\n", ret_val -> line, ret_val -> file_name);
            break;

        case CantAllocateMemory:
            fprintf(stderr, "Failed to allocate memory at line %d, in file %s\n", ret_val -> line, ret_val -> file_name);
            break;
        
        case CapacityIsSmallerThanSize:
            fprintf(stderr, "The Capacity is smaller than the Size at line %d, in file %s\n", ret_val -> line, ret_val -> file_name);
            break;

        case NoElementsLeft:
            fprintf(stderr, "Nothing left to pop at line %d, in file %s\n", ret_val -> line, ret_val -> file_name);
            break;
            
        case  ArgumentsHasntMatched:
            fprintf(stderr, "Wrong input from File at line %d, in file %s\n", ret_val -> line, ret_val -> file_name);
            break;

        case CommandHasntMatched:
            fprintf(stderr, "Wronf =) input of command name at line %d, in file %s\n", ret_val -> line, ret_val -> file_name);
            break;

        case ValueHasntMatched:
            fprintf(stderr, "Wrong input of value at line %d? in file %s\n", ret_val -> line, ret_val -> file_name);
            break;

        case NullFilePointer:
            fprintf(stderr, "Failed to make a pointer at File at line %d, in file %s\n", ret_val -> line, ret_val -> file_name);
            break;

        case LableOverflow:
            fprintf(stderr, "Lable Table has been overflowed at lilne %d,  in file %s\n", ret_val -> line, ret_val -> file_name);
            break;
        
        case LableHasntMatched:
            fprintf(stderr, "Wrong input of lable at lilne %d in file %s\n", ret_val -> line, ret_val -> file_name);
            break;
        
        case EmptyFile:
            fprintf(stderr, "Trying to read an empty file at line %d, in file %s\n", ret_val -> line, ret_val -> file_name);
            break;
        
        default:
            break;
    }

    return;
}
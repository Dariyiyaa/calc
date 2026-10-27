#ifndef HASH_

#define HASH_

#include <stdio.h>
#include <stddef.h>


unsigned int HashDjb2(const char* command);
int CreateHashTable(FILE* ptr);


enum HashCommand
{
    hshHLT        =    47369200,
    hshPUSH       =    1563480936,
    hshPOP        =    47378007,
    hshADD        =    47361297,
    hshSUB        =    47381458,
    hshMUL        =    47374934,
    hshDIV        =    47364747,
    hshOUT        =    47377120,


};





#endif 
#include <stdio.h>
#include <unistd.h>


unsigned int HashDjb2(const char* command);

unsigned int HashDjb2(const char* command)
{
    unsigned int hash = 5381;
    int c = 0;
    while ((c = *command++) != '\0')
    {
        hash = (hash << 5) + hash + c;
    }

    return hash;
}





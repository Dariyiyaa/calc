#include <stdio.h>

int CreateHashTable(FILE* ptr);
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

int CreateHashTable(FILE* ptr)
{
    const char* Commands[] = {
        "hshHLT", 
        "hshPUSH", 
        "hshPOP", 
        "hshADD",
        "hshSUB",
        "hshMUL",
        "hshDIV",
        "hshOUT"
    };

    for (size_t i = 0; i < sizeof(Commands)/sizeof(Commands[0]); i++)
    {
        unsigned long long hash = HashDjb2(Commands[i]);
        fprintf(ptr, "%s        =    %llu,\n", Commands[i], hash);
    }

    return 0;
        
}


int main()
{
    FILE* ptr = fopen("HashCode.txt", "w");

    CreateHashTable(ptr);
}

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
        "HLT", 
        "PUSH", 
        "POP", 
        "ADD",
        "SUB",
        "MUL",
        "DIV",
        "OUT",
        "JMP",
        "JA",
        "JAE",
        "JB",
        "JBE",
        "JE",
        "JNE",
        "CALL",
        "RET",
    };

    for (size_t i = 0; i < sizeof(Commands)/sizeof(Commands[0]); i++)
    {
        int hash = HashDjb2(Commands[i]);
        fprintf(ptr, "hsh%s        =    %d,\n", Commands[i], hash);
    }

    return 0;
        
}


int main()
{
    FILE* ptr = fopen("HashCode.txt", "w");

    CreateHashTable(ptr);
}

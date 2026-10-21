// #include <stdio.h>
// #include <unistd.h>
// // #include "ComandCode.h"


// unsigned long long HashDjb(const char* command);
// int CreateHashTable(FILE* ptr);




// int CreateHashTable(FILE* ptr)
// {
//     const char* Commands[] = {
//         "hshHLT", 
//         "hshPUSH", 
//         "hshPOP", 
//         "hshADD",
//         "hshSUB",
//         "hshMUL",
//         "hshDIV",
//         "hshOUT"
//     };

//     for (size_t i = 0; i < sizeof(Commands)/sizeof(Commands[0]); i++)
//     {
//         unsigned long long hash = HashDjb2(Commands[i]);
//         fprintf(ptr, "%s = %llu,\n", Commands[i], hash);
//     }

//     return 0;
        
// }

// int main()
// {
//     FILE* hash_code_ptr = fopen("HashCodes.txt", "w");

//     CreateHashTable(hash_code_ptr);   

// }


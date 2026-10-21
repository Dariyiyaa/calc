#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE* file_output_ptr = fopen(argv[1], "r");
    
    int* ptr = 0;
    
    ReadCode(&ptr, file_output_ptr);

}
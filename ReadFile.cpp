#include <stdio.h>
#include <sys/stat.h>

int IndexCount(char* file_ptr);
int ReadFile(FILE* file_ptr, char* text, char** lines_ptr);


int IndexCount(char *const file_ptr)
{
    struct stat buff;
    stat(file_ptr, &buff);

    return buff.st_size;
}

int ReadFile(FILE *const file_ptr, char* text_buff, char** lines_ptr)
{
    int symbol_count = 0, lines_count = 0;
    int symbol = 0;

    lines_ptr[lines_count++] = text_buff;

    while((symbol = getc(file_ptr)) != EOF) // TODO use fgets
    {   
        if (symbol == '\n')
        {
            text_buff[symbol_count++] = '\0';
            lines_ptr[lines_count++] = text_buff + symbol_count; 
        }

        else
        {
            text_buff[symbol_count++] = char(symbol);
        }
    }

    text_buff[symbol_count++] = '\0';

    return lines_count;
}
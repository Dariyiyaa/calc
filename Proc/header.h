#include "error.h"
#include "ComandCode.h"

struct Processor
{
    struct Stack_t stk = {};
    int* code = 0;
    int pc = 0;
    size_t size_of_code = 0;
};

struct File
{
    FILE* ptr;
    const char* name;
};

struct Comand
{
    enum ProcessorCommand code_command;
    const char* name_command = 0;
    double value = 0;
};

errorReturn ReadCode(struct File* code_file, struct Processor* proc);
int SizeofFile(const char *const file_ptr);
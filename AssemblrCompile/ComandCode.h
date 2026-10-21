#include <stdio.h>

enum ProcessorCommand
{
    pcHLT = 0x0,

    pcPUSHc = 0b00100001,
    pcPUSHr = 0b01000001,
    pcPUSHm = 0b10000001,

    pcPOPc = 0b00100010,
    pcPOPr = 0b01000010,
    pcPOPm = 0b10000010,

    pcADD = 0x2,
    pcSUB = 0x3,
    pcMUL = 0x4,
    pcDIV = 0x5,
    pcOUT = 0x6,
    pcJMP = 0x9,
    pcJA = 0xA,
    pcJAE = 0xB,
    pcJB = 0xC,
    pcJBE = 0xD,
    pcJE = 0xE,
    pcJNE = 0xF,

    pcCALL = 0x10,
    pcRET = 0x11,
};



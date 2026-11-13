#ifndef COMMANDS

#define COMMANDS

#include <stddef.h>

enum ProcessorCommand
{
    pcHLT   =   0x0,

    pcPUSHc =   0b00100001,
    pcPUSHr =   0b01000001,
    pcPUSHm =   0b10000001,

    pcPOPc  =   0b00100010,
    pcPOPr  =   0b01000010,
    pcPOPm  =   0b10000010,

    pcADD   =   0x2,
    pcSUB   =   0x3,
    pcMUL   =   0x4,
    pcDIV   =   0x5,
    pcOUT   =   0x6,
    
    pcJMP   =   0x9,
    pcJA    =   0xA,
    pcJAE   =   0xB,
    pcJB    =   0xC,
    pcJBE   =   0xD,
    pcJE    =   0xE,
    pcJNE   =   0xF,

    pcCALL  =   0x10,
    pcRET   =   0x11,

};


enum ProcessorReg
{
    xEMPTY  =   0,
    
    AX      =   1,
    BX      =   2,     
    CX      =   3,       
    DX      =   4,      

    EX      =   5,
    FX      =   6,
    GX      =   7, 
    HX      =   8,

    IX      =   9, 
    JX      =   10,
    KX      =   11,
    LX      =   12,

    MX      =   13, 
    NX      =   14, 
    OX      =   15, 
    PX      =   16, 

};

#endif
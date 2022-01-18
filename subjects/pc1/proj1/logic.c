#include "types.h"
#include "logic.h"

/* Variaveis globais */
extern unsigned long r[32];
extern unsigned rip;
extern inst_t bin[100];

/* Implementar BEQ */
void do_beq(){
    if(*(unsigned int *)bin[rip].op1 == *(unsigned int *)bin[rip].op2){
        rip = bin[rip].op3 - 1;
    }
}

/* Implementar BLT */
void do_blt(){
    if(*(unsigned int *)bin[rip].op1 < *(unsigned int *)bin[rip].op2){
        rip = bin[rip].op3 - 1;
    }
}

/* Implementar JMP */
void do_jmp(){
    rip = bin[rip].op1 - 1;
}
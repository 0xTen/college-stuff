#include "types.h"
#include "read.h"

/* Variaveis globais */
extern unsigned long r[32];
extern unsigned rip;
extern inst_t bin[100];

/* Implementar MOV */
void do_mov(){
    if(bin[rip].mode){
        *(unsigned int *)bin[rip].op1 = bin[rip].op2;
    } else{
        *(unsigned int *)bin[rip].op1 = *(unsigned int *)bin[rip].op2;
    }
}
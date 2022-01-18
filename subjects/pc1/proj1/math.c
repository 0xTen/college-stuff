#include <stdlib.h>
#include "types.h"
#include "math.h"

/* Variaveis globais */
extern unsigned long r[32];
extern unsigned rip;
extern inst_t bin[100];

/* Implementar ADD */
void do_add(){
    *(unsigned int *)bin[rip].op1 = *(int *)bin[rip].op2 +
                                    *(int *)bin[rip].op3;
}

/* Implementar SUB */
void do_sub(){
    *(unsigned int *)bin[rip].op1 = *(int *)bin[rip].op2 -
                                    *(int *)bin[rip].op3;
}

/* Implementar MUL */
void do_mul(){
    *(unsigned int *)bin[rip].op1 = *(int *)bin[rip].op2 *
                                    *(int *)bin[rip].op3;
}

/* Implementar DIV */
void do_div(){
    if (*(unsigned int *)bin[rip].op3){
        *(unsigned int *)bin[rip].op1 = *(int *)bin[rip].op2 /
                                        *(int *)bin[rip].op3;
    } else{
        /* Erro caso haja divisao por 0 */
        exit(-1);
    } 
}

/* Implementar MOD */
void do_mod(){
    if (*(unsigned int *)bin[rip].op3){
        /* Obter modulo positivo */
        *(unsigned int *)bin[rip].op1 = (*(int *)bin[rip].op2 %
                                        *(int *)bin[rip].op3 +
                                        *(int *)bin[rip].op3) %
                                        *(int *)bin[rip].op3;
    } else{
        /* Erro caso haja divisao por 0 */
        exit(-1);
    }
}
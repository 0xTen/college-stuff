#include <stdio.h>
#include "types.h"
#include "out.h"

/* Variaveis globais */
extern unsigned long r[32];
extern unsigned rip;
extern inst_t bin[100];

/* Implementar PRINT */
void do_print(){
    printf("%d\n",*(unsigned int *)bin[rip].op1);
}
#include <sys/mman.h>
#include "types.h"
#include "mem.h"

/* Variaveis globais */
extern unsigned long r[32];
extern unsigned rip;
extern inst_t bin[100];

/* Inicializar a memoria */
unsigned long init_mem(){
    return mmap(0x1337000, 4000, PROT_READ|PROT_WRITE,
                MAP_ANON|MAP_FIXED|MAP_PRIVATE, -1, 0);
}

/* Carregar dados da memoria */
void do_load(){
    *(unsigned int *)bin[rip].op1 =
    *(unsigned int *)(0x1337000+*(unsigned int *)bin[rip].op2*4);
}

/* Armazenar dados na memoria */
void do_store(){
    *(unsigned int *)(0x1337000+*(unsigned int *)bin[rip].op2*4) =
    *(unsigned int *)bin[rip].op1;
}
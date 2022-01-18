#include <stdlib.h>
#include "types.h"
#include "control.h"

/* Variaveis globais */
extern unsigned long r[32];
extern unsigned rip;
extern inst_t bin[100];

int main(){
    unsigned long mem = init_mem();
    unsigned size = parse_size();

    /* Armazenar todas as instrucoes */
    for(int i = 0; i < size; i++){
        cmd_t cmd = parse_cmd();
        bin[i] = parse_inst(cmd);
    }

    /* Executar as instrucoes linha a linha */
    for(int _ = 0; _ < 100000; _++){
        if (rip >= size){
            exit(0);
        }
        exec_inst();
        rip++;
    }
    return 1;
}
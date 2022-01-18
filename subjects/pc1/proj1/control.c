#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "global.h"
#include "control.h"
#include "math.h"
#include "logic.h"
#include "mem.h"
#include "read.h"
#include "out.h"

/* Parsear o tamanho do programa */
unsigned parse_size(){
    unsigned size;
    scanf("%d",&size);
    return size;
}

/* Parsear os comandos */
cmd_t parse_cmd(){
    char raw[5];
    scanf("%5s",raw);
    if(!strncmp("MOV",raw,3)){
        return CMD_MOV;
    } else if(!strncmp("ADD",raw,3)){
        return CMD_ADD;
    } else if(!strncmp("SUB",raw,3)){
        return CMD_SUB;      
    } else if(!strncmp("MUL",raw,3)){
        return CMD_MUL;
    } else if(!strncmp("DIV",raw,3)){
        return CMD_DIV;
    } else if(!strncmp("MOD",raw,3)){
        return CMD_MOD;
    } else if(!strncmp("BEQ",raw,3)){
        return CMD_BEQ;
    } else if(!strncmp("BLT",raw,3)){
        return CMD_BLT;
    } else if(!strncmp("JMP",raw,3)){
        return CMD_JMP;
    } else if(!strncmp("LOAD",raw,4)){
        return CMD_LOAD;
    } else if(!strncmp("STORE",raw,5)){
        return CMD_STORE;
    } else if(!strncmp("PRINT",raw,5)){
        return CMD_PRINT;
    } else if(!strncmp("EXIT",raw,4)){
        return CMD_EXIT;
    }
}

/* Parsear os operandos da instrucao */
inst_t parse_inst(cmd_t cmd){
    unsigned long op1, op2, op3;
    unsigned mode = 0;
    char *line = NULL;
    char *tmp_1, *tmp_2, *tmp_3;
    size_t len = 0;
    getline(&line, &len, stdin);

    /* Verificar se ha mais de um operando */
    if (strstr(line," ")){
        tmp_1 = strtok(line, " ");
        tmp_2 = strtok(NULL, " ");
        tmp_3 = strtok(NULL, " ");

        if(strstr(tmp_1,"\n")){
            tmp_1[strcspn(tmp_1, "\n")] = 0;
        } else if(strstr(tmp_2,"\n")){
            tmp_2[strcspn(tmp_2, "\n")] = 0;
        } else if(strstr(tmp_3,"\n")){
            tmp_3[strcspn(tmp_3, "\n")] = 0;
        }

        /* Verificar para cada operando se e um registrador */
        if(tmp_1 && !strncmp("R",tmp_1,1)){
            op1 = &r[atoi(tmp_1+1)];
        } else {
            if(tmp_1){
                op1 = atoi(tmp_1);
            } else{
                op1 = 0;
            }
        }
        if(tmp_2 && !strncmp("R",tmp_2,1)){
            op2 = &r[atoi(tmp_2+1)];
        } else {
            if(cmd == CMD_MOV){
                mode = 1;
            }
            if(tmp_2){
                op2 = atoi(tmp_2);
            } else{
                op2 = 0;
            }
        }
        if(tmp_3 && !strncmp("R",tmp_3,1)){
            op3 = &r[atoi(tmp_3+1)];
        } else {
            if(tmp_3){
                op3 = atoi(tmp_3);
            } else{
                op3 = 0;
            }
        }
    } else {
        tmp_1 = line;
        if(tmp_1 && !strncmp("R",tmp_1,1)){
            op1 = &r[atoi(tmp_1+1)];
        } else {
            if(tmp_1){
                op1 = atoi(tmp_1);
            } else{
                op1 = 0;
            }
        }
        op2 = 0;
        op3 = 0;
    }

    inst_t result = {
        .cmd = cmd,
        .mode = mode,
        .op1 = op1,
        .op2 = op2,
        .op3 = op3
    };

    return result;

}

/* Executar instrucao */
void exec_inst(){
    switch(bin[rip].cmd){
        case CMD_MOV:
            do_mov();
            break;
        case CMD_ADD:
            do_add();
            break;
        case CMD_SUB:
            do_sub();
            break;
        case CMD_MUL:
            do_mul();
            break;
        case CMD_DIV:
            do_div();
            break;
        case CMD_MOD:
            do_mod();
            break;
        case CMD_BEQ:
            do_beq();
            break;
        case CMD_BLT:
            do_blt();
            break;
        case CMD_JMP:
            do_jmp();
            break;
        case CMD_LOAD:
            do_load();
            break;
        case CMD_STORE:
            do_store();
            break;
        case CMD_PRINT:
            do_print();
            break;
        case CMD_EXIT:
            exit(0);
    }
}
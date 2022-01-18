/*
Modulo para retornar eventuais erros
*/

#include <stdio.h>
#include <stdlib.h>
#include "err.h"

/* Escrever erros na stream stderr */
void putserr(err_t error){
    switch(error){
        case ERR_ARGS:
            fprintf(stderr, "Erro: Argumentos insuficientes!\n"
                            "./<nome_executavel> <caminho_arquivo_criptografado>"
                            "<caminho_arquivo_pre_computado> <relatorio_quebra>\n");
            break;
        case ERR_FILE:
            fprintf(stderr, "Erro: Nao foi possivel abrir o arquivo!\n");
            break;
        case ERR_MEM:
            fprintf(stderr, "Erro: Nao foi possivel alocar memoria dinamicamente!\n");
            break;
        case ERR_PERM:
            fprintf(stderr, "Erro: Permissao negada\n");
        case ERR_SIZE:
            fprintf(stderr, "Erro: Tamanho invalido\n");
    }
    exit(-1);
}
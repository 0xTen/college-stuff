/*
Modulo de leitura dos arquivos de entrada
*/

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "types.h"
#include "err.h"
#include "in.h"

/* Ler os dados dos arquivos de entrada */
list_t *parse_file(char *file){
    indata_t *target;
    char ch;
    unsigned lines = 1;
    FILE *fp;

    /* Alocar espaco para a lista */
    list_t *list;
    list = (list_t *)calloc(1, sizeof(list_t));

    /* Abrir o arquivo */
    fp = fopen(file,"r");
    if (fp <= 0){

        /* Nao foi possivel abrir o arquivo */
        putserr(ERR_FILE);
    }

    /* Obter o nro de linhas do arquivo */
    while((ch=fgetc(fp))!=EOF){
        if(ch=='\n'){
            lines++;
        }
    }

    /* Resetar a stream consumida */
    fclose(fp);
    fp = fopen(file,"r");
    if (fp <= 0){

        /* Nao foi possivel abrir o arquivo */
        putserr(ERR_FILE);
    }

    /* Alocar buffer para a lista de entradas */
    target = calloc(1, lines*sizeof(indata_t));
    if (target == NULL){

        /* Nao foi possivel alocar memoria */
        putserr(ERR_MEM);
    }

    /* Armazenar as estruturas com os dados de entrada */
    for (int i = 0; i < lines; i++){
        for (int j = 0; j <= 32; j++){
            ch = fgetc(fp);

            /* Ignorar linhas vazias */
            if (ch == '\n' || ch == '\r'){
                break;
            }

            if (ch == 32){

                /* Caso o caracter seja um " " ler a hash */
                fread(target[i].hash, 64, 1, fp);
                fgetc(fp);
                if (strlen(target[i].hash) != 64){

                    /* Tamanho invalido */
                    putserr(ERR_SIZE);
                }
                break;
            } else{
                if (j == 32){

                    /* Tamanho invalido */
                    putserr(ERR_SIZE);
                }
                /* Ler o nome ou senha em texto claro */
                target[i].data[j] = ch;
            }
        } 
    }

    list->lines = lines;
    list->data = target;

    fclose(fp);
    return list;
}
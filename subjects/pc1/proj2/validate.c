/*
Modulo de validacao das entradas 
*/

#include <stdio.h>
#include <unistd.h>
#include "err.h"
#include "validate.h"


/* Validar os arquivos e argumentos */
void validate(int argc, char *argv[]){

    /* Validar o nro de argumentos*/
    if (argc <= 3){
        putserr(ERR_ARGS);
    }

    /* Validar permissoes dos arquivos de entrada */
    if (access(argv[1], R_OK) != 0 || access(argv[2], R_OK) != 0){

        /* Pemissao negada */
        putserr(ERR_PERM);
    }

    /* Remover arquivo de saida, caso exista*/
    if (access(argv[3], F_OK) == 0){
        if (remove(argv[3]) != 0){

            /* Permissao negada */
            putserr(ERR_PERM);
        }
    }
}
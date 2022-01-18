/*
Modulo para salvar os resultados do programa
*/

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "out.h"

/* Armazenar os resultados no arquivo de saida */
void out(char *file, char *user, char *passwd){
    FILE *fp = fopen(file, "a");

    /* Adicionar os dados ao final do arquivo */
    fprintf(fp, "%s %s\n", user, passwd);
    fclose(fp);
}
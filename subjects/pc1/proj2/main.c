/*
Modulo principal
*/

#include "types.h"
#include "err.h"
#include "validate.h"
#include "in.h"
#include "crack.h"

int main(int argc, char *argv[]){

    /* Validar os arquivos e argumentos */
    validate(argc, argv);

    /* Ler as entradas, chamar modulo de busca de senhas,
        e por fim salvar o arquivo de saida */
    crack(argv[3], parse_file(argv[1]),parse_file(argv[2]));

    return 0;
}
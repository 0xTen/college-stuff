/*
Modulo de quebra de senhas
*/

#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "out.h"
#include "crack.h"

/* Implementacao de busca binaria de forma recursiva */
unsigned binarySearch(char *hash, list_t *wordlist, unsigned start, unsigned end){
    if (end >= start){
    
        /* Selecionar elemento do meio entre start e end */
        int mid = start + (end - start) / 2;

        int ret = strncmp(hash, wordlist->data[mid].hash, 64);
        if(ret > 0){

            /* Se o elemento desejado for maior que o do meio,
                buscar novamente, na metade superior */
            binarySearch(hash, wordlist, mid+1, end);

        } else if(ret < 0){

            /* Se o elemento desejado for menor que o do meio,
                buscar novamente, na metade inferior */
            binarySearch(hash, wordlist, start, mid-1);
        } else{

            /* Retornar o elemento do meio se for o desejado */
            return mid;
        }
    } else{
        return -1;
    }
}

/* Tentar quebrar as senhas com a lista pre-computada */
void crack(char *outfile, list_t *infile, list_t *wordlist){
    int passwd;

    for (int i = 0; i < infile->lines; i++){

        /* Busca binaria para procurar pelo hash na lista pre-computada */
        passwd = binarySearch(infile->data[i].hash, wordlist, 0, wordlist->lines-1);
        if (passwd >= 0){

            /* Chamar o modulo de saida para salvar as senhas quebradas */
            out(outfile, infile->data[i].data, wordlist->data[passwd].data);
        }
    }
}
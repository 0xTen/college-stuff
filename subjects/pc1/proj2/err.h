#ifndef ERR_H
#define ERR_H 1

typedef enum {
    ERR_ARGS,
    ERR_FILE,
    ERR_MEM,
    ERR_PERM,
    ERR_SIZE
} err_t;

/* Escrever erros na stream stderr */
void putserr(err_t error);

#endif
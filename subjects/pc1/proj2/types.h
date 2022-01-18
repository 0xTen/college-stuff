/* Pares de dados/hashes na memoria */
typedef struct {
    char data[33];
    char hash[65];
} indata_t;

/* Estrutura das listas na memoria */
typedef struct {
    unsigned lines;
    indata_t *data;
} list_t;
#include <stddef.h>
#include "types.h"

/* Inicializar os registradores e o buffer para o codigo */
unsigned long r[32] = {NULL};
unsigned rip = 0;
inst_t bin[100];
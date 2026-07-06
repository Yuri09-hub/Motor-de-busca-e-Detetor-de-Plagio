#ifndef PLAGIO_H
#define PLAGIO_H

#include <stddef.h>

#define SHINGLE_SIZE        3      /* trigramas de palavras */
#define MAX_SHINGLES        2048
#define LIMIAR_PLAGIO       0.7f   /* 70% */

typedef struct no {
    char palavra[30];
    int  id;
    struct no *prox;
} plagio;

typedef struct {
    unsigned long hashes[MAX_SHINGLES];
    int           count;
    int           doc_id;
} ShingleSet;

plagio*    criar_lista_plagio(void);
plagio*    inserir_na_lista_plagio(plagio *lista, char palavra[30], int id);

ShingleSet* calcular_shingles(const char *filepath, int doc_id);
float       jaccard(ShingleSet *a, ShingleSet *b);
void        detectar_plagio(ShingleSet **sets, int n, char paths[][512]);
void        shingle_set_free(ShingleSet *ss);

#endif

#include "plagio.h"
#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* -- lista de plágio -- */
plagio* criar_lista_plagio() {
    return NULL;
}

plagio* inserir_na_lista_plagio(plagio *lista, char palavra[30], int id) {
    plagio *novo = (plagio*)malloc(sizeof(plagio));
    if (novo) {
        novo->id = id;
        strcpy(novo->palavra, palavra);
        novo->prox = NULL;
        if (lista == NULL) {
            lista = novo;
        } else {
            plagio *aux = lista;
            while (aux->prox != NULL) aux = aux->prox;
            aux->prox = novo;
        }
    } else
        printf("Erro na alocacao do plagio\n");
    return lista;
}

/* -- hash de uma string -- */
static unsigned long hash_str(const char *s) {
    unsigned long h = 5381;
    int c;
    while ((c = (unsigned char)*s++))
        h = ((h << 5) + h) + c;
    return h;
}

/* -- calcula shingles de um ficheiro -- */
ShingleSet* calcular_shingles(const char *filepath, int doc_id) {
    TokenList *tl = tokenize_file(filepath, doc_id);
    if (!tl) return NULL;

    ShingleSet *ss = (ShingleSet*)calloc(1, sizeof(ShingleSet));
    ss->doc_id = doc_id;

    /* converte lista ligada para array temporário */
    char palavras[MAX_SHINGLES][MAX_TOKEN_LEN];
    int  total = 0;
    TokenNode *cur = tl->head;
    while (cur && total < MAX_SHINGLES) {
        strncpy(palavras[total++], cur->word, MAX_TOKEN_LEN - 1);
        cur = cur->next;
    }
    token_list_free(tl);

    /*shingles de SHINGLE_SIZE palavras */
    int i;
    for (i = 0; i <= total - SHINGLE_SIZE && ss->count < MAX_SHINGLES; i++) {
        char buf[MAX_TOKEN_LEN * SHINGLE_SIZE + SHINGLE_SIZE];
        int  j;
        buf[0] = '\0';
        for (j = 0; j < SHINGLE_SIZE; j++) {
            if (j > 0) strcat(buf, " ");
            strcat(buf, palavras[i + j]);
        }
        ss->hashes[ss->count++] = hash_str(buf);
    }

    return ss;
}

/* -- similaridade de Jaccard -- */
float jaccard(ShingleSet *a, ShingleSet *b) {
    int i, j, interseccao = 0;
    if (!a || !b || a->count == 0 || b->count == 0) return 0.0f;

    for (i = 0; i < a->count; i++)
        for (j = 0; j < b->count; j++)
            if (a->hashes[i] == b->hashes[j]) { interseccao++; break; }

    int uniao = a->count + b->count - interseccao;
    return (float)interseccao / (float)uniao;
}

/* -- compara todos os documentos par a par -- */
void detectar_plagio(ShingleSet **sets, int n, char paths[][512]) {
    int i, j, encontrou = 0;
    printf("\n=== DETECTOR DE PLAGIO ===\n");
    printf("Limiar: %.0f%%\n\n", LIMIAR_PLAGIO * 100);

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            float sim = jaccard(sets[i], sets[j]);
            printf("  %s\n  vs\n  %s\n", paths[i], paths[j]);
            printf("  Similaridade: %.1f%%  %s\n\n",
                   sim * 100,
                   sim >= LIMIAR_PLAGIO ? ">>> PLAGIO PROVAVEL!" : "[OK]");
            if (sim >= LIMIAR_PLAGIO) encontrou++;
        }
    }

    if (encontrou == 0)
        printf("Nenhum caso de plagio detectado.\n");
}

void shingle_set_free(ShingleSet *ss) {
    free(ss);
}

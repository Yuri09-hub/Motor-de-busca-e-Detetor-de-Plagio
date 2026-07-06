#ifndef DOCUMENT_LOADER_H
#define DOCUMENT_LOADER_H

#include "hash.h"
#include "trie.h"
#include "tokenizer.h"
#include <dirent.h>

#define MAX_FILES    100
#define MAX_PATH_LEN 512
#include "plagio.h"

typedef struct {
    char       paths[MAX_FILES][MAX_PATH_LEN];
    int        count;
    ShingleSet *shingles[MAX_FILES];
} DocumentLoader;

DocumentLoader* loader_criar(void);
void loader_carregar_pasta(DocumentLoader *dl, hashTable *tabela,NodeTrie **raiz, const char *pasta);
void loader_listar_docs(DocumentLoader *dl);
void loader_destruir(DocumentLoader *dl);

#endif

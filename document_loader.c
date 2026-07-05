#include "document_loader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

DocumentLoader* loader_criar(void) {
    DocumentLoader *dl = (DocumentLoader*)calloc(1, sizeof(DocumentLoader));
    return dl;
}

void loader_carregar_pasta(DocumentLoader *dl, hashTable *tabela,
                           NodeTrie **raiz, const char *pasta) {
    DIR *dir = opendir(pasta);
    if (!dir) {
        printf("Erro ao abrir a pasta '%s'\n", pasta);
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) && dl->count < MAX_FILES) {

        /* só ficheiros .txt */
        if (!strstr(entry->d_name, ".txt")) continue;

        /* monta caminho completo */
        snprintf(dl->paths[dl->count], MAX_PATH_LEN,
                 "%s/%s", pasta, entry->d_name);

        /* tokeniza */
        TokenList *tl = tokenize_file(dl->paths[dl->count], dl->count);
        if (!tl) { dl->count++; continue; }

        /* percorre tokens e insere na hash e na trie */
        TokenNode *cur = tl->head;
        while (cur) {
            insercao_de_palavra(tabela, cur->word, cur->doc_id);
            *raiz = insercao_de_palavra_trie(*raiz, cur->word, cur->doc_id);
            cur = cur->next;
        }

        token_list_free(tl);

        printf("[indexado] %s\n", dl->paths[dl->count]);
        dl->count++;
    }

    closedir(dir);
    printf("Total: %d documento(s) indexado(s)\n\n", dl->count);
}

void loader_listar_docs(DocumentLoader *dl) {
    printf("\n=== DOCUMENTOS CARREGADOS ===\n");
    for (int i = 0; i < dl->count; i++)
        printf("  [%d] %s\n", i, dl->paths[i]);
    printf("\n");
}

void loader_destruir(DocumentLoader *dl) {
    free(dl);
}

#ifndef TRIE_H
#define TRIE_H

#include "frequencia.h"

#define TAMANHO_ALFABETO 26

typedef struct NodeTrie {
    struct NodeTrie *filhos[TAMANHO_ALFABETO];
    ocor *lista; // Se for NULL, não é fim de palavra. Se tiver dados, guarda os documentos.
} NodeTrie;

NodeTrie* inicializar_trie();
NodeTrie* buscar_no_prefixo(NodeTrie *raiz, const char *prefixo);
NodeTrie* insercao_de_palavra_trie(NodeTrie *raiz, const char *palavra, int id);
ocor* buscar_palavra_trie(NodeTrie *raiz, const char *palavra);
void imprimir_trie(NodeTrie *no, char *buffer, int nivel);
void liberar_trie(NodeTrie *no);

#endif // TRIE_H

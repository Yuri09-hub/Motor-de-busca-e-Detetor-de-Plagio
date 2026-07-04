#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

NodeTrie* inicializar_trie() {
    NodeTrie *novo = (NodeTrie *)malloc(sizeof(NodeTrie));
    if (novo == NULL) {
        printf("Erro ao alocar memoria para o no da Trie\n");
        return NULL;
    }
    novo->lista = inicializar_lista_freq(); // Inicializa como NULL
    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        novo->filhos[i] = NULL;
    }
    return novo;
}

NodeTrie* insercao_de_palavra_trie(NodeTrie *raiz, const char *palavra, int id) {
    if (raiz == NULL) raiz = inicializar_trie();
    
    NodeTrie *no = raiz;
    for (int i = 0; palavra[i] != '\0'; i++) {
        int indice = tolower((unsigned char)palavra[i]) - 'a';
        
        // Ignora caracteres inválidos fora do intervalo a-z
        if (indice < 0 || indice >= TAMANHO_ALFABETO) continue;

        if (no->filhos[indice] == NULL) {
            no->filhos[indice] = inicializar_trie();
        }
        no = no->filhos[indice];
    }

    int existe_doc = verfica_doc_na_lista(no->lista, id);
    if (existe_doc == 0) { 
        // Documento não está na lista desta palavra: cria e insere
        ocor* novo_doc = criar_doc(id);
        no->lista = inserir_na_lista(no->lista, novo_doc);
    } else { 
        // Documento já existe: apenas incrementa a frequência
        no->lista = adiciona_freq(no->lista, id);
    }

    return raiz;
}

ocor* buscar_palavra_trie(NodeTrie *raiz, const char *palavra) {
    NodeTrie *no = raiz;
    if (no == NULL) return NULL;

    for (int i = 0; palavra[i] != '\0'; i++) {
        int indice = tolower((unsigned char)palavra[i]) - 'a';
        if (indice < 0 || indice >= TAMANHO_ALFABETO || no->filhos[indice] == NULL) {
            return NULL; // Palavra não encontrada
        }
        no = no->filhos[indice];
    }
    
    return no->lista; // Retorna a lista de ocorrências (será NULL se não for uma palavra completa)
}

void imprimir_trie(NodeTrie *no, char *buffer, int nivel) {
    if (no == NULL) return;

    if (no->lista != NULL) {
        buffer[nivel] = '\0';
        printf("%s -> ", buffer);
        imprimir_lista_ocor(no->lista);
    }

    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        if (no->filhos[i] != NULL) {
            buffer[nivel] = i + 'a';
            imprimir_trie(no->filhos[i], buffer, nivel + 1);
        }
    }
}

void liberar_trie(NodeTrie *no) {
    if (no == NULL) return;
    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        liberar_trie(no->filhos[i]);
    }
    free(no);
}
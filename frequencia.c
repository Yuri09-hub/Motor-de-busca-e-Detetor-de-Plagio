//
// Created by Yuri Rodrigues on 26/06/2026.
//
#include "frequencia.h"
#include <stdlib.h>
#include <stdio.h>

ocor * inicializar_lista_freq() {
    return NULL;
}

ocor *criar_doc(int id) {
    ocor *new_doc = (ocor*) malloc(sizeof(ocor));
    if(new_doc) {
        new_doc->id = id;
        new_doc->freq = 1;
        new_doc->prox = NULL;
        return new_doc;
    }
    return NULL;
}

ocor *adiciona_freq(ocor*lista,int id) {
    if (lista == NULL) {
        printf("Lista vazia");
        return NULL;
    }
    ocor * aux = lista;
    while (aux->prox != NULL) {
        if (aux->id == id) {
            aux->freq++;
            printf("Ocorrencia adicionada");
            return lista;
        }
        aux->prox = aux->prox;
    }
    return lista;
}

int verfica_doc_na_lista(ocor*lista, int id) {
    if (lista==NULL)
        return 0;
    ocor * aux = lista;
    while (aux->prox != NULL) {
        if (aux->id == id) {
            return 1;
        }
        aux->prox = aux->prox;
    }
    return 0;
}

ocor *inserir_na_lista(ocor*lista,ocor* new_doc) {
    if (lista==NULL)
        return NULL;
    ocor* aux = lista;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = new_doc;
    return lista;
}
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
    while (aux!= NULL) {
        if (aux->id == id) {
            aux->freq++;
            return lista;
        }
        aux  = aux->prox;
    }
    return lista;
}

int verfica_doc_na_lista(ocor*lista, int id) {
    if (lista==NULL)
        return 0;
    ocor * aux = lista;
    while (aux != NULL) {
        if (aux->id == id) {
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

ocor *inserir_na_lista(ocor*lista,ocor* new_doc) {
    if (lista==NULL) {
        return new_doc;
    }
    ocor* aux = lista;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = new_doc;
    return lista;
}

void imprimir_lista_ocor(ocor *lista)
{
    ocor *aux = lista;
    while (aux != NULL)
    {
        printf("(Doc%d, freq:%d) -> ", aux->id, aux->freq);
        aux = aux->prox;
    }
    printf("NULL\n");
}


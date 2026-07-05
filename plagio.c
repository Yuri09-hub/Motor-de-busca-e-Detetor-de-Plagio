//
// Created by Yuri Rodrigues on 05/07/2026.
//

#include "plagio.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

plagio *criar_lista_plagio() {
    return NULL;
}

plagio* inserir_na_lista_plagio(plagio *lista, char palavra[30], int id) {

   plagio* novo = (plagio*) malloc(sizeof(plagio));
    if (novo) {
        novo->id = id;
        strcpy(novo->palavra, palavra);
        novo->prox = NULL;

        if (lista == NULL) {
            lista =  novo;
        }else
            {
            plagio* aux = lista;
            while (aux->prox != NULL) {
                aux = aux->prox;
            }
            aux->prox = novo;
            }
    }else
        printf("Erro na alocao do plagio\n");

    return lista;
}

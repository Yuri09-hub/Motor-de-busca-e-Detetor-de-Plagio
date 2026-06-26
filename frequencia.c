//
// Created by Yuri Rodrigues on 26/06/2026.
//
#include "frequencia.h"
#include <stdlib.h>
#include <stdio.h>

ocor * inicializar_lista_freq() {
    return NULL;
}

ocor *criar_lista_doc(int id) {
    ocor *new_doc = (ocor*) malloc(sizeof(ocor));
    if(new_doc) {
        new_doc->id = id;
        new_doc->freq = 0;
        new_doc->prox = NULL;
        return new_doc;
    }
    return NULL;
}


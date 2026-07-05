//
// Created by Yuri Rodrigues on 05/07/2026.
//

#ifndef PLAGIO_H
#define PLAGIO_H

typedef struct no {
    char palavra[30];
    int id;
    struct no* prox;
}plagio;

plagio *criar_lista_plagio();
plagio *inserir_na_lista_plagio(plagio *lista, char palavra[30], int id);

#endif //PLAGIO_H

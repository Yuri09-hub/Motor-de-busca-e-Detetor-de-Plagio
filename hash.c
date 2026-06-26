//
// Created by Yuri Rodrigues on 26/06/2026.
//
#include "hash.h"
#include <string.h>
#include <stdlib.h>

hash* inicializar_tabela(int Tamanho) {
    hash* tabela = (hash*)malloc(sizeof(hash));
    if (tabela) {
        tabela -> Tamanho = Tamanho;

        tabela->lista_de_palavra = (Palavra*)malloc(sizeof(Palavra)* tabela -> Tamanho);

        if (tabela->lista_de_palavra== NULL) {
            free(tabela);
            return NULL;
        }
        tabela -> qtd = 0;
        for (int i = 0; i < tabela -> Tamanho; i++) {
            tabela ->lista_de_palavra[i].lista = (Ocorrencia*)malloc(sizeof(Ocorrencia));

        }
    }


}

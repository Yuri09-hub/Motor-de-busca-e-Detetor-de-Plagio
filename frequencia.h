//
// Created by Yuri Rodrigues on 26/06/2026.
//

#ifndef FREQUENCIA_H
#define FREQUENCIA_H
typedef struct Ocor {
    int freq, id;
    struct Ocor *prox;
}ocor;
ocor * inicializar_lista_freq();
ocor *criar_doc(int id);
ocor *adiciona_freq(ocor*lista,int id);
ocor *inserir_na_lista(ocor*lista,ocor* new_doc);
int verfica_doc_na_lista(ocor*lista, int id);


#endif //FREQUENCIA_H

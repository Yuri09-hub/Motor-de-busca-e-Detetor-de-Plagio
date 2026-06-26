//
// Created by Yuri Rodrigues on 26/06/2026.
//

#ifndef FREQUENCIA_H
#define FREQUENCIA_H
typedef struct  {
    int freq, id;
    struct Ocorrencia *prox;
}ocor;
ocor * inicializar_lista_freq();
ocor *criar_lista_doc(int id);
ocor *inserir_lista(ocor*lista,ocor* new_doc);
ocor *adiciona_freq(ocor*lista,int id);

#endif //FREQUENCIA_H

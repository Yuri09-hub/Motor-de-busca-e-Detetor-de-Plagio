//
// Created by Yuri Rodrigues on 13/06/2026.
//

#ifndef HASH_H
#define HASH_H
#define TAM_PALAVRA 30
typedef struct  {
    int freq, id;
    struct Ocorrencia *prox;
}Ocorrencia;

typedef struct {
    char palavra[TAM_PALAVRA];
    Ocorrencia * lista;// pra identificar os documentos
    struct Palavra *prox;
}Palavra;


typedef struct {
  int qtd, Tamanho;
  Palavra * lista_de_palavra;
}hash;


hash* inicializar_tabela(int Tamanho);


#endif //HASH_H

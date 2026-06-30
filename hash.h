//
// Created by Yuri Rodrigues on 13/06/2026.
//

#ifndef HASH_H
#define HASH_H
#define TAM_PALAVRA 30
#include "frequencia.h"

typedef struct {
  char palavra[TAM_PALAVRA];
  ocor * lista;// pra identificar os documentos
  int ocupado;
}Palavra;


typedef struct {
  int qtd, Tamanho;
  Palavra * tabela;
}hashTable;


hashTable* inicializar_tabela(int Tamanho);
unsigned long funcao_hashing(char palavra[30]);
hashTable* insercao_de_palavra(hashTable*tabela,char palavra[30],int id);
int verficar_palavra_na_hash(hashTable*tabela,char palavra[30]);
void imprimir (hashTable* tabela);
#endif //HASH_H

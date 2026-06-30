//
// Created by Yuri Rodrigues on 26/06/2026.
//
#include "hash.h"
#include "frequencia.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

hashTable* inicializar_tabela(int Tamanho) {
    hashTable* tabela = (hashTable*) malloc(sizeof(hashTable));
    if (tabela == NULL) {
        printf("Erro ao alocar memoria na criacao da tabela");
        return NULL;
    }
    tabela->Tamanho = Tamanho;
    tabela-> tabela = (Palavra*) malloc(Tamanho * sizeof(Palavra));
    if (tabela-> tabela == NULL) {
        free(tabela);
        printf("Erro ao alocar memoria nos espaco da tabela");
        return NULL;
    }
    for (int i = 0; i < Tamanho; i++) {
        tabela->tabela[i].lista = inicializar_lista_freq();
        strcpy(tabela -> tabela[i].palavra, "");
        tabela -> tabela[i].ocupado = -1;// vazio pra -1
    }
    tabela-> qtd = 0;

    return tabela;

}

unsigned long funcao_hash( char palavra[30]) {
    unsigned long hash = 5381;
    char * p = palavra;
    int c;

    while ((c = *p++)) {

        hash = ((hash << 5) + hash) + c;

    }

    return hash;
}

hashTable* insercao_de_palavra(hashTable*tabela,char palavra[30], int id) {

    int index =  funcao_hash(palavra) % tabela-> Tamanho ;
    while (tabela-> tabela[index].ocupado != -1) {
        index = (index+1) % tabela-> Tamanho;
    }
    tabela-> tabela[index].ocupado = 1;
    strcpy(tabela -> tabela[index].palavra, palavra);
   int x = verfica_doc_na_lista(tabela->tabela[index].lista,id);
    if (x == 0) {
       ocor* novo = criar_doc(id);
        tabela->tabela[index].lista = inserir_na_lista(tabela->tabela[index].lista,novo);
        tabela ->qtd++;
    }
    else {
        tabela -> tabela[index].lista = adiciona_freq(tabela -> tabela[index].lista,id);
    }
    return tabela;

}
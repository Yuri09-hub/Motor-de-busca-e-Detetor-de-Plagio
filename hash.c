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

unsigned long funcao_hashing( char palavra[30]) {
    unsigned long hash = 5381;
    char * p = palavra;
    int c;

    while ((c = *p++)) {

        hash = ((hash << 5) + hash) + c;

    }

    return hash;
}

int verficar_palavra_na_hash(hashTable* tabela,char palavra[30]) {

    for (int i = 0; i < tabela->Tamanho; i++) {
        if (strcmp(tabela -> tabela[i].palavra, palavra) == 0 ) {
            return i;
        }
    }
    return -1;
}

hashTable* insercao_de_palavra(hashTable*tabela,char palavra[30], int id) {

    int verfica = verficar_palavra_na_hash(tabela,palavra);

    if ( verfica != -1) { // palavra existe

        // verifica se o doc ja existe na hash
        int x = verfica_doc_na_lista(tabela->tabela[verfica].lista,id);
        if (x == 0) { // não existe
            ocor* novo = criar_doc(id);
            tabela->tabela[verfica].lista = inserir_na_lista(tabela->tabela[verfica].lista,novo);
        }
        else // existe
            tabela -> tabela[verfica].lista = adiciona_freq(tabela -> tabela[verfica].lista,id);

    }else{ // palavra não existe na hash

        int index = (int)(funcao_hashing(palavra) % (unsigned long)tabela-> Tamanho) ;

        while (tabela-> tabela[index].ocupado != -1) {
            index = (index+1) % tabela-> Tamanho;
        }
        tabela-> tabela[index].ocupado = 1;
        strcpy(tabela -> tabela[index].palavra, palavra);
        tabela ->qtd++;

        // criar o doc na lista de ocorrencias
        ocor* novo = criar_doc(id);
        tabela->tabela[index].lista = inserir_na_lista(tabela->tabela[index].lista,novo);
      }
    return tabela;

}

void imprimir (hashTable* tabela) {

    for (int i = 0; i < tabela->Tamanho; i++) {
        printf("[%d] - %s ->",i, tabela -> tabela[i].palavra);
        imprimir_lista_ocor(tabela->tabela[i].lista);
        printf("\n");
    }
    printf("quantidade de elementos inserido: %d", tabela->qtd);
}
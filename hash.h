//
// Created by Yuri Rodrigues on 13/06/2026.
//

#ifndef HASH_H
#define HASH_H
typedef struct doc {
    int id;
    char caminho[50];
    int tam_palavra;
};

typedef struct hash {
  int qtd, Tamanho;
  struct doc * item;
};


#endif //HASH_H

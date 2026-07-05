#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LEN 64

/* Nó da lista ligada — uma palavra única por nó */
typedef struct TokenNode {
    char             word[MAX_TOKEN_LEN];
    int              doc_id;
    int              frequency;
    struct TokenNode *next;
} TokenNode;

/* Lista ligada de tokens */
typedef struct {
    TokenNode *head;   /* primeiro nó */
    int        count;  /* total de entradas únicas */
} TokenList;

TokenList* tokenize_file(const char *filepath, int doc_id);
TokenList* tokenize_string(const char *text, int doc_id);
void       token_list_free(TokenList *tl);
int        is_stopword(const char *word);

#endif
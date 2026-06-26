#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LEN 64
#define MAX_TOKENS 4096

typedef struct{
	char words [MAX_TOKENS][MAX_TOKEN_LEN];
	int count;
}TokenList;

TokenList * tokenize_file(const char *filepath);
TokenList * tokenize_string(const char *text);
void token_list_free(TokenList *tl);
int is_stopword(const char *word);
#endif

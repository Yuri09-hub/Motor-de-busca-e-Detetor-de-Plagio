#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tokenizer.h"

static const char *STOPWORDS[] = {
    "o","a","os","as","um","uma","de","da","do","em","na","no",
    "e","ou","se","que","com","por","para","the","is","in","of",
    "and","to","an","it","at","on","this","was","for", NULL
};

int is_stopword(const char *word) {
    int i;
    for (i = 0; STOPWORDS[i] != NULL; i++)
        if (strcmp(word, STOPWORDS[i]) == 0) return 1;
    return 0;
}

static void normalize(char *dest, const char *src) {
    int i, j = 0;
    for (i = 0; src[i] && j < MAX_TOKEN_LEN - 1; i++) {
        if (isalpha((unsigned char)src[i]))
            dest[j++] = tolower((unsigned char)src[i]);
    }
    dest[j] = '\0';
}

static TokenNode* find_word(TokenList *tl, const char *word) {
    TokenNode *cur = tl->head;
    while (cur) {
        if (strcmp(cur->word, word) == 0) return cur;
        cur = cur->next;
    }
    return NULL;
}

static void insert_token(TokenList *tl, const char *word, int doc_id) {
    TokenNode *found = find_word(tl, word);
    if (found) {
        found->frequency++;
        return;
    }
    TokenNode *node = (TokenNode*)calloc(1, sizeof(TokenNode));
    strncpy(node->word, word, MAX_TOKEN_LEN - 1);
    node->doc_id    = doc_id;
    node->frequency = 1;
    node->next      = tl->head;
    tl->head        = node;
    tl->count++;
}

TokenList* tokenize_file(const char *filepath, int doc_id) {
    FILE *f = fopen(filepath, "r");
    if (!f) { perror("fopen"); return NULL; }

    TokenList *tl = (TokenList*)calloc(1, sizeof(TokenList));
    char raw[MAX_TOKEN_LEN * 2];

    while (fscanf(f, "%s", raw) == 1) {
        char norm[MAX_TOKEN_LEN];
        normalize(norm, raw);
        if (strlen(norm) >= 2 && !is_stopword(norm))
            insert_token(tl, norm, doc_id);
    }

    fclose(f);
    return tl;
}

TokenList* tokenize_string(const char *text, int doc_id) {
    char *buf = (char*)strdup(text);
    TokenList *tl = (TokenList*)calloc(1, sizeof(TokenList));

    char *tok = strtok(buf, " \t\n\r.,!?;:\"'()[]{}");
    while (tok) {
        char norm[MAX_TOKEN_LEN];
        normalize(norm, tok);
        if (strlen(norm) >= 2 && !is_stopword(norm))
            insert_token(tl, norm, doc_id);
        tok = strtok(NULL, " \t\n\r.,!?;:\"'()[]{}");
    }

    free(buf);
    return tl;
}

void token_list_free(TokenList *tl) {
    TokenNode *cur = tl->head;
    while (cur) {
        TokenNode *tmp = cur->next;
        free(cur);
        cur = tmp;
    }
    free(tl);
}

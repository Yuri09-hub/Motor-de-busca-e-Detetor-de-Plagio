#include "tokenizer.h"

static const char *STOPWORDS[] = {
"o","a","os","as","um","uma","de","da","do","em","na","no",
"e","ou","se","que","com","por","para", NULL
};

int is_stopword(const char *word)
{
	for (int i = 0 ; STOPWORDS[i]!=NULL;i++)
	{
		if (strcmp(word,STOPWORDS[i]==0))return 0 ;
		
	}
	
	return 0 ;
}

static void normalize (char *dest,const char *src)
{
	int j=0;
	for(int i =0;src[i];i++)
	{
		if(isalpha((unsigned char)src[i]))
		{
			dest[j++] = tolower((unsigned char)src[i]);
		}
		else if (j>0&& dest[j-1] != '\0')
			continue;
		
	}
	dest[j]='\0';
}

TokenList* tokenize_file(const char *filepath) {
	FILE *f = fopen(filepath, "r");
	if (!f) { perror("fopen"); return NULL; }
	TokenList *tl = calloc(1, sizeof(TokenList));
	char raw[MAX_TOKEN_LEN * 2];
	while (fscanf(f, "%s", raw) == 1 && tl->count < MAX_TOKENS) {
		char norm[MAX_TOKEN_LEN];
		normalize(norm, raw);
		if (strlen(norm) >= 2 && !is_stopword(norm)) {
		strncpy(tl->words[tl->count], norm, MAX_TOKEN_LEN - 1);
		tl->count++;
	}
}
fclose(f);
return tl;
}

TokenList* tokenize_string(const char *text) {
/* Copia o texto para um buffer temporário e tokeniza */
	char *buf = strdup(text);
	TokenList *tl = calloc(1, sizeof(TokenList));
	char *tok = strtok(buf, " \t\n\r.,!?;:\"'()[]{}");
	while (tok && tl->count < MAX_TOKENS) {
		char norm[MAX_TOKEN_LEN];
		normalize(norm, tok);
		if (strlen(norm) >= 2 && !is_stopword(norm)) 
		{
			strncpy(tl->words[tl->count], norm, MAX_TOKEN_LEN - 1);
			tl->count++;
		}
		tok = strtok(NULL, " \t\n\r.,!?;:\"'()[]{}");
		}
		free(buf);
	return tl;
	}
	void token_list_free(TokenList *tl) {
	free(tl);
}
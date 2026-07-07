#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "document_loader.h"
#include "trie.h"



void menu(){
    printf("==========================================\n");
    printf("  MOTOR DE BUSCA E DETECTOR DE PLAGIO     \n");
    printf("==========================================\n");
    printf("---------------- BUSCA -------------------\n");
    printf("1 - Pesquisar palavra                     \n");
    printf("2 - Sugestoes de pesquisa(autocomplete)   \n");
    printf("3 - Visualizar tabela hash                \n");
    printf("--------------- PLAGIO -------------------\n");
    printf("4 - Comparar dois documentos              \n");
    printf("5 - Mostrar percentagem de similaridade   \n");
    printf("--------------- SISTEMA ------------------\n");
    printf("0 - sair                                  \n");
    printf("==========================================\n");
    printf(" /> ");


}
#define TAM 1001
#define PASTA "docs"


int main(void) {
    int escolha;
    hashTable* tabela = (hashTable*)inicializar_tabela(TAM);
	NodeTrie *raiz = (NodeTrie*)inicializar_trie();
    DocumentLoader *dl=(DocumentLoader*)loader_criar();
	char enter;
    
    loader_carregar_pasta(dl,tabela,&raiz,PASTA);
    char palavra[30];
    char buffer [100];
    
    do {
        menu();
        scanf("%d", &escolha);
        getchar();

        switch (escolha) {
            case 1:
        	    system("cls");
                printf("Digite a palavra: ");
                scanf("%29s", palavra);
                getchar();
                pesquisa_palavra(tabela, palavra);

        		printf("\n pressione enter pra continuar...");
        		scanf("%c", &enter);

                printf("\n");
                break;
            case 2:
            	system("cls");
                printf("Digite o prefixo: ");
                scanf("%29s", palavra);
                getchar();
                printf("\nPalavras com prefixo '%s':\n", palavra);
                imprimir_trie(buscar_no_prefixo(raiz, palavra),buffer, 0);

        		printf("\n pressione enter pra continuar...");
        		scanf("%c", &enter);
                printf("\n");
                break;
            case 3:
            	system("cls");
				imprimir(tabela);

        		printf("\n pressione enter pra continuar...");
        		scanf("%c", &enter);
                printf("\n");
                break;
            case 4: {
			    /* compara dois documentos específicos */
			    int a, b;
			    loader_listar_docs(dl);
			    printf("Numero do primeiro documento: ");
			    scanf("%d", &a); getchar();
			    printf("Numero do segundo documento: ");
			    scanf("%d", &b); getchar();
			
			    if (a >= dl->count || b >= dl->count) {
			        printf("Numero invalido\n");
			        break;
			    }
			
			    float sim = jaccard(dl->shingles[a], dl->shingles[b]);
			    printf("\n%s\nvs\n%s\n", dl->paths[a], dl->paths[b]);
			    printf("Similaridade: %.1f%%  %s\n",
			           sim * 100,
			           sim >= LIMIAR_PLAGIO ? ">>> PLAGIO PROVAVEL!" : "[OK]");

            	printf("\n pressione enter pra continuar...");
            	scanf("%c", &enter);
			    break;
			}

			case 5:
			    /* compara todos os documentos */
			    detectar_plagio(dl->shingles, dl->count, dl->paths);
        		printf("\n pressione enter pra continuar...");
        		scanf("%c", &enter);
			    break;
			    }
			    }while (escolha != 0);

return 0;



}

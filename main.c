#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "document_loader.h"
#include "trie.h"



void menu(){
    printf("==========================================\n");
    printf("  MOTOR DE BUSCA E DETECTOR DE PLAGIO     \n");
    printf("==========================================\n");
    printf("1 - Listar documentos                     \n");
    printf("---------------- BUSCA -------------------\n");
    printf("2 - Pesquisar palavra                     \n");
    printf("3 - Sugestoes de pesquisa(autocomplete)   \n");
    printf("4 - Visualizar tabela hash                \n");
    printf("--------------- PLAGIO -------------------\n");
    printf("5 - Comparar dois documentos              \n");
    printf("6 - Mostrar percentagem de similaridade   \n");
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
    
    loader_carregar_pasta(dl,tabela,&raiz,PASTA);
    char palavra[30];
    char buffer [100];
    
    do {
        menu();
        scanf("%d", &escolha);
        getchar();

        switch (escolha) {
            case 1:
                printf("case1 \nCarregar Lista de Documentos");
                system("cls");
                break;
            case 2:
		    system("cls");
                printf("case2 \n");
                printf("Digite a palavra: ");
                scanf(" %29[^\n]", palavra);
                getchar();

                pesquisa_palavra(tabela, palavra);
                printf("\n");
                break;
            case 3:
			 system("cls");
                printf("case3 \n");
                printf("Digite o prefixo: ");
                scanf("%29s", palavra);
                getchar();
                printf("\nPalavras com prefixo '%s':\n", palavra);
                imprimir_trie(buscar_no_prefixo(raiz, palavra),buffer, 0);
                printf("\n");
                break;
            case 4:
            	system("cls");
			imprimir(tabela);
                printf("\n");

                break;
            case 5:
            	system("cls");
                printf("case5 \n");
                break;
            case 6:
            	system("cls");
                imprimir(tabela);
                printf("case5 \n");
                break;
            case 7:
            	system("cls");

                printf("case7 \n");
                break;
            case 8:
                printf("case8 \n");
                break;

            case 0:
                printf("Saindo... \n");
                break;
            default:
                printf("Opcao invalida \n");
                break;
        }
	
    }while (escolha != 0);

return 0;



}

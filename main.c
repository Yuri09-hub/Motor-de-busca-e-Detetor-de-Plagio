#include <stdio.h>
#include <stdlib.h>
#include "hash.h"



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


int main(void) {
    int escolha;
    hashTable* tabela = inicializar_tabela(TAM);
    char palavra[30];

    tabela = insercao_de_palavra(tabela,"Casa",1);
    tabela = insercao_de_palavra(tabela,"Casa",1);
    tabela = insercao_de_palavra(tabela,"domingo",1);

    do {
        menu();
        scanf("%d", &escolha);
        getchar();

        switch (escolha) {
            case 1:
                printf("case1 \n");
                break;
            case 2:
                printf("case2 \n");
                break;
            case 3:
                printf("case3 \n");
                break;
            case 4:

                printf("digite a palavra: ");
                scanf("%[^\n]",palavra);

                pesquisa_palavra(tabela, palavra);
                printf("\n");

                break;
            case 5:
                printf("case5 \n");
                break;
            case 6:
                imprimir(tabela);
                printf("case5 \n");
                break;
            case 7:
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

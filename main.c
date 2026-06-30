#include <stdio.h>
#include <stdlib.h>

#include "hash.h"


void menu(){
    printf("==========================================\n");
    printf("  MOTOR DE BUSCA E DETECTOR DE PLAGIO     \n");
    printf("==========================================\n");
    printf("1 - Adicionar documento                   \n");
    printf("2 - Remover documento                     \n");
    printf("3 - Listar documentos                     \n");
    printf("---------------- BUSCA -------------------\n");
    printf("4 - Pesquisar palavra                     \n");
    printf("5 - Pesquisar frase                       \n");
    printf("6 - Sugestoes de pesquisa                 \n");
    printf("--------------- PLAGIO -------------------\n");
    printf("7 - Comparar dois documentos              \n");
    printf("8 - Mostrar percentagem de similaridade   \n");
    printf("--------------- SISTEMA ------------------\n");
    printf("0 - sair                                  \n");
    printf("==========================================\n");
    printf(" /> ");


}
#define TAM 11


int main(void) {
    int escolha;
    hashTable* tabela = inicializar_tabela(TAM);

    tabela = insercao_de_palavra(tabela,"Casa",1);
    tabela = insercao_de_palavra(tabela,"Casa",1);
    tabela = insercao_de_palavra(tabela,"domingo",1);
    imprimir(tabela);
    return 0;

    do {
        menu();
        scanf("%d", &escolha);
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
                printf("case4 \n");
                break;
            case 5:
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





}

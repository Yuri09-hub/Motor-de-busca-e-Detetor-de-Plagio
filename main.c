#include <stdio.h>

void menu(){
    printf("==========================================\n");
    printf("  MOTOR DE BUSCA E DETECTOR DE PLÁGIO     \n");
    printf("==========================================\n");
    printf("1 - Adicionar documento                   \n");
    printf("2 - Remover documento                     \n");
    printf("3 - Listar documentos                     \n");
    printf("---------------- BUSCA -------------------\n");
    printf("4 - Pesquisar palavra                     \n");
    printf("5 - Pesquisar palavra                     \n");
    printf("6 - Pesquisar palavra                     \n");
    printf("--------------- PLAGIO -------------------\n");
    printf("7 - Comparar dois documentos              \n");
    printf("8 - Mostrar percentagem de similaridade   \n");
    printf("--------------- SISTEMA ------------------\n");

}

int main(void) {
    int escolha;

    do {
        menu();
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                printf("case1");
                break;
            case 2:
                printf("case2");
                break;
            case 3:
                printf("case3");
                break;
            case 4:
                printf("case4");
                break;
            case 5:
                printf("case5");
                break;
            case 7:
                printf("case7");
                break;
            case 8:
                printf("case8");
                break;
            case 0:
                printf("Saindo...");
                break;
            default:
                printf("Opcao invalida");
                break;
        }

    }while (escolha != 0);




    return 0;
}

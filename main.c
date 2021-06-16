#include "func.h"

int main(){
    int i=0;
    while (i!=3){
        printf("ESCOLHA UMA OPÇAO:\n");
        printf("[1] PARTE 1\n");
        printf("[2] PARTE 2\n");
        printf("[3] SAIR\n");
        scanf("%d",&i);
        switch (i){
            case 1:
                parte1();
                break;
            case 2:
                parte2();
                break;
            case 3:
                break;
            default:
                printf("Opçao invalida!\n");
                break;
        }
    }
    return 0;
}

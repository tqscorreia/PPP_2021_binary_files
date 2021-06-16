
#include "func.h"
#include "funcParte2.h"

/*
 * Funçao principal para a parte 2
 */
void parte2() {
    //variaveis globais
    FILE *fp3 = fopen("tab_texto.bin", "rb"); //abre o ficheiro onde estao os dados em modo leitura
    char ini[3], cont[10];

    //estrutura dos pares(palavra e posiçao)
    Dados d;

    //cria a arvore
    Tree* t = createTree();

    //verifica se o ficheiro esta vazio
    if (fp3 == NULL) {
        printf("Erro ao tentar abrir o arquivo param3.txt!");
    } else {

        //lê a linha e faz a divisao para fazer a inserçao na arvore
        while (fread(&d, sizeof(Dados), 1, fp3)){
            strtobase_u8(d.word, d.word);
            insertTree(&t, d.word, d.posi);
            //printf("%s--->%d\n", d.word, d.posi);
        }

    }
    fclose(fp3);
    //menu
    int opcao = 0; // inicialização do int opcao
    while (opcao != 4) {
        printf("ESCOLHA UMA OPÇAO:\n");
        printf("1 - Mostrar arvore\n");
        printf("2 - Mostrar contexto da palavra\n");
        printf("3 - Procurar por letras iniciais\n");
        printf("4 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                showTree(t);
                break;
            case 2:
                printf("Insira a palavra a contextualizar\n");
                scanf("%s", cont);
                strtobase_u8(cont, cont);
                context(t, cont);
                break;
            case 3:
                printf("Insira as letras iniciais\n");
                scanf("%s", ini);
                //passa a string a minusculas
                strtobase_u8(ini, ini);
                searchIniciais(t, ini);
                break;
            case 4:
                free(t);
                break;
            default:
                printf("Opçao invalida!\n");
                break;
        }
    }
}


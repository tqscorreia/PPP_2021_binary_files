#include "funcParte2.h"
Tree* createTree(){
    return NULL;
}

//insere as posiçoes na lista ligada
void insertAtEnd(List** ref, int data) {
    List* new_node = (List*)malloc(sizeof(List));
    List* last = *ref;

    new_node->pos = data;
    new_node->next = NULL;

    if (*ref == NULL) {
        *ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

//imprime a lista ligada
void printList(List* l) {
    while (l != NULL) {
        printf(" %d ", l->pos);
        l = l->next;
    }
}

//imprime a arvore com a lista ligada
void showTree(Tree* t){

    if(t!=NULL) {
        showTree(t->esq);
        printf("%20s ", t->pala);
        printList(t->head);
        printf("\n");
        showTree(t->dir);
    }
}

//insere a palavras na arvore
void insertTree(Tree** t, char *p, int pos ){
    //vê se o no esta vazio
    if(*t == NULL){
        *t = (Tree*)malloc(sizeof(Tree));
        (*t)->esq = NULL;
        (*t)->dir = NULL;
        (*t)->head = NULL;
        strcpy((*t)->pala, p);

        insertAtEnd(&(*t)->head, pos);

    } else {
        if(strcmp(p, (*t)->pala)<0){
            insertTree(&(*t)->esq, p, pos);
        }
        else if(strcmp(p, (*t)->pala)>0){
            insertTree(&(*t)->dir, p, pos);
        }
        else if(strcmp(p, (*t)->pala)==0){
            insertAtEnd(&(*t)->head, pos);
        }
    }
}

//procura na arvore se existem palavras começadas pelas mesmas letras
void searchIniciais(Tree* t, char* ini){
    char palavra[TAM];
    if(t!=NULL){

        searchIniciais(t->esq, ini);
        strcpy(palavra, t->pala);
        if (ini[1]=='\0'){
            if (ini[0] == palavra[0]){

                printf("%20s ", palavra);
                printList(t->head);
                printf("\n");

            }
        }else if(ini[2]=='\0'){
            if (ini[0] <= palavra[0] && ini[1] >= palavra[0]){

                printf("%20s ", palavra);
                printList(t->head);
                printf("\n");

            }
        }
        searchIniciais(t->dir, ini);
    }

}

void  contextualiza(int posicao) {
    int contador = 0, c = 0, i = 0;
    char cad[posicao + 1], ord[posicao + 1];
    FILE *fich = fopen("texto.txt", "r");
    if (fich == NULL) {
        printf("Problemas na abertura do ficheiro de texto\n");
    }
    fseek(fich, posicao, SEEK_SET);
    long lim = ftell(fich);

    //procura as palavras para tras
    while (lim >= 0) {
        fseek(fich, lim, SEEK_SET); //reposicionar de acordo com a posicao
        c = fgetc(fich);
        if (c == ' ' || c == '\n')
            contador++;
        if (contador == 6) {
            cad[i] = '\0';
            break;
        }
        cad[i] = (char) c;
        i++;
        lim--; //andar uma posição para trás
    }
    for (unsigned n = 0; n < strlen(cad); n++) {
        ord[n] = cad[strlen(cad) - n];
        printf("%c", ord[n]);
    }
    contador = 0;
    fseek(fich, posicao, SEEK_SET);
    while (1) {
        c = fgetc(fich);
        printf("%c", c);
        if (c == ' ' || c == '\n')
            contador++;
        if (contador == 11 || c == EOF)
            break;

    }
    printf("\n");


}

void listContexto(List* l) {

    while (l != NULL) {
        contextualiza(l->pos);
        printf("\n");
        l = l->next;
    }
}

int context(Tree* t, char* ini){
    //se o no for nulo nao encontra
    if (t==NULL) {
        printf("A palavra inserida não se encontra no texto\n");
        return 0;
    }
        //se a palavra for igual á palavra do no printa
    else if (strcmp(ini, t->pala)==0){
        listContexto(t->head);
        return 0;
    }
        //se a palavra for "maior" que a palavra do nó vai para o nó direito
    else if (strcmp(ini, t->pala)>0)
        context(t->dir, ini);
        //se a palavra for "menor" que a palavra do nó vai para o nó esquerdo
    else if (strcmp(ini, t->pala)<0)
        context(t->esq, ini);
    return 0;
}
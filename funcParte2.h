
#ifndef PPP_2021_BINARY_FILES_FUNCPARTE2_H
#define PPP_2021_BINARY_FILES_FUNCPARTE2_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "lib-utf8.h"

#define TAM 100

//estrutura da lista ligada
typedef struct lnode{
    int pos;
    struct lnode *next;
}List;

//estrutura da arvore
typedef struct tree{
    char pala[TAM];
    List *head;
    struct tree* dir;
    struct tree* esq;
} Tree;

Tree* createTree();

int treeIsEmpty(Tree* t);

//insere as posiçoes na lista ligada
void insertAtEnd(List** ref, int data);

//imprime a lista ligada
void printList(List* l);

//imprime a arvore com a lista ligada
void showTree(Tree* t);

//insere a palavras na arvore
void insertTree(Tree** t, char *p, int pos );

//procura na arvore se existem palavras começadas pelas mesmas letras
void searchIniciais(Tree* t, char* ini);

void contextualiza(int posicao);


void listContexto(List* l);

int context(Tree* t, char* ini);

#endif //PPP_2021_BINARY_FILES_FUNCPARTE2_H

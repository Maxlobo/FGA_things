#ifndef ARVORE_H
#define ARVORE_H

typedef struct no {
  int info;
  struct no* esq;
  struct no* dir;
} No;


No *removeValue(No *raiz,int info);
No *loadTreeFromFile(char arquivo[]);
No *balanceTree(No *raiz);

int getHeight(No *raiz);

void showTree(No *raiz);
void isFull(No *raiz);
void searchValue(No *raiz,int info);
void printInOrder(No *raiz);
void printPreOrder(No *raiz);
void printPostOrder(No *raiz);

#endif

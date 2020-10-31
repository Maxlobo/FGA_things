#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvore.c"
//---------------------------------------------------------------------
//DECLARAÇÕES DE FUNÇÕES

char menu();

void liberaArvore(No *raiz);
void limpaBuff();
void continuar();

No *selecionaArquivo();

//---------------------------------------------------------------------
//QUERIDA MAIN

int main(int argc, char const *argv[]) {
  char select;
  No *raiz;
  int num;
  raiz = selecionaArquivo();
  do{
    select = menu();
    switch (select){
      case '1':
        system("clear");
        showTree(raiz);
        break;

      case '2':
        system("clear");
        isFull(raiz);
        break;

      case '3':
        system("clear");
        printf("Digite o numero que deseja procurar na arvore: \n");
        showTree(raiz);
        scanf("%d",&num);
        getchar();
        printf("\n\nValor procurado: %d\n\n",num);
        searchValue(raiz,num);
        break;

      case '4':
        system("clear");
        printf("Altura da arvore: %d\n",getHeight(raiz));
        break;

      case '5':
        system("clear");
        printf("Digite o numero que deseja remover da arvore: \n");
        showTree(raiz);
        scanf("%d",&num);
        getchar();
        raiz = removeValue(raiz,num);
        break;

      case '6':
        system("clear");
        printInOrder(raiz);
        break;

      case '7':
        system("clear");
        printPreOrder(raiz);
        break;

      case '8':
        system("clear");
        printPostOrder(raiz);
        break;

      case '9':
        system("clear");
        raiz = balanceTree(raiz);
        showTree(raiz);
        break;

      case '0':
        liberaArvore(raiz);
        printf("\nTchau :)\n");
    }

    if (select != '0'){
      continuar();
    }
  } while(select != '0');
  return 0;
}
//----------------------------------------------------------------------
char menu(){
  char select;
  do{
    system("clear");
    printf("\n");
    printf("==============================================\n");
    printf("||\t1 - Mostrar arvore                  ||\n");
    printf("||\t2 - Verificar se a arvore é cheia   ||\n");
    printf("||\t3 - Procurar o numero na arvore     ||\n");
    printf("||\t4 - Verificar altura da arvore      ||\n");
    printf("||\t5 - Remover o numero da arvore      ||\n");
    printf("||\t6 - Printar - In Order              ||\n");
    printf("||\t7 - Printar - Pre Order             ||\n");
    printf("||\t8 - Printar - Post Order            ||\n");
    printf("||\t9 - Balancear arvore                ||\n");
    printf("||\t0 - Sair                            ||\n");
    printf("==============================================\n\n");
    scanf("%c",&select);
    limpaBuff();
  } while(select < '0' || select > '9');
  return select;
}
//----------------------------------------------------------------------
void limpaBuff(){
  char c;
  do{
      c = getchar();
    } while(c != '\n');
}
//----------------------------------------------------------------------
void continuar(){
  char c;
  printf("\nAperte enter para continuar\n");
  do
  {
    c = getchar();
  } while(c != '\n');
}
//----------------------------------------------------------------------
No *selecionaArquivo(){
  char arquivo;
  char nomeArquivo[50];
  No *raiz;
  do{
      system("clear");
      printf("\n");
      printf("Selecione um dos arquivos abaixo, ou digite 0 para utilizar um arquivo pessoal:\n\n");
      printf("================================\n");
      printf("||  1 - bst1.txt              ||\n");
      printf("||  2 - bst2.txt              ||\n");
      printf("||  3 - bst3.txt              ||\n");
      printf("||  4 - bst4.txt              ||\n");
      printf("||  5 - bst5.txt              ||\n");
      printf("||  6 - bst6.txt              ||\n");
      printf("||  0 - Utilizar seu arquivo  ||\n");
      printf("================================\n\n");
      scanf("%c",&arquivo);
      limpaBuff();
    } while(arquivo < '0' || arquivo > '6');
  if (arquivo == '0'){
    printf("Digite o nome do seu arquivo:\n");
    scanf("%s",nomeArquivo);
    limpaBuff();
    raiz = loadTreeFromFile(nomeArquivo);
  }
  else
  {
    strcat(nomeArquivo,"BSTs/bst");
    nomeArquivo[strlen(nomeArquivo)] = arquivo;
    strcat(nomeArquivo,".txt");
    raiz = loadTreeFromFile(nomeArquivo);
  }
  return raiz;
}
//----------------------------------------------------------------------
void liberaArvore(No *raiz){
    if(raiz != NULL){
      liberaArvore(raiz->esq);
      liberaArvore(raiz->dir);
      free(raiz);
    }
  }
//----------------------------------------------------------------------

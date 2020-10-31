/*
    Érico Bandeira - 16/0070287
    Luciana Ribeiro Lins de Albuquerque - 15/0016131
    Max Henrique Barbosa - 16/0047013
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "arvore.h"

//---------------------------------------------------------------
//DECLARAÇÃO DE FUNÇÕES

void insere(No *raiz, No *aux);
void encheMatriz(int **matrizNum,char **matrizBarra,No *raiz,int altura,int nivel,int coluna);
void retiraEspacos(char **matrizBarra,int height, int *inicio, int *fim);


int verificaCheia(No *raiz);
int verificaBalanceamento(No *raiz);

No *rotaciona(No *raiz, No *pai, No *raizReal);
No *rodaEsq(No *raiz, No *pai, No *raizReal);
No *rodaDir(No *raiz, No *pai, No *raizReal);

No *removeRaiz(No *raiz);
No *verificaValor(No *raiz,No *pai);
No *achaSucessor(No *Raiz);
//---------------------------------------------------------------
No *loadTreeFromFile(char arquivo[]){
  FILE *arq;
  int info;
  No *aux;
  No *raiz = NULL;

  if(arq = fopen(arquivo,"a+"), arq == NULL){
    printf("erro ao abrir o arquivo!\n");
    exit(1);
  }

  if (!feof(arq)){
    fscanf(arq," %d ",&info);
  }

  if (!feof(arq)){
    if(raiz = (No*)malloc(sizeof(No)),raiz == NULL){
      printf("Alocação falhou!\n");
    }

    raiz->info = info;
    raiz->esq = NULL;
    raiz->dir = NULL;
  }

  while(!feof(arq)){
    fscanf(arq," %d ",&info);
    if(aux = (No*)malloc(sizeof(No)),aux == NULL){
      printf("alocação falhou!\n");
    }

    aux->info = info;
    aux->dir = NULL;
    aux->esq = NULL;
    insere(raiz,aux);
  }
  fclose(arq);
  return raiz;
}
//---------------------------------------------------------------
void insere(No *raiz,No *aux){
  if (raiz->info < aux->info){
    if (raiz->dir == NULL){
      raiz->dir = aux;
    }
    else{
      insere(raiz->dir,aux);
    }
  }
  else{
    if (raiz->esq == NULL){
      raiz->esq = aux;
    }
    else{
      insere(raiz->esq,aux);
    }
  }
}
//---------------------------------------------------------------
void isFull(No *raiz){
   if (raiz == NULL){
     printf("Arvore esta vazia\n");
     return;
   }

   if(verificaCheia(raiz)){
     printf("Arvore cheia\n");
   }

   else{
     printf("Arvore não é cheia\n");
   }
 }
//---------------------------------------------------------------
int verificaCheia(No *raiz){
   if (raiz != NULL){
     if ((raiz->esq == NULL && raiz->dir != NULL) || (raiz->esq != NULL && raiz->dir == NULL)){
       return 0;
     }

     else{
       return verificaCheia(raiz->esq) * verificaCheia(raiz->dir);
     }
   }
   return 1;
 }
//---------------------------------------------------------------
No *balanceTree(No *raiz){
   if (raiz == NULL){
     printf("arvore esta vazia\n");
     return raiz;
   }
   if(!verificaBalanceamento(raiz)){
     do{
       raiz = rotaciona(raiz, NULL, raiz);
     } while(!verificaBalanceamento(raiz));
   }

   else{
     printf("arvore esta balanceada\n");
   }
   return raiz;
 }
//---------------------------------------------------------------
No *rodaDir(No *raiz,No *pai,No *raizReal){
  No *aux = raiz->dir;
  if (pai != NULL){
    if (pai->esq == raiz){
      pai->esq = aux;
    }

    else{
      pai->dir = aux;
    }
    raiz->dir = aux->esq;
    aux->esq = raiz;
  }

  else{
    raiz->dir = aux->esq;
    aux->esq = raiz;
    raizReal = aux;
  }

  return raizReal;
}
//---------------------------------------------------------------
No *rodaEsq(No *raiz,No *pai,No *raizReal){
  No *aux = raiz->esq;
  if (pai != NULL){
    if (pai->esq == raiz){
      pai->esq = aux;
    }

    else{
      pai->dir = aux;
    }
    raiz->esq = aux->dir;
    aux->dir = raiz;
  }

  else{
    raiz->esq = aux->dir;
    aux->dir = raiz;
    raizReal = aux;
  }
  return raizReal;
}
//---------------------------------------------------------------
No *rotaciona(No *raiz, No *pai, No *raizReal){
  if (raiz != NULL){
    if (!verificaBalanceamento(raiz)){
      raizReal = rotaciona(raiz->esq,raiz,raizReal);
      if (verificaBalanceamento(raiz)){
        return raizReal;
      }

      raizReal = rotaciona(raiz->dir,raiz,raizReal);

      if (verificaBalanceamento(raiz)){
        return raizReal;
      }

      if (getHeight(raiz->esq) > getHeight(raiz->dir)){
        raizReal = rodaEsq(raiz,pai,raizReal);
      }

      else{
        raizReal = rodaDir(raiz,pai,raizReal);
      }
    }
  }
  return raizReal;
}
//---------------------------------------------------------------
int verificaBalanceamento (No *raiz){
   int diferenca;
   if (raiz != NULL){
     diferenca = getHeight(raiz->esq) - getHeight(raiz->dir);

     if (diferenca < -1 || diferenca > 1){
       return 0;
     }

     else{
       return verificaBalanceamento(raiz->esq)*verificaBalanceamento(raiz->dir);
     }
   }
   return 1;
 }
//---------------------------------------------------------------
No *removeValue(No *raiz,int info){
  No *pai = NULL, *aux = raiz;
  while (aux != NULL){

    if (aux->info == info){
      break;
    }

    pai = aux;

    if (aux->info < info){
      aux = pai->dir;
    }

    else{
      aux = pai->esq;
    }
  }

  if (aux == NULL){
    printf("Valor não encontrado\n");
  }

  else{
    if (pai == NULL){
      raiz = removeRaiz(raiz);
    }
    else{
      aux = verificaValor(aux,pai);
      free(aux);
    }
    printf("\nValor removido\n\n");
    showTree(raiz);
  }
  return raiz;
}
//---------------------------------------------------------------
No *removeRaiz(No *raiz){
  No *aux;
  if (raiz->dir != NULL || raiz->esq != NULL){
    if (raiz->dir != NULL && raiz->esq != NULL){
      aux = achaSucessor(raiz);
      free(aux);
      return raiz;
    }

    else{
      if (raiz->dir != NULL){
        aux = raiz->dir;
        free(raiz);
        return aux;
      }

      else{
        aux = raiz->esq;
        free(raiz);
        return aux;
      }
    }
  }

  else{
    free(raiz);
    return NULL;
  }
}
//---------------------------------------------------------------
No *verificaValor(No *raiz,No *pai){
  if (raiz->dir != NULL || raiz->esq != NULL){
    if (raiz->dir != NULL && raiz->esq != NULL){
      return achaSucessor(raiz);
    }

    else{
      if (raiz->dir != NULL){
        if (pai->dir == raiz){
          pai->dir = raiz->dir;
          return raiz;
        }

        else{
          pai->esq = raiz->dir;
          return raiz;
        }
      }

      else{
        if (pai->dir == raiz){
          pai->dir = raiz->esq;
          return raiz;
        }

        else{
          pai->esq = raiz->esq;
          return raiz;
        }
      }
    }
  }

  else{
    if (pai->info < raiz->info){
      pai->dir = NULL;
    }

    else{
      pai->esq = NULL;
    }

    return raiz;
  }
}
//---------------------------------------------------------------
No *achaSucessor(No *raiz){
    No *sucessor, *pai, *aux;
    int info;

    sucessor = raiz->dir;

    pai = raiz;

    while (sucessor->esq != NULL){
      pai = sucessor;
      sucessor = pai->esq;
    }

    info = sucessor->info;
    aux = verificaValor(sucessor,pai);
    raiz->info = info;
    return aux;
}
//---------------------------------------------------------------
int getHeight(No *raiz){
    int u, v;

    if (raiz == NULL)
        return 0;

    u = getHeight(raiz->esq);
    v = getHeight(raiz->dir);

    if (u > v)
        return u+1;

    return v+1;
}
//---------------------------------------------------------------
void printPostOrder(No *raiz){
   if(raiz == NULL)
       return;
   printPostOrder(raiz->esq);
   printPostOrder(raiz->dir);
   printf("%d ", raiz->info);
 }
//---------------------------------------------------------------
void printPreOrder(No *raiz){
   if(raiz == NULL)
       return;
   printf("%d ", raiz->info);
   printPreOrder(raiz->esq);
   printPreOrder(raiz->dir);
 }
//---------------------------------------------------------------
void printInOrder(No *raiz){
   if(raiz == NULL)
       return;
   printInOrder(raiz->esq);
   printf("%d ", raiz->info);
   printInOrder(raiz->dir);
 }
//---------------------------------------------------------------
void searchValue(No *raiz,int info){
  int nivel = 1;
  No *pai=NULL, *irmao=NULL;
  while (raiz != NULL){
    if (raiz->info == info){
      break;
    }

    nivel++;

    pai = raiz;

    if (raiz->info < info){
      irmao = raiz->esq;
      raiz = pai->dir;
    }

    else{
      irmao = raiz->dir;
      raiz = pai->esq;
    }
  }

  if (raiz == NULL){
    printf("Valor não encontrado\n");
  }

  else{

    printf("Nivel   : %d\n",nivel);

    if (pai != NULL){
      printf("Pai     : %d\n",pai->info);
    }

    if (irmao != NULL){
      printf("Irmão   : %d\n",irmao->info);
    }
  }
}
//---------------------------------------------------------------
void showTree(No *raiz){
  if (raiz == NULL){
    return;
  }

  int height = getHeight(raiz);
  int inicio = 0;
  int fim = (pow(2,height)-1)/2;
  int **matrizNum = (int **) calloc (height,sizeof(int*));

  if(matrizNum == NULL){
     puts("Alocação Falhou!");
     exit(1);
  }

  for (int i = 0; i < (height); i++){
     *(matrizNum+i) = (int*)calloc(pow(2,height)-1,sizeof(int));

     if(*(matrizNum+i) == NULL){
        puts("Alocação Falhou!");
        exit(1);
     }
  }

  char **matrizBarra = (char **) calloc (height-1,sizeof(char*));

  if(matrizBarra == NULL){
     puts("Alocação Falhou!");
     exit(1);
  }

  for (int i = 0; i < (height-1); i++){
     *(matrizBarra+i) = (char*)calloc(pow(2,height)-1,sizeof(char));

     if(*(matrizBarra+i) == NULL){
        puts("Alocação Falhou!");
        exit(1);
     }
  }

  for (int i = 0; i < height-1; i++){
    for (int j = 0; j < pow(2,height)-1; j++){
      matrizBarra[i][j] = ' ';
    }
  }

  encheMatriz(matrizNum,matrizBarra,raiz,height,0,(pow(2,height)-1)/2);

  retiraEspacos(matrizBarra, height, &inicio, &fim);

  for (int j = inicio; j <= fim; j++){
    if (j != (int)(pow(2,height)-1)/2){
      printf(" ");
    }

    else{
      printf("%d",matrizNum[0][j]);
    }
  }

  printf("\n");

  for (int i = 0; i < height-1; i++){
    for (int j = inicio; j <= fim; j++){
      if (matrizBarra[i][j] == '/' || matrizBarra[i][j] == '\\'){
        for(int aux = matrizNum[i+1][j]/10; aux != 0; aux = aux/10){
          printf(" ");
        }
        printf("%c",matrizBarra[i][j]);
      }

      else{
        printf(" ");
      }
    }
    printf("\n");

    for (int j = inicio; j <= fim; j++){
      if (matrizBarra[i][j] == '/' || matrizBarra[i][j] == '\\'){
        printf("%d",matrizNum[i+1][j]);
      }

      else{
        printf("%c",matrizBarra[i][j]);
      }
    }
    printf("\n");
  }
  puts("");

   for(int i=0; i < height; i++){
      free(*(matrizNum+i));
   }

   free(matrizNum);

   for(int i=0; i < height-1; i++){
      free(*(matrizBarra+i));
   }

   free(matrizBarra);

}
//---------------------------------------------------------------
void encheMatriz(int **matrizNum,char **matrizBarra,No *raiz,int altura,int linha,int coluna){
  int aux = pow(2,altura-2-linha);
  * (*(matrizNum+linha)+coluna) = raiz->info;

  if (raiz->esq != NULL){
    * (*(matrizBarra+linha)+coluna-aux) = '/';
    encheMatriz(matrizNum,matrizBarra,raiz->esq,altura,linha+1,coluna-aux);
  }

  if (raiz->dir != NULL){
    * (*(matrizBarra+linha)+coluna+aux) = '\\';
    encheMatriz(matrizNum,matrizBarra,raiz->dir,altura,linha+1,coluna+aux);
  }
}
//---------------------------------------------------------------
void retiraEspacos(char **matrizBarra,int height, int *inicio, int *fim){
  for (int j = 0; j < pow(2,height)-1; j++){
    for (int i = 0; i < height-1; i++){
      if (matrizBarra[i][j] == '/' || matrizBarra[i][j] == '\\'){
        if (! *inicio) {
          *inicio = j;
        }

        if (*fim < j) {
          *fim = j;
        }
      }
    }
  }
}
//---------------------------------------------------------------

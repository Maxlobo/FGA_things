/*
  Érico Bandeira - 16/0070287
  Luciana Ribeiro Lins de Albuquerque - 15/0016131
  Max Henrique Barbosa - 16/0047013

*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void fneuronio(double *, double *, double , int, int *);

int main() {
  double ENTRADAS[MAX], PESOS[MAX];
  double T;
  int i, resultado;

  printf("Digite 10 números de entrada: \n");
  for(i = 0; i < MAX; i++){
    scanf("%lf", &ENTRADAS[i]);
  }
  printf("Digite 10 números de pesos: \n");
  for(i = 0; i < MAX; i++){
    scanf("%lf", &PESOS[i]);
    while(PESOS[i] < 0){
      printf("Valor inválido. Insira novamente:\n");
      scanf("%lf", &PESOS[i]);
    }
  }
  printf("Digite o valor do limiar T: ");
  scanf("%lf", &T);

  fneuronio(ENTRADAS, PESOS, T, MAX, &resultado);

  if(!(resultado)){
    printf("\n Neurônio inibido! \n\n");
  }
  else{
    printf("\n Neurônio ativado!");
    printf("\n\n");
  }

  return 0;
}

void fneuronio(double *ENTRADAS, double *PESOS, double T, int N, int *resultado){
  int k;
  double SOMAP=0;
  for(k = 0 ; k < N ; k++){
    SOMAP += (ENTRADAS[k] * PESOS[k]);
  }

  if(SOMAP <= T){
    *resultado = 0;
  }
  else{
    *resultado = 1;
  }

}

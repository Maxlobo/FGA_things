
/*
    Érico Bandeira - 16/0070287
    Luciana Ribeiro Lins de Albuquerque - 15/0016131
    Max Henrique Barbosa - 16/0047013
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define UnTempo 5

//-----------------------------------------------------
/*STRUCTS*/
typedef struct aviao {
  int id;
  char tipo;
  int combustivel;
} Aviao;

typedef struct lista {
  Aviao aviao;
  struct lista* ant;
  struct lista* prox;
} Lista;

typedef struct fila {
  Lista* ini;
  Lista* fim;
} Fila;

//-----------------------------------------------------
/* Declarção de Funções*/
Lista *insere_inicio (Lista*,Aviao*);
Lista *insere_fim (Lista*,Aviao*);
Lista *retira_inicio (Lista*);
Lista *retira_fim (Lista*);
Lista *busca(Fila *f);

void fila_insere_inicio (Fila*);
void fila_insere_fim (Fila* f, int n, int *auxDeco,int *auxAprox,int nAproximacoes,int nDecolagens);
void mostrar_tela (Fila* f);
void verificarTempo(Fila*, int);
void combustivel (Fila *f,int n);
void emergencia(Fila* f, int id, char tipo, int combustivel);
void evento (Fila* f, int nVoos, int *tempo, char cod[64][6]);

Aviao fila_retira_inicio (Fila*);
Aviao fila_retira_fim (Fila*);

Fila* cria_fila ();
Fila* retira (Fila *f);

char geraVoo(int *auxDeco,int *auxAprox,int nAproximacoes,int nDecolagens);

int numeroDecolagem();
int rand12();
int busca_todos(Fila *f);
int relogio(int t,int n);

//-----------------------------------------------------
/*Nossa querida Main*/

int main(int argc, char const *argv[]) {

  char codVoos[64][6] =  {"VG3001", "JJ4404", "LN7001", "TG1501", "GL7602", "TT1010", "AZ1009",
							"AZ1008", "AZ1010", "TG1506", "VG3002", "JJ4402", "GL7603", "RL7880",
							"AL0012", "TT4544", "TG1505", "VG3003", "JJ4403", "JJ4401", "LN7002",
							"AZ1002", "AZ1007", "GL7604", "AZ1006", "TG1503", "AZ1003", "JJ4403",
							"AZ1001", "LN7003", "AZ1004", "TG1504", "AZ1005", "TG1502", "GL7601",
							"TT4500", "RL7801", "JJ4410", "GL7607", "AL0029", "VV3390", "VV3392",
							"GF4681", "GF4690", "AZ1020", "JJ4435", "VG3010", "LF0920", "AZ1065",
							"LF0978", "RL7867", "TT4502", "GL7645", "LF0932", "JJ4434", "TG1510",
							"TT1020", "AZ1098", "BA2312", "VG3030", "BA2304", "KL5609", "KL5610",
							"KL5611"};

int nVoos,nAproximacoes,nDecolagens,combA,aux,tempo = 1000;
int auxAprox=0;
int auxDeco=0;

Lista *l;
Fila *f,*auxiliar;
srand(time(NULL));

f = cria_fila();
nAproximacoes=numeroDecolagem();
nDecolagens=numeroDecolagem();

nVoos = nAproximacoes + nDecolagens;

for(aux = 0; aux < nVoos; aux++){
	fila_insere_fim(f,aux+1,&auxDeco,&auxAprox,nAproximacoes,nDecolagens);
}

printf("===========================================================\n");
puts("||Aeroporto Internacional de Brasília                    ||");
puts("||Hora Inicial: 10:00                                    ||");
puts("||Fila de Pedidos:[código do voo – P/D –prioridade]      ||");
printf("||Numero de Voos: %d                                     ||\n",nVoos);
printf("||Numero de Aproximacoes: %d                             ||\n",nAproximacoes);
printf("||Numero de Decolagens: %d                               ||\n",nDecolagens);
printf("===========================================================\n");
evento(f,nVoos,&tempo,codVoos);
free(f);
return 0;
}

//-----------------------------------------------------
/*Funções*/
int numeroDecolagem(){
  srand(time(NULL));
  return 10+(rand() % (22)) + 1;
}
//-------------------------------------------------------
int rand12(){

  return (rand() % (13));
}
//-------------------------------------------------------
char geraVoo(int *auxDeco,int *auxAprox,int nAproximacoes,int nDecolagens){ //PRECISO ENTENDER
	int n;
  n = rand() % (2);
	if (*auxAprox == nAproximacoes) {
		*auxDeco += 1;
		return 'D';
	}
	if (*auxDeco == nDecolagens) {
		*auxAprox += 1;
		return 'A';
	}
	if(n == 0){
		*auxAprox += 1;
		return 'A';
	}
	if(n == 1){
		*auxDeco += 1;
		return 'D';
	}
}
//-------------------------------------------------------
Lista *insere_inicio (Lista* ini, Aviao *i) { //Aux
   Lista* novo = (Lista*) malloc(sizeof(Lista));
   novo->aviao = *i;
   novo->prox = ini;
   novo->ant = NULL;
   if (ini != NULL){
     ini->ant = novo;
   }
   return novo;
}
//--------------------------------------------------------
Lista *insere_fim (Lista* fim, Aviao *i) { //Aux
   Lista* novo = (Lista*) malloc(sizeof(Lista));
   novo->aviao = *i;
   novo->prox = NULL;
   novo->ant = fim;
   if (fim != NULL){
      fim->prox = novo;
   }
   return novo;
}
//--------------------------------------------------------
Lista *retira_inicio (Lista* ini) { //Aux
   Lista* p = ini->prox;
   if (p != NULL){
     p->ant = NULL;
   }
   free(ini);
   return p;
}
//--------------------------------------------------------
Lista *retira_fim (Lista* fim) { //Aux
   Lista* p = fim->ant;
   if (p != NULL){
     p->prox = NULL;
   }
   free(fim);
   return p;
}
//-------------------------------------------------------
Fila* cria_fila (){
   Fila* f = (Fila*) malloc(sizeof(Fila));
   f->ini = f->fim = NULL;
   return f;
}
//-------------------------------------------------------
void fila_insere_inicio (Fila* f) {
	 Aviao *i = (Aviao*)calloc(1,sizeof(Aviao));
   f->ini = insere_inicio(f->ini,i);
   if (f->fim==NULL){
     f->fim = f->ini;
   }
}
//-------------------------------------------------------
void fila_insere_fim (Fila* f, int n, int *auxDeco,int *auxAprox,int nAproximacoes,int nDecolagens) {
	 Aviao *i = (Aviao*)calloc(1,sizeof(Aviao));

   i->id = n;
	 i->tipo = geraVoo(auxDeco,auxAprox,nAproximacoes,nDecolagens);
	 if(i->tipo == 'A'){
		 i->combustivel = rand12();
	 }

   f->fim = insere_fim(f->fim,i);
   if (f->ini==NULL){
      f->ini = f->fim;
   }
}
//-------------------------------------------------------
Aviao fila_retira_inicio (Fila* f) {
   Aviao v;
   if (f->ini == NULL) {
      printf("Fila vazia.\n");
      exit(1);
   }
   v = f->ini->aviao;
   f->ini = retira_inicio(f->ini);
   if (f->ini == NULL){
      f->fim = NULL;
   }
   return v;
}
//-------------------------------------------------------
Aviao fila_retira_fim (Fila* f) {
   Aviao v;
   if (f->ini == NULL) {
      printf("Fila vazia.\n");
      exit(1);
   }
   v = f->fim->aviao;
   f->fim = retira_fim(f->fim);
   if (f->fim == NULL){
     f->ini = NULL;
   }
   return v;
}
//-------------------------------------------------------
void mostrar_tela (Fila* f){
   Lista* q;
   for (q=f->ini; q!=NULL; q=q->prox)
      printf("[%d %c %d] ",q->aviao.id,q->aviao.tipo,q->aviao.combustivel);
}
//-------------------------------------------------------
Fila* retira(Fila *f){

	Lista *q = busca(f);

	if(q == NULL){
		return f;
	}

	if (f->ini == q){
		f->ini = q->prox;
  }
	else {
		q->ant->prox = q->prox;
   }
	if (q->prox != NULL){
    q->prox->ant = q->ant;
  }

	emergencia(f,q->aviao.id,q->aviao.tipo,q->aviao.combustivel);
	free(q);
	return f;
}
//-------------------------------------------------------
void combustivel(Fila *f,int n){
	Lista *q;
	int combInicial=0;
	for(q=f->ini; q!=NULL; q=q->prox)
		q->aviao.combustivel-=1*n;
		combInicial = busca_todos(f);
		for(int aux = 0; aux < combInicial; aux++){
			f = retira(f);
		}
}
//-------------------------------------------------------
void emergencia(Fila* f, int id, char tipo, int combustivel){
	Aviao *i = (Aviao*)calloc(1,sizeof(Aviao));
	i->id = id;
	i->tipo = tipo;
	i->combustivel = combustivel;
	f->ini = insere_inicio(f->ini,i);
	if (f->fim==NULL){
		f->fim = f->ini;
  }
}
//-------------------------------------------------------
Lista* busca(Fila *f){
	Lista *q;
	for(q=f->fim; q!=NULL; q = q->ant)
		if(q->aviao.tipo == 'A')
			if(q->aviao.combustivel <= 0)
				return q;
	return NULL;
}
//-------------------------------------------------------
int busca_todos(Fila *f){
	Lista *q;
	int total=0;
	for(q=f->fim; q!=NULL; q=q->ant)
		if(q->aviao.tipo == 'A')
			if(q->aviao.combustivel <= 0)
				total++;
	return total;
}
//-------------------------------------------------------
void evento (Fila* f, int nVoos, int *tempo, char cod[64][6]){
	int pistasEmUso[3] = {0,0,0};
	int tempoPistas[3] = {0,0,0};
	int pistaAtual, contadorDaMorte = 0;
	int combInicial=0;
	char codigo[7],strTempo[5];
	combInicial = busca_todos(f);
	for(int aux = 0; aux < combInicial; aux++){
		f = retira(f);
	}


	for(int i = 0; i < nVoos; i ++){
		if(f->ini->aviao.combustivel < 0 && f->ini->aviao.tipo == 'A'){
			for(int j = 0; j < 6; j++){
				codigo[j] = cod[i][j];
			}
			printf("Código do Voo: %s / %d\n",codigo,f->ini->aviao.id);
			printf("Status: ALERTA CRÍTICO, AERONAVE IRÁ CAIR\n\n");
			fila_retira_inicio(f);
		}
		else {
  			if(tempoPistas[0] == 0){
				printf("\n\n");
  				pistaAtual = 1;
  				pistasEmUso[0] = 1;
  			}else if(tempoPistas[1] == 0){
 				printf("\n\n");
  				pistaAtual = 2;
  				pistasEmUso[1] = 1;
  			}else if((tempoPistas[2] == 0 && f->ini->aviao.tipo == 'D') || (tempoPistas[2] == 0  && f->ini->aviao.tipo == 'A' && f->ini->aviao.combustivel == 0)){
 				printf("\n\n");
  				pistaAtual = 3;
  				pistasEmUso[2] = 1;
  			}else {
				if(tempoPistas[0] <= tempoPistas[1] && tempoPistas[0] <= tempoPistas[2] ){
					verificarTempo(f,*tempo);
					*tempo =relogio(*tempo,tempoPistas[0]);
					tempoPistas[1] -= tempoPistas[0];
					tempoPistas[2] -= tempoPistas[0];
					tempoPistas[0] = 0;
					pistaAtual = 1;
 					printf("\n\n");
				}else if(tempoPistas[1] <= tempoPistas[0] && tempoPistas[1] <= tempoPistas[2]){
					verificarTempo(f,*tempo);
  					*tempo =relogio(*tempo,tempoPistas[1]);
  					tempoPistas[0] -= tempoPistas[1];
  					tempoPistas[2] -= tempoPistas[1];
  					tempoPistas[1] = 0;
  					pistaAtual = 2;
 					printf("\n\n");
				}else if((tempoPistas[2] <= tempoPistas[0] && tempoPistas[2] <= tempoPistas[1] && f->ini->aviao.tipo == 'D') ){
					verificarTempo(f,*tempo);
  					tempoPistas[0] -= tempoPistas[2];
  					tempoPistas[1] -= tempoPistas[2];
  					tempoPistas[2] = 0;
  					pistaAtual = 3;
 					printf("\n\n");
				}else {
					if(tempoPistas[0] <= tempoPistas[1]){
						verificarTempo(f,*tempo);
  						*tempo =relogio(*tempo,tempoPistas[0]);
  						tempoPistas[1] -= tempoPistas[0];
  						tempoPistas[0] = 0;
  						pistaAtual = 1;
 						printf("\n\n");
					}else {
						verificarTempo(f,*tempo);
  						*tempo =relogio(*tempo,tempoPistas[1]);
  						tempoPistas[0] -= tempoPistas[1];
  						tempoPistas[1] = 0;
  						pistaAtual = 2;
						printf("\n\n");
					}
				}
			}
			if(f->ini->aviao.combustivel < 0 && f->ini->aviao.tipo == 'A'){
				for(int j = 0; j < 6; j++){
					codigo[j] = cod[i][j];
				}
				printf("Código do Voo: %s / %d\n",codigo,f->ini->aviao.id);
				printf("Status: ALERTA CRÍTICO, AERONAVE IRÁ CAIR\n\n");
				fila_retira_inicio(f);
			}else {
				for(int j = 0; j < 6; j++){
					codigo[j] = cod[i][j];
				}
				printf("Código do Voo: %s / %d\n",codigo,f->ini->aviao.id);
				if(f->ini->aviao.tipo == 'A'){
					printf("Status: [Aeronave Pousou]\n");
					if(pistaAtual == 1){
						tempoPistas[0] += 4*UnTempo;
					}else if(pistaAtual == 2){
						tempoPistas[1] += 4*UnTempo;
					}else if(pistaAtual == 3){
						tempoPistas[2] += 4*UnTempo;
					}
				}
				else{
					printf("Status: [Aeronave Decolou]\n");
					if(pistaAtual == 1){
						tempoPistas[0] += 2*UnTempo;
					}else if(pistaAtual == 2){
						tempoPistas[1] += 2*UnTempo;
					}else if(pistaAtual == 3){
						tempoPistas[2] += 2*UnTempo;
					}
				}
				strcpy(strTempo,"");
				snprintf(strTempo,5, "%d",*tempo);


				printf("Horário inicial: %c%c:%c%c\n",strTempo[0],strTempo[1],strTempo[2],strTempo[3]);
				printf("Pista: %d\n\n\n",pistaAtual);

				fila_retira_inicio(f);
			}
		}
	}
}
//-------------------------------------------------------
int relogio(int t,int n){
	int resultado;
	if(t < 1100){
		if(n+(t-1000) < 60){
			resultado = t+n;
		}else if(n+(t-1000) == 60){
			resultado = t +  (40 + n);
		}else if(n+(t-1000) > 60){
			resultado = t +  (40 + n) + 10;
		}
	}else if(t < 1200){
		if(n+(t-1100) < 60){
			resultado = t+n;
		}else if(n+(t-1100) == 60){
			resultado =t +  (40 + n);
		}else if(n+(t-1100) > 60){
			resultado = t +  (40 + n) + 10;
		}
	}else if(t < 1300){
		if(n+(t-1200) < 60){
			resultado = t+n;
		}else if(n+(t-1200) == 60){
			resultado =t +  (40 + n);
		}else if(n+(t-1200) > 60){
			resultado = t +  (40 + n) + 10;
		}
	}else if (t < 1400){
		if(n+(t-1300) < 60){
			resultado = t+n;
		}else if(n+(t-1300) == 60){
			resultado =t +  (40 + n);
		}else if(n+(t-1300) > 60){
			resultado = t +  (40 + n) + 10;
		}
	}
	return resultado;
}
//-------------------------------------------------------
void verificarTempo(Fila *f, int tempo){
   if(tempo >= 1050 && tempo < 1140){
 		combustivel(f,1);
 	}else if(tempo >= 1140 && tempo < 1230){
 		combustivel(f,1);
 	}else if(tempo >= 1230 && tempo < 1320){
 		combustivel(f,1);
 	}else if(tempo >= 1320 && tempo < 1410){
 		combustivel(f,1);
 	}else if(tempo >= 1410 && tempo < 1500){
 		combustivel(f,1);
 	}
 }
//-------------------------------------------------------

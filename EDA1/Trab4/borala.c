/*
    Érico Bandeira - 16/0070287
    Luciana Ribeiro Lins de Albuquerque - 15/0016131
    Max Henrique Barbosa - 16/0047013
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct aeronave {
    char tipo;
    int id;
    int combustivel;
} Aeronave;

typedef struct lista {
    Aeronave aero;
    struct Lista* prox;
    struct Lista* ant;
} Lista;

typedef struct fila {
    Lista *ini;
    Lista *fim;
} Fila;


Fila *cria();
Lista *insere_fim(Lista* fim, Aeronave *info);
void insere(Fila *f, int i, int nAproximações, int nDecolagens);
int geraAleatorio();
char geraVoo(int *deco,int *aprox,int nAproximacoes,int nDecolagens);
int rand12();
Lista *insere_inicio (Lista* ini, Aviao *i);
void fila_insere_inicio (Fila* f);


int main(){

    Fila *fila;

    printf("---------------------------------------------------------------------------------\n");
    printf("Aeroporto Internacional de Braslia\n");
    printf("Hora Inicial: \n");
    printf("Fila de Pedidos: [código do voo – P/D – prioridade]\n");
    printf("NVoos: \n");
    printf("Naproximações: \n");
    printf("NDecolagens: \n");
    printf("---------------------------------------------------------------------------------\n");

    fila = cria();

    int i;
    int nVoos, nAproximações, nDecolagens;
    char codigos[64][6] = {
            "VG3001", "JJ4404", "LN7001", "TG1501", "GL7602", "TT1010", "AZ1009", "AZ1008",
            "AZ1010", "TG1506", "VG3002", "JJ4402", "GL7603", "RL7880", "AL0012", "TT4544",
            "TG1505", "VG3003", "JJ4403", "JJ4401", "LN7002", "AZ1002", "AZ1007", "GL7604",
            "AZ1006", "TG1503", "AZ1003", "JJ4403", "AZ1001", "LN7003", "AZ1004", "TG1504",
            "AZ1005", "TG1502", "GL7601", "TT4500", "RL7801", "JJ4410", "GL7607", "AL0029",
            "VV3390", "VV3392", "GF4681", "GF4690", "AZ1020", "JJ4435", "VG3010", "LF0920",
            "AZ1065", "LF0978", "RL7867", "TT4502", "GL7645", "LF0932", "JJ4434", "TG1510",
            "TT1020", "AZ1098", "BA2312", "VG3030", "BA2304", "KL5609", "KL5610", "KL5611"
         };

    nAproximações = geraAleatorio();
    nDecolagens = geraAleatorio();

    nVoos = nAproximações + nDecolagens;

    for(i=0;i<nVoos;i++){
      insere(f, i, nAproximações, nDecolagens);
    }

    return 0;
}

Fila *cria(){
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    fila->ini = fila->fim = NULL;
    // printf("Criou");
    return fila;
}



Lista *insere_fim(Lista* fim, Aeronave *info){
    Lista* p = (Lista*) malloc(sizeof(Lista));
    p->aero = *info;
    p->prox = NULL;
    p->ant = fim;
    if(fim != NULL){
        fim->prox = p;
    }
    return p;
}

void insere(Fila *f, int i, int nAproximações, int nDecolagens){
    Aeronave *aero = (Aeronave*)calloc(1, sizeof(Aeronave));

    aero->id = i;
    aero->tipo = geraVoo(deco, aprox, nAproximacoes, nDecolagens);
    if(aero->tipo == 'A'){
      aero->combustivel = rand12();
    }

    f->fim = insere_fim(f->fim, v);
    if(f->ini == NULL){
        f->ini = f->fim;
    }
}

int geraAleatorio(){
    srand(time(NULL));
    return 10 + (rand()%(22)) + 1;
}

char geraVoo(int *deco,int *aprox,int nAproximacoes,int nDecolagens){
	int n;
  n = rand() % (2);
	if (*aprox == nAproximacoes) {
		*deco += 1;
		return 'D';
	}
	if (*deco == nDecolagens) {
		*aprox += 1;
		return 'A';
	}
	if(n == 0){
		*aprox += 1;
		return 'A';
	}
	if(n == 1){
		*deco += 1;
		return 'D';
	}
}

int rand12(){
  return (rand() % (13));
}

Lista *insere_inicio (Lista* ini, Aviao *i) { //Aux
   Lista* novo = (Lista*) malloc(sizeof(Lista));
   novo->aero = *i;
   novo->prox = ini;
   novo->ant = NULL;
   if (ini != NULL){
     ini->ant = novo;
   }
   return novo;
}

void fila_insere_inicio (Fila* f) {
	 Aviao *i = (Aviao*)calloc(1,sizeof(Aeronave));
   f->ini = insere_inicio(f->ini,i);
   if (f->fim==NULL){
     f->fim = f->ini;
   }
}

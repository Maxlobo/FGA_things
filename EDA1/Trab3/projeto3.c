/*
    Érico Bandeira - 16/0070287
    Luciana Ribeiro Lins de Albuquerque - 15/0016131
    Max Henrique Barbosa - 16/0047013
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct contato {
  char name[101];
  char cel[11];
  char adress[101];
  int cep;
  char date[11];

  struct contato *prox;
  struct contato *ante;
} Contato;

Contato *readFile();
Contato *newInsert(Contato *list);
Contato *insertSort(Contato *position, Contato *list);
void *search(Contato *list, char name[]);
void leString (char * s);
void save(Contato *list);
void listAll(Contato *list);
Contato *removeData(Contato *list, char name[]);

int main() {
  FILE *fp;
  Contato *list;
  int sel;
  char c, searchName[101];

  if(list = (Contato*)malloc(sizeof(Contato)), list == NULL){
    printf("Erro ao alocar!\n");
  }

  list = readFile();
  system("clear");

  do {

    printf("\n=========================================================================\n");
    printf("||\t0. Sair                                                        ||\n");
    printf("||\t1. Inserir novo registro                                       ||\n");
    printf("||\t2. Remover registros por nome                                  ||\n");
    printf("||\t3. Visualizar registros por nome                               ||\n");
    printf("||\t4. Visualizar todos os registros                               ||\n");
    printf("=========================================================================\n\n");

    printf("Resposta: ");
    scanf("%d",&sel);

    switch(sel){
      case 1:
        list = newInsert(list);
      break;

      case 2:
        printf("Digite o nome do contato a ser removido: \n");
        scanf("%s", searchName);
        list = removeData(list, searchName);
      break;

      case 3:
        printf("Digite o nome do contato a ser procurado: \n");
        scanf("%s", searchName);
        search(list, searchName);
      break;

      case 4:
        listAll(list);
      break;

      default:
        if(fp = fopen("contatos.txt", "w"), fp == NULL){
          printf("Falha ao abrir o arquivo!\n");
          exit(1);
        }
        save(list);
        fclose(fp);
    }

    system("clear");

  } while(sel != 0);

  return 0;
}

void leString (char * s){
	int i;
	i = getchar();

	if(i == '\n'){
		i = getchar();
	}
	while (i != '\n'){
		*s = i;
		++s;
		i = getchar();
	}
	s = '\0';
}

Contato *readFile(){
  FILE *fp;
  Contato *data, *firstPosition=NULL;
  char dollar;

  if(fp = fopen("contatos.txt", "r+"), fp == NULL){
    printf("Falha ao abrir o arquivo!\n");
    exit(1);
  }

  while(!feof(fp)){
    if(data = (Contato*)malloc(sizeof(Contato)), data == NULL){
      printf("Erro ao alocar!\n");
    }

    fscanf(fp, "%[^\n]\n%s\n%[^\n]\n%u\n%s\n%c\n",
           data->name,
           data->cel,
           data->adress,
           &data->cep,
           data->date,
           &dollar);

    firstPosition = insertSort(firstPosition, data);

  }
  fclose(fp);
  return firstPosition;
}

Contato *insertSort(Contato *position, Contato *data){
  Contato *num;

  for(num=position; num!=NULL; num=num->prox){
    if(strcasecmp(num->name, data->name) > 0){
      data->prox = num;
      data->ante = num->ante;
      num->ante = data;

      if(data->ante != NULL){
        data->ante->prox = data;
      } else {
        position = data;
      }
      return position;
    }
    if(num -> prox == NULL){
      data -> prox = NULL;
      data -> ante = num;
      num -> prox = data;
      return position;
    }
  }

if(position==NULL)
  return data;
  free(num);
}

Contato *newInsert(Contato *list){
  Contato *newData;
  char day, month, year;

  if(newData = (Contato*)malloc(sizeof(Contato)), newData == NULL){
    printf("Erro ao alocar!\n");
  }

  printf("Insira o nome do novo contato:\n");
  scanf("%[^\n]",newData->name);
  leString (newData->name);

  printf("Insira o telefone do novo contato:\n");
  scanf("%[^\n]",newData->cel);
  leString (newData->cel);

  printf("Insira o endereco do novo contato:\n");
  scanf("%[^\n]",newData->adress);
  leString (newData->adress);

  printf("Insira o CEP do novo contato:\n");
  scanf("%u",&newData->cep);

  printf("Insira a data de nascimento do novo contato:\n");
  scanf("%[^\n]",newData->date);
  leString (newData->date);

  list = insertSort(list, newData);

  free(newData);
  return list;
}

void save(Contato *list){
  FILE *fp;
  Contato *num;

  if(fp = fopen("contatos.txt", "w+"), fp == NULL){
    printf("Falha ao abrir o arquivo!\n");
    exit(1);
  }

  for(num=list; num != NULL; num = num->prox){
    fprintf(fp, "%s\n", list->name);
    fprintf(fp, "%s\n", list->cel);
    fprintf(fp, "%s\n", list->adress);
    fprintf(fp, "%d\n", list->cep);
    fprintf(fp, "%s\n", list->date);
    fprintf(fp, "$\n");

    if(num != list){
      free(num->ante);
    }
  }

  free(num);
  free(fp);
  fclose(fp);
}

void *search(Contato *list, char name[]){
  Contato *p;
  int count=0;
	for(p=list; p!=NULL; p = p->prox){
      if (!strcasecmp(p->name, name)){
        printf("\n%s\n%s\n%s\n%u\n%s\n\n",
                p->name,
                p->cel,
                p->adress,
                p->cep,
                p->date);
        count++;
      }
  }
  if(count == 0){
    printf("Nome nao encontrado");
  }
  free(p);
}

void listAll(Contato *list) {
  Contato *p;

  for(p=list; p != NULL; p->prox){
    printf("\n%s\n%s\n%s\n%u\n%s\n\n",
            p->name,
            p->cel,
            p->adress,
            p->cep,
            p->date);
  }
  free(p);
}

Contato *removeData(Contato *list, char name[]){
	Contato *p = search(list, name);

  if (p == NULL)
    return 1; //Não achou um elemnto: retorna lista inalterada

  //retira elemento do encadeamento
  if (list == p)  //testa se é o primeiro elemnto
    list = p->prox;

  else
    p->ante->prox = p->prox;

  if (p->prox != NULL)  //teste se é o último elemnto
    p->prox->ante = p->ante;

  free(p);
  return list;
}

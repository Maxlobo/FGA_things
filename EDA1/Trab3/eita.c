Contatos busca(Contatos *list, char name){
	Contatos *p;
	for(p=1; p!=NULL; p = p->next){
      if (p->name = name)
        return p;
  return NULL; //não achou o elemento
	}
}

Contatos remove(Contatos *list, char name){
	Contatos *p = busca(list, name);

  if (p == NULL)
    return 1; //Não achou um elemnto: retorna lista inalterada

  //retira elemento do encadeamento

  if (list == p)  //testa se é o primeiro elemnto
    list = p->next;

  else
    p->ante->next = p->next;

  if (p->next != NUll)  //teste se é o último elemnto
    p->next->ant = p->ante;

  free(p);

  return list;
	}

  void imprimir(Contato *list){
    Contato *p;
    p = list->next;
    while(p != NULL){
      printf(fp, "%[^\n]\n%s\n%[^\n]\n%u\n%s\n%c\n",
             data->name,
             data->cel,
             data->adress,
             data->cep,
             data->date,
             dollar);

        p = p->next;
    }
}

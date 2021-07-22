#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

typedef struct Contador{
	void* endereco;
	int referencias;
	struct Contador* prox;
}contador;

contador* SetKila(){
	contador* lista = (contador*) malloc(sizeof(contador));
	lista->endereco=NULL;
	lista->prox=NULL;
	return lista;
}

contador* InsereCont(void* x, contador *lista){
	contador* aux = (contador*) malloc(sizeof(contador));
	contador* novo = (contador*) malloc(sizeof(contador));
	novo->endereco=x;
	novo->referencias=1;
	novo->prox=NULL;
	if(lista->prox==NULL){
		lista->prox=novo;
	}
	else{
		aux=lista->prox;
		while(aux->prox!=NULL)
			aux=aux->prox;
		aux->prox=novo;
	}	
}

void Atualiza(void* x, void* y, contador *lista){
	contador* aux = lista;
	contador* aux2 = lista->prox;
    while(aux2!=NULL && aux2->endereco!=x){
    	aux = aux->prox;
		aux2=aux2->prox;	
	}
    aux2->referencias--;
    if(aux2->referencias==0){
    	aux->prox=aux2->prox;
    	free(aux2);
	}
    
    aux = lista;
    while(aux!=NULL && aux->endereco!=y)
		aux = aux->prox;
	aux->referencias++;
}

void dump(contador* lista){
	setlocale(LC_ALL, "");
	if(lista==NULL){
		printf("\t*NENHUMA MEMÓRIA ALOCADA*\n");
	}
	else{
		contador* aux = (contador*) malloc(sizeof(contador));
		aux=lista->prox;
		printf("\tMEMÓRIAS ALOCADAS:\n\n");
		while(aux!=NULL){
			printf("Endereço: %d\n", aux->endereco);
			printf("Tamanho: %d byte(s)\n", _msize(aux->endereco));
			printf("Número de refências: %d\n", aux->referencias);
			printf("------------------\n");
			aux=aux->prox;
		}
	}
}

void* malloc2(size_t tam, contador* lista){
	
	void* x = malloc(tam);
	lista=InsereCont(x, lista);
	
	return x;
}

void* atrib2(void* x, void* y, contador* lista){
	/*printf("DENTRO DE ATRIB.\n");
	printf("End. registrado: x=%d, y=%d\n", x, y);
	printf("End.:x=%d, y=%d\n\n", &x, &y);*/
	Atualiza(x, y, lista);
	x=y;
	
	return x;	
}

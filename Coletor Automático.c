//Ayla Rodrigues e Sofia Kitaeva
//Coletor Automatico de lixo

#include <stdio.h>
#include <stdlib.h>

typedef struct Contador{
    void* endereco;
    int referencias;
    struct Contador* prox;
}contador;

contador* lista = (contador*) malloc(sizeof(contador));

contador* InsereCont(void* x){
    contador* aux = (contador*) malloc(sizeof(contador));
    contador* novo = (contador*) malloc(sizeof(contador));
    novo->endereco=x;
    novo->referencias=1;
    novo->prox==NULL;
    if(lista->prox==NULL)
        lista->prox=novo;
    else{
        contador* aux = (contador*) malloc(sizeof(contador));
        aux=lista->prox;
        while(aux!=NULL)
            aux=aux->prox;
        aux->prox=novo;
    }

            
}

void* malloc2(size_t tam){
    
    void* x = malloc(tam);
    lista=InsereCont(x);
    
    return x;
}

void atrib2(int *x, int *y){
    x = y;        
}

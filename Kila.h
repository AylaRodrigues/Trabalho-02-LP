#ifndef Kila_h
#define Kila_h

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

typedef struct Contador{
	void* endereco;
	int referencias;
	struct Contador* prox;
}contador;

contador* SetKila();

contador* InsereCont(void* x, contador *lista);

void Atualiza(void* x, void* y, contador *lista);

void dump(contador* lista);

void dump(contador* lista);

void* malloc2(size_t tam, contador* lista);

void* atrib2(void* x, void* y, contador* lista);

#endif

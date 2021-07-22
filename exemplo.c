#include <Kila.h>
#include <stdio.h>

int main(){
	contador* reg=SetKila();
	int *v=malloc2(sizeof(int), reg);
	*v=10;
	printf("v=%d\n", *v);
	int *w=malloc2(sizeof(int), reg);
	*w=20;
	printf("v=%d w=%d\n", *v, *w);
	
	printf("ANTES DE ATRIB.\n");
	printf("End. registrado: v=%d, w=%d\n", v, w);
	printf("End.:v=%d, w=%d\n", &v, &w);
	printf("Conteúdo:v=%d, w=%d\n\n", *v, *w);
	
	v=atrib2(v,w,reg);
	
	printf("DEPOIS DE ATRIB.\n");
	printf("End. registrado: v=%d, w=%d\n", v, w);
	printf("End.:v=%d, w=%d\n", &v, &w);
	printf("Conteúdo:v=%d, w=%d\n\n", *v, *w);
	
  int *c=malloc2(sizeof(char), reg);
	*c='b';
	printf("%c\n", *c);
	system("pause");
	system("cls");
	dump(reg);
	system("pause");
	
	return 0;
}

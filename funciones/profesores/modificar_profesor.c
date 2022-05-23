#ifndef MODIFICAR_PROFESOR_C
#define MODIFICAR_PROFESOR_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
void modificar_profesor(long int dato,int op,profesor **ini_profesor){
	int buscar,codigo;
	int encontrado = 0;
	// printf("\naaa\n");
	profesor *aux = *ini_profesor;
	while(aux != NULL && encontrado != 1){
		// printf("\nbbb\n");
		if(aux->dni == dato){
			// printf("\nccc\n");
			if(op==1){
				// printf("\nop1\n");
				fflush(stdin);
				gets(aux->nombre);
			}else if(op==2){
				// printf("\nop2\n");
				scanf("%ld",&aux->telefono);
			}
			encontrado = 1;
		}
		
		aux = aux->sgte;	
	}
	// printf("\nddd\n");
	// system("pause");
}


#endif

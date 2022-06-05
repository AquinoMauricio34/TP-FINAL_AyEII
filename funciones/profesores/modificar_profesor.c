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
	profesor *aux = *ini_profesor;
	while(aux != NULL && encontrado != 1){
		if(aux->dni == dato){
			if(op==1){
				fflush(stdin);
				gets(aux->nombre);
			}else if(op==2){
				scanf("%ld",&aux->telefono);
			}
			encontrado = 1;
		}
		
		aux = aux->sgte;	
	}
}


#endif

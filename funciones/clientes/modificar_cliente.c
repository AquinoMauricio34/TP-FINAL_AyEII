#ifndef MODIFICAR_CLIENTE_C
#define MODIFICAR_CLIENTE_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
void modificar_cliente(long int dato,int op,cliente **ini_cliente){
	int encontrado = 0;
	cliente *aux = *ini_cliente;
	while(*ini_cliente != NULL && encontrado != 1){
		
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
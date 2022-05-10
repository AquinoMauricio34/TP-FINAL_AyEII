#ifndef MODIFICAR_CLIENTE_C
#define MODIFICAR_CLIENTE_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
void modificar_cliente(long int dato,int op,cliente **ini_cliente){
	while(*ini_cliente != NULL){
		
		if((*ini_cliente)->dni == dato){
		
			if(op==1){
				fflush(stdin);
				gets((*ini_cliente)->nombre);
			}else if(op==2){
				scanf("%ld",&(*ini_cliente)->telefono);
			}
			*ini_cliente = NULL;
		}
		
		*ini_cliente = (*ini_cliente)->sgte;	
	}
}
#endif
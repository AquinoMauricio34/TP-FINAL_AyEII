#ifndef MODIFICAR_ACTIVIDAD_C
#define MODIFICAR_ACTIVIDAD_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
void modificar_actividad(long int dato,int op,actividad **ini_actividad){
	int encontrado = 0;
	actividad *aux = *ini_actividad;
	while(aux != NULL && encontrado != 1){
		
		if(aux->cod_act== dato){
		
			if(op==1){
				fflush(stdin);
				printf("NOMBRE DE LA ACTIVIDAD\n");
				printf("Nombre actual: ");puts(aux->nombre);
				printf("Nuevo nombre: ");
				fflush(stdin);
				gets(aux->nombre);
			}else if(op==2){
				printf("CANTIDAD DE CUPOS DE LA ACTIVIDAD\n");
				printf("Cantidad actual: %d\n",aux->cant_personas);
				printf("Nueva cantidad: ");
				scanf("%d",&aux->cant_personas);
			}else if(op==3){
				printf("SEDE DE LA ACTIVIDAD\n");
				printf("Sede actual: %d\n",aux->sede);
				printf("Nueva sede: ");
				scanf("%d",&aux->sede);
			}
			encontrado = 1;
		}
		
		aux = aux->sgte;	
	}
}
#endif
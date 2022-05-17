#ifndef MODIFICAR_ACTIVIDAD_C
#define MODIFICAR_ACTIVIDAD_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
void modificar_actividad(long int dato,int op,actividad **ini_actividad){
	while(*ini_actividad != NULL){
		
		if((*ini_actividad)->cod_act== dato){
		
			if(op==1){
				fflush(stdin);
				gets((*ini_actividad)->nombre);
			}else if(op==2){
				scanf("%ld",&(*ini_actividad)->cant_personas);
			}
			*ini_actividad = NULL;
		}
		
		*ini_actividad = (*ini_actividad)->sgte;	
	}
}
#endif
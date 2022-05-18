#ifndef GUARDADO_LISTAS_C
#define GUARDADO_LISTAS_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"

void guardado_listas(actividad *ini_actividad){
    guardado_actividad(ini_actividad);
}

void guardado_actividad(actividad *ini_actividad){
	FILE *a_actividades;
	if((a_actividades=fopen("actividades.dat","wb"))!=NULL){
		actividad c_actividad;
		actividad *aux = ini_actividad;
		while(aux != NULL){
			// printf("aux %s | %d | %d\n",aux->nombre,aux->cant_personas,aux->sede);
			fwrite(aux,sizeof(actividad),1,a_actividades);
			aux = aux->sgte;
		}

		fclose(a_actividades);
	}else{
		printf("El archivo no se pudo abrir.");
	}
}

#endif
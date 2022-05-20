#ifndef GUARDADO_LISTAS_C
#define GUARDADO_LISTAS_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"

void guardado_listas(actividad *ini_actividad,tipo_turno *ini_tipo_turno){
    guardado_actividad(ini_actividad);
	guardado_tipo_turno(ini_tipo_turno);
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

void guardado_tipo_turno(tipo_turno *ini_tipo_turno){
	FILE *a_tipo_turnos;
	if((a_tipo_turnos=fopen("tipo_turnos.dat","wb"))!=NULL){
		tipo_turno c_tipo_turno;
		tipo_turno *aux = ini_tipo_turno;
		while(aux != NULL){
			// printf("aux %s | %d | %d\n",aux->nombre,aux->cant_personas,aux->sede);
			fwrite(aux,sizeof(tipo_turno),1,a_tipo_turnos);
			aux = aux->sgte;
		}

		fclose(a_tipo_turnos);
	}else{
		printf("El archivo no se pudo abrir.");
	}
}

#endif
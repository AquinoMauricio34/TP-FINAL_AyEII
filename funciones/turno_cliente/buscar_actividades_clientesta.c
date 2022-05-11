#ifndef buscar_turno_C
#define buscar_turno_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
int buscar_actividades(int cod_act,int sede,actividad *ini_actividad){
	int buscar=0;
	while(ini_actividad != NULL){
		if(ini_actividad->cod_act == cod_act && ini_actividad->sede == sede){
			buscar = 1;
			ini_actividad = NULL;
		}else{
			buscar = 0;
			ini_actividad = ini_actividad->sgte;
		}
	}
	return (buscar);
}
#endif
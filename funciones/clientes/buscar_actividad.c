#ifndef buscar_actividades_C
#define buscar_actividades_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
int buscar_actividades(int codigo,actividad *ini_actividad){
	int buscar=0;
	while(ini_actividad != NULL){
		if(ini_actividad->cod_act == codigo){
			buscar = 1;
		}else{
			buscar = 0;
		}
		ini_actividad = ini_actividad->sgte;
	}
	
	return buscar;
}
#endif
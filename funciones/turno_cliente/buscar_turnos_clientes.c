#ifndef buscar_turno_C
#define buscar_turno_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"

int buscar_turno(int turno,int cod_actividad,tipo_turno *ini_turno){
	int buscar=0;
	// printf("\n111\n");
	while(ini_turno != NULL && buscar != 1){
		if(ini_turno->cod_turno == turno && ini_turno->cod_act == cod_actividad){
			buscar = 1;
			// printf("\nbbb\n");
		}
		// printf("\nccc\n");
		ini_turno = ini_turno->sgte;
		// printf("\nddd\n");
	}
	
	return buscar;
}

#endif
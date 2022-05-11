#ifndef buscar_turno_C
#define buscar_turno_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"

int buscar_turno(int turno,tipo_turno *ini_turno){
	int buscar=0;
	while(ini_turno != NULL){
		if(ini_actividad->cod_turno == turno){
			buscar = 1;
			ini_turno = NULL;
		}else{
			buscar = 0;
		}
		ini_turno = ini_turno->sgte;
	}
	
	return buscar;
}

#endif
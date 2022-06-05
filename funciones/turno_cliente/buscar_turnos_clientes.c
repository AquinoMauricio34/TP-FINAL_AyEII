#ifndef buscar_turno_C
#define buscar_turno_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"

int buscar_turno(int turno,int cod_actividad,tipo_turno *ini_turno){
	int buscar=0;
	while(ini_turno != NULL && buscar != 1){
		if(ini_turno->cod_turno == turno && ini_turno->cod_act == cod_actividad && ini_turno->estado == 1){
			buscar = 1;
		}
		ini_turno = ini_turno->sgte;
	}
	
	return buscar;
}

#endif
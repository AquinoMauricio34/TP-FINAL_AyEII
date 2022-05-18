#ifndef recorrer_turnos_C
#define recorrer_turnos_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
void recorrer_turnos(int cod_act,tipo_turno *ini_turno){
	int buscar=0;
	while(ini_turno != NULL){
		if(ini_turno->cod_act == cod_act){
			printf("%d,%f,%d",ini_turno->cod_turno,ini_turno->precio);//chequear VECTOR ini_turno->dias);
		}
		ini_turno = ini_turno->sgte;
	}
	
}
#endif
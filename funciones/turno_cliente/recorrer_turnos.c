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
			printf("cod_t: %7d | cod_act: %7d | precio: %.2f | est: %d\n",ini_turno->cod_turno,ini_turno->cod_act,ini_turno->precio,ini_turno->estado);
            printf("Dias %d-%d-%d-%d-%d\n",ini_turno->dias[0],ini_turno->dias[1],ini_turno->dias[2],ini_turno->dias[3],ini_turno->dias[4]);
            printf("Hora ini: %d:%d, Hora fin: %d:%d\n",ini_turno->hora_inicio_turno.hh,ini_turno->hora_inicio_turno.mm,ini_turno->hora_fin_turno.hh,ini_turno->hora_fin_turno.mm);
            printf("-----------\n");
		}
		ini_turno = ini_turno->sgte;
	}
	
}
#endif
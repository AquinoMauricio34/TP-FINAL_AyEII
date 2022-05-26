#ifndef LISTAR_RESERVAS_C
#define LISTAR_RESERVAS_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
void listar_reservas_actividad(actividad *ini_actividad,reserva *ini_reserva){
	int i=1,cod_act,cont=0;
	while(i <= 2){
		printf("sede %d \n",i);
		while(ini_actividad != NULL){
			if(ini_actividad->sede == i){
				cod_act = ini_actividad->cod_act;
                while(ini_reserva != NULL){
                    printf("\t %-7d %s",ini_actividad->cod_act,ini_actividad->nombre);
			
			    	ini_reserva = ini_reserva->sgte;
                }
				ini_actividad = ini_actividad->sgte;
			}
		}
		i++;
	}
}
#endif
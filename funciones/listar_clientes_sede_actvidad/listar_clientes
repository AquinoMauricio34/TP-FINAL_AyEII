#ifndef listar_clientes_C
#define listar_clientes_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
void listar_sede_actividades(actividad *ini_actividad,turno_cliente *ini_turno){
	int i=1,cod_act,cont=0;
	while(i <= 2){
		printf("sede %d \n",i);
		while(ini_actividad != NULL){
			if(ini_actividad->sede == i){
				cod_act = ini_actividad->cod_act;
				printf("\t %-7d %s",ini_actividad->cod_act,ini_actividad->nombre);
				if(ini_turno != NULL){
					if(ini_turno->cod_act == cod_act){
						cont++;
					}
					ini_turno = ini_turno->sgte;
				}
				printf("\t %-7d personas",cont);
				ini_actividad = ini_actividad->sgte;
			}
		}
		i++;
	}
}
#endif
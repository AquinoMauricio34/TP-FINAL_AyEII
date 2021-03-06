//Melani
#ifndef listar_clientes_C
#define listar_clientes_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
void listar_sede_actividades(actividad *ini_actividad,turno_cliente *ini_turno){
	int i=-1,cod_act,cont=0;
	actividad *aux_actividad=NULL;
	turno_cliente *aux_turno_cliente=NULL;
	while(i <= 2){
		if(i != 0){
			if(i!=-1){
				printf("Sede %d \n",i);
			}else
				printf("En todas las sedes\n");
			aux_actividad = ini_actividad;
			while(aux_actividad != NULL){
				if(aux_actividad->sede == i){
					cod_act = aux_actividad->cod_act;
					printf("\t %-7d %s |",aux_actividad->cod_act,aux_actividad->nombre);
					aux_turno_cliente = ini_turno;
					cont = 0;
					while(aux_turno_cliente != NULL){
						if(aux_turno_cliente->cod_act == cod_act && aux_turno_cliente->baja != 1){
							cont++;
						}
						aux_turno_cliente = aux_turno_cliente->sgte;
					}
					printf("\t %-4d personas\n",cont);
				}
				aux_actividad = aux_actividad->sgte;
			}
		}
		i++;
	}
}
#endif
//check
#ifndef LISTAR_CSAT_C
#define LISTAR_CSAT_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
void listar_sede_actividades_turno(actividad *ini_actividad,tipo_turno *ini_turno, turno_cliente *ini_turno_cliente){
	int i=-1,cod_act,cont=0;
	actividad *aux_actividad = NULL;
	tipo_turno *aux_tipo_turno = NULL;
	turno_cliente *aux_turno_cliente = NULL;
	while(i <= 2){
		if(i!=0){
			printf("Sede %d \n",i);
			aux_actividad = ini_actividad;
			while(aux_actividad != NULL){
				if(aux_actividad->sede == i){//debe incluir al -1
					cod_act = aux_actividad->cod_act;
					printf("\n\t%-7d | %s\n\n",aux_actividad->cod_act,aux_actividad->nombre);
					aux_tipo_turno = ini_turno;
					while(aux_tipo_turno != NULL){
						if(aux_tipo_turno->cod_act == cod_act){
							printf("\t\tCodigo: %d | Inicio: %d:%d | Fin: %d:%d | Dias: %d-%d-%d-%d-%d\n\n",aux_tipo_turno->cod_turno,aux_tipo_turno->hora_inicio_turno.hh,aux_tipo_turno->hora_inicio_turno.mm,aux_tipo_turno->hora_fin_turno.hh,aux_tipo_turno->hora_fin_turno.mm,aux_tipo_turno->dias[0],aux_tipo_turno->dias[1],aux_tipo_turno->dias[2],aux_tipo_turno->dias[3],aux_tipo_turno->dias[4]);
							aux_turno_cliente = ini_turno_cliente;
							while(aux_turno_cliente != NULL){
								if(aux_turno_cliente->cod_turno == aux_tipo_turno->cod_turno){
									printf("\t\t\t%-7d | ",aux_turno_cliente->dni);
									printf("%.2f\n",aux_turno_cliente->debe);
								}
								aux_turno_cliente = aux_turno_cliente->sgte;
							}

						printf("\n");
						}
						aux_tipo_turno = aux_tipo_turno->sgte;
					}
					
				}
				// printf("\n\n");
				aux_actividad = aux_actividad->sgte;
			}

		}
		i++;
	}
}
#endif
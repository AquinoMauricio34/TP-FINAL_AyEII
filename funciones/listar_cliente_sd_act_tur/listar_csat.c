//check
#ifndef LISTAR_CSAT_C
#define LISTAR_CSAT_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
void listar_sede_actividades_turno(actividad *ini_actividad,tipo_turno *ini_turno, turno_cliente *ini_turno_cliente){
	int i=-1,j,cod_act,cont=0,no_mostrar;
	char nombres_dias_sem[5][15]={"Lunes","Martes","Miercoles","Jueves","Vienes"};
	actividad *aux_actividad = NULL;
	tipo_turno *aux_tipo_turno = NULL;
	turno_cliente *aux_turno_cliente = NULL;
	while(i <= 2){
		if(i!=0){
			if(i!=-1){
				printf("Sede %d \n",i);
			}else
				printf("En todas las sedes\n");
			aux_actividad = ini_actividad;
			while(aux_actividad != NULL){
				if(aux_actividad->sede == i){
					cod_act = aux_actividad->cod_act;
					printf("\n\t%-7d | %s\n\n",aux_actividad->cod_act,aux_actividad->nombre);
					aux_tipo_turno = ini_turno;
					while(aux_tipo_turno != NULL){
						if(aux_tipo_turno->cod_act == cod_act){
							printf("\t\tCodigo: %d | Inicio: %d:%d | Fin: %d:%d | Dias: ",aux_tipo_turno->cod_turno,aux_tipo_turno->hora_inicio_turno.hh,aux_tipo_turno->hora_inicio_turno.mm,aux_tipo_turno->hora_fin_turno.hh,aux_tipo_turno->hora_fin_turno.mm);
							for(j=0;j<5;j++){
								if(aux_tipo_turno->dias[j]==1){
									printf("%s, ",nombres_dias_sem[j]);
								}
							}
							printf("\n\n");
							aux_turno_cliente = ini_turno_cliente;
							no_mostrar = 0;
							while(aux_turno_cliente != NULL){
								if(aux_turno_cliente->cod_turno == aux_tipo_turno->cod_turno){
									if(no_mostrar == 0){
										printf("\t\t\t%-7s | %s\n","DNI","DEBE");
										no_mostrar = 1;
									}
									printf("\t\t\t%-7d | %.2f\n",aux_turno_cliente->dni,aux_turno_cliente->debe);
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
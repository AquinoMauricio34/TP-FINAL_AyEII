#ifndef LISTAR_CSAT_C
#define LISTAR_CSAT_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
void listar_sede_actividades_turno(actividad *ini_actividad,turno_cliente *ini_turno, turno_cliente *ini_turno_cliente){
	int i=1,cod_act,cont=0;
	while(i <= 2){
		printf("sede %d \n",i);
		while(ini_actividad != NULL){
			if(ini_actividad->sede == i){
				cod_act = ini_actividad->cod_act;
                while(ini_turno != NULL){
                    printf("\t %-7d %s",ini_actividad->cod_act,ini_actividad->nombre);
					if(ini_turno->cod_act == cod_act){
						cont++;
					}
					ini_turno = ini_turno->sgte;
			    	while(ini_turno_cliente != NULL){
                       if(ini_turno_cliente->cod_turno == ini_turno->cod_turno){
                            printf("\n %ld \t",ini_turno_cliente->debe);
                            printf("\n %-7d \t",ini_turno_cliente->dni);
                        }
                    }
                }
				
			}
		}
		i++;
	}
}
#endif
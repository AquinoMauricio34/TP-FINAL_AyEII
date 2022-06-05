#ifndef buscar_actividades_clientesta_C
#define buscar_actividades_clientesta_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
int buscar_actividades_clientesta(int cod_act,int sede,actividad *ini_actividad,turno_cliente *ini_turno_cliente){
	int buscar=0,cont;
	turno_cliente *aux_t_cliente=NULL;
	while(ini_actividad != NULL && buscar!=1 && buscar!=-1){
		if(ini_actividad->cod_act == cod_act && ini_actividad->estado == 1 && (ini_actividad->sede == sede || ini_actividad->sede == -1)){
			aux_t_cliente = ini_turno_cliente;
			cont = 0;
			while(aux_t_cliente != NULL){

				if(aux_t_cliente->cod_act == ini_actividad->cod_act && aux_t_cliente->baja == 0){
					cont++;
				}

				aux_t_cliente = aux_t_cliente->sgte;
			}
			if(cont < ini_actividad->cant_personas){
				buscar = 1;
			}else
				buscar = -1;
		}
		ini_actividad = ini_actividad->sgte;
	}
	aux_t_cliente=NULL;
	return (buscar);
}
#endif
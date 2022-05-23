#ifndef buscar_actividades_clientesta_C
#define buscar_actividades_clientesta_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
int buscar_actividades_clientesta(int cod_act,int sede,actividad *ini_actividad){
	int buscar=0;
	printf("\naaa\n");
	while(ini_actividad != NULL && buscar!=1){
		printf("\nbbb\n");
		if(ini_actividad->cod_act == cod_act && ini_actividad->sede == sede){
			printf("\nccc\n");
			buscar = 1;
		}
		printf("\nddd\n");
		ini_actividad = ini_actividad->sgte;
		printf("\neee\n");
	}
	printf("\nfff\n");
	return (buscar);
}
#endif
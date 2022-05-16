#ifndef listar_actividades_sede_C
#define listar_actividades_sede_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"

void recorrer_actividades(int sede,actividad *ini){
	while(ini != NULL){
		if(*ini == sede){
		printf("%-10d| %s\n",ini->cod_act,ini->nombre);
		}
		ini = ini->sgte;
	}
}


#endif
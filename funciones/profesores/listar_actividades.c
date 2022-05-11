#ifndef listar_actividades_C
#define listar_actividades_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"

void listar_actividades(actividad *ini){
	while(ini != NULL){
		printf("%-10d| %s\n",ini->cod_act,ini->nombre);
		ini = ini->sgte;
	}
}


#endif

#ifndef BUSCAR_DNI_PROFESOR_C
#define BUSCAR_DNI_PROFESOR_C


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
int buscar_dni_profesor(long int dni,profesor *ini_profesor){
    int buscar=0;
	while(ini_profesor != NULL){
		if(ini_profesor->cod_act == dni){
			buscar = 1;
			ini_profesor = NULL;
		}else{
			buscar = 0;
		}
		ini_profesor = ini_profesor->sgte;
	}
	return buscar;
}
#endif
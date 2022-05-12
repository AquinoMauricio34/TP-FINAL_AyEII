#ifndef BUSCAR_DNI_CLIENTESTA_C
#define BUSCAR_DNI_CLIENTESTA_C


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
int buscar_dni_clientest(long int dni,turno_cliente *ini_clientesta){
    int buscar=0;
	while(ini_clientesta != NULL){
		if(ini_clientesta->dni == dni){
			buscar = 1;
			ini_clientesta = NULL;
		}else{
			buscar = 0;
		}
		ini_clientesta = ini_clientesta->sgte;
	}
	return buscar;
}
#endif
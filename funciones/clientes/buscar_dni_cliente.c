#ifndef BUSCAR_DNI_CLIENTE_C
#define BUSCAR_DNI_CLIENTE_C


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
int buscar_dni_cliente(long int dni,cliente *ini_cliente){
	// printf("\naaaa11\n");
    int buscar=0;
	while(ini_cliente != NULL && buscar != 1){
		// printf("\nbbbb\n");
		if(ini_cliente->dni == dni && ini_cliente->baja == 0){
			buscar = 1;
		}else{
			buscar = 0;
		}
		ini_cliente = ini_cliente->sgte;
	}
	// printf("\nccc\n");
	return buscar;
}
#endif
#ifndef BUSCAR_DNI_CLIENTE_C
#define BUSCAR_DNI_CLIENTE_C


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
int buscar_dni_cliente(long int dni,cliente *ini_cliente){
    int buscar=0;
	while(ini_cliente != NULL){
		if(ini_cliente->dni == dni){
			buscar = 1;
		}else{
			buscar = 0;
		}
		ini_cliente = ini_cliente->sgte;
	}
	return buscar;
}
#endif
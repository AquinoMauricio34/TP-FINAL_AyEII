#ifndef BUSCAR_DNI_RESERVA_C
#define BUSCAR_DNI_RESERVA_C


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
int buscar_dni_reserva(long int dni,reserva *ini_reserva){
    int encontrado=0;
	while(ini_reserva != NULL){
		if(ini_reserva->dni == dni){
			encontrado = 1;
		}else{
			encontrado = 0;
		}
		ini_reserva = ini_reserva->sgte;
	}
	
	return encontrado;
}
#endif
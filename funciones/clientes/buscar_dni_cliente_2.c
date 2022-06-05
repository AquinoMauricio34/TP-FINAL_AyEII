#ifndef BUSCAR_DNI_CLIENTE_2_C
#define BUSCAR_DNI_CLIENTE_2_C


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
int buscar_dni_cliente_2(long int dni,cliente **ini_cliente,turno_cliente *ini_turno_cliente){
    int encontrado=0,salir;
    cliente *aux_cliente=*ini_cliente;
	while(aux_cliente != NULL && encontrado != 1){
		if(dni == aux_cliente->dni){
	
			if(aux_cliente->baja == 1){
				printf("\nEl cliente esta registrado en el sistema, pero se encuentra dado de baja.\n");
				salir = 0;
				while(ini_turno_cliente != NULL && salir != 1){
					
					if(ini_turno_cliente->dni == dni && ini_turno_cliente->debe != 0){
						salir = 1;
					}
					ini_turno_cliente = ini_turno_cliente->sgte;
					
				}
				if(salir == 1){
					encontrado = 1;
					printf("NO PUEDE SER ACTIVIDADO, DEBIDO A QUE ADEUDA TURNO/S.\n");
					system("pause");
				}else{
					do{
						printf("Desea darlo de alta (1. SI | 0. NO)?");scanf("%d",&encontrado);
					}while(encontrado < 0 && encontrado > 1);
					if(encontrado == 1){
						encontrado = 2;		//para que tome el otro camino
                        aux_cliente->baja = 0;
                    }else
                        encontrado = 1;
				}
				
			}else
				encontrado = 1;

		}







		aux_cliente = aux_cliente->sgte;
	}
    aux_cliente = NULL;
	return encontrado;
}
#endif
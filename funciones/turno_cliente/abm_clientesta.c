#ifndef ABM_CLIENTESTA_C
#define ABM_CLIENTESTA_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
//ANALIZAR LOS CUPOS
void abm_clientes_ta(turno_cliente **ini_clientesta,tipo_turno **ini_turno,actividad *ini_actividad){
	tipo_turno *nv;
	int op,buscar_act,buscar_turno,sede,cod_act,buscara,buscart;
	long int buscar_borrar,buscar_mod,buscar_dni,buscar_dni_clientest,buscar_dni_clientes;
	do{
		printf("1-Ingresar un cliente del turno\n");
		printf("2-Borrar un cliente del turno\n");
		printf("3-Modifcar un cliente del turno\n");
		scanf("%d",&op);
		switch(op){
			case 1:
					printf("ingrese la sede que desee 1-2\n");
					scanf("%d",&sede);
					//chequear si no existe el codigo
					do{//mientras se encuentre el dni ingresado o el dni es igual a 0, el bucle se repetira
						recorrer_actividades(sede,*ini_actividad);
						printf("ingrese el codigo de la actividad que desee\n");
                   			scanf("%d",&cod_act);//codigo y sede 
						buscara = buscar_actividades_clientesta(cod_act,sede,*ini_actividad);
				}while(buscara!=1 && nv->cod_act !=0);//modifcar por un or
				if(buscara == 1){
					do{//mientra no se encuentre el turno ingresado o es igual a 0, el bucle se repetira
						recorrer_turnos(cod_act,*ini_turno);
						printf("ingrese el turno que desee\n");
						scanf("%d",&nv->cod_turno);
						buscart = buscar_turno_clientesta(nv->cod_turno,*ini_turno);
					}while(buscart!=1 && nv->cod_turno !=0);
						if(buscart == 1){
							insertar_clientesta(&nv,&*ini_clientesta);
						}
				}
				break;
			case 2:
					printf("ingrese el dni del cliente que se quiere dar de baja en el turno\n");
					scanf("%ld",&buscar_borrar);
			     	if(buscar_dni != 0){//si encontro el dni
						printf("Esta seguro/a de que quiere eliminar al cliente en este turno (1. SI | 0. NO): ");scanf("%d",&op);
							if(op == 1){
								borrar_nodo_clientest(buscar_borrar,&*ini_clientesta);
							}
					}
				break;
			case 3:
					printf("ingrese el dni del cliente que quiere modificar el turno\n");
					scanf("%ld",&buscar_mod);
					buscar_dni_clientes = buscar_dni_clientesta(buscar_mod,*ini_clientesta,ini_turno);
				
			break;
		}
	}
}

#endif
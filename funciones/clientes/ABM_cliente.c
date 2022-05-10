#ifndef ABM_CLIENTE_C
#define ABM_CLIENTE_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
void ABM_clientes(cliente **ini_cliente,actividad **ini_actividad){
	cliente *nv=NULL;
	actividad *p=NULL;
	int op,buscar=0,dni_cliente,buscar_dni=0,op_mod;
	long int buscar_borrar,modificar;
	do{
		system("cls");
		printf("1-Aniadir un nuevo cliente\n");
		printf("2-Eliminar un cliente\n");
		printf("3-Modificar un cliente\n");
		printf("0-Finalizar");
		scanf("%d",&op);
		
		switch(op){
			case 1://aniadir un nuevo cliente
				do{//mientras se encuentre el dni ingresado o el dni es igual a 0, el bucle se repetira
					listar_codigo_actividades(*ini_actividad);
					printf("ingrese el codigo de la actividad que desee\n");
                    scanf("%d",&p->cod_act);
					buscar = buscar_actividades(p->cod_act,*ini_actividad);
				}while(buscar!=1 && p->cod_act !=0);

				if(buscar == 1){
					do{
						printf("ingrese el dni del cliente\n");
						scanf("%ld",&nv->dni);
						buscar_dni = buscar_dni_cliente(nv->dni,*ini_cliente);
					}while(buscar_dni != 1 && nv->dni !=0);
					if(nv->dni != 0){
						printf("ingrese el nombre del cliente\n");
						gets(nv->nombre);
						printf("ingrese el telefono del cliente\n");
						scanf("%ld",&nv->telefono);
						insertar_cliente(&nv,&*ini_cliente);
						
					}
				}

			break;
			case 2://Eliminar un cliente
				do{//no se saldra del bucle a no ser de que, se encuentre un cliente o el dni ingresado sea 0
						printf("ingrese el dni del cliente que desee borrar\n");
						scanf("%ld",&buscar_borrar);
						buscar_dni = buscar_dni_cliente(buscar_borrar,*ini_cliente);
				}while(buscar_dni != 1 && buscar_borrar !=0);

				if(buscar_borrar != 0){//si ebcontro el dni
					printf("Esta seguro/a de que quiere eliminar al cliente (1. SI | 0. NO): ");
					scanf("%d",&op);
					if(op == 1){
					//	borrar_Tcliente(&*ini_cliente);
						borrar_nodo_cliente(buscar_borrar,&*ini_cliente);
					}
				}
			break;
			case 3:
				do{//no se saldra del bucle a no ser de que, se encuentre un cliente o el dni ingresado sea 0
						printf("Ingrese el dni que desea buscar para modificarlo\n");
						scanf("%d",&modificar);
						buscar_dni = buscar_dni_cliente(modificar,*ini_cliente);
				}while(buscar_dni != 1 && modificar !=0);

				if(modificar != 0){
					do{
						printf("1-modificar nombre del cliente\n");
						printf("2-modificar telefono del cliente\n");
						printf("0-Finalizar\n");
						scanf("%d",&op_mod);
					}while(op_mod<0 || op_mod>2);
					modificar_cliente(modificar,op_mod,&*ini_cliente);
				}
			break;
		}	
	}while(op != 0);
	free(nv);
}
#endif
#ifndef ABM_CLIENTE_C
#define ABM_CLIENTE_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
void ABM_clientes(cliente **ini_cliente,actividad *ini_actividad,tipo_turno **ini_turno_cliente){
	cliente *nv=NULL;
	actividad *p=NULL;
	int op,buscar=0,dni_cliente,buscar_dni=0,op_mod,encontrado;
	long int buscar_borrar,modificar;
	do{
		system("cls");
		printf("1-Aniadir un nuevo cliente\n");
		printf("2-Eliminar un cliente\n");
		printf("3-Modificar un cliente\n");
		printf("0-Finalizar\n>> ");
		scanf("%d",&op);
		
		switch(op){
			case 1://aniadir un nuevo cliente
				nv = malloc(sizeof(cliente));// espacio en la memoria ---------
				if(nv != NULL){
					do{
						printf("ingrese el dni del cliente: ");
						scanf("%ld",&nv->dni);
						// printf("\naaa = %ld\n",nv->dni);
						buscar_dni = buscar_dni_cliente_2(nv->dni,&*ini_cliente,*ini_turno_cliente);
					}while(buscar_dni == 1 && buscar_dni != 2 && nv->dni !=0);
					if(buscar_dni != 2){
						if(nv->dni != 0){
							fflush(stdin);
							printf("ingrese el nombre del cliente: ");
							gets(nv->nombre);
							printf("ingrese el telefono del cliente: \n");
							scanf("%ld",&nv->telefono);
							printf("Ingrese el fecha de nacimiento del cliente (dd/mm/aa): ");
							scanf("%d/%d/%d",&nv->f_nacimiento.dd,&nv->f_nacimiento.mm,&nv->f_nacimiento.yy);
							nv->baja = 0;
							nv->sgte = NULL;
							insertar_cliente(&nv,&*ini_cliente);
							
						}
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
					printf("Esta seguro/a de que quiere dar de baja al cliente (1. SI | 0. NO): ");
					scanf("%d",&op_mod);
					if(op_mod == 1){
						// encontrado = 0;
						// do{
						// 	encontrado = borrar_Tcliente(buscar_borrar,&*ini_turno_cliente,&encontrado);
						// }while(encontrado == 1);
					//	borrar_Tcliente(buscar_borrar,&*ini_cliente);
						// borrar_nodo_cliente(buscar_borrar,&*ini_cliente);
						baja_nodo_cliente(buscar_borrar,&*ini_cliente);
						baja_turnos_cliente(buscar_borrar,&*ini_turno_cliente);
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

void baja_nodo_cliente(long int buscar_borrar,cliente **ini_cliente){
	cliente *aux = *ini_cliente;
	int encontrado=0;
	while(aux != NULL && encontrado != 1){
		if(aux->dni == buscar_borrar){
			aux->baja = 1;
			encontrado = 1;
		}
		aux = aux->sgte;
	}
}

void baja_turnos_cliente(long int buscar_borrar,turno_cliente **ini_turno_cliente){
	turno_cliente *aux = *ini_turno_cliente;
	while(aux != NULL){

		if(buscar_borrar == aux->dni){
			aux->baja = 1;
		}

		aux = aux->sgte;
	}
}

void listar_all_clientes(cliente *ini){
	if(ini!=NULL){
		while(ini != NULL){
			printf("%15ld | %30s | %15ld | %d/%d/%d | baja: %d\n",ini->dni,ini->nombre,ini->telefono,ini->f_nacimiento.dd,ini->f_nacimiento.mm,ini->f_nacimiento.yy,ini->baja);
			ini = ini->sgte;
		}
	}else
		printf("\nSIN CLIENTES\n");
}
#endif

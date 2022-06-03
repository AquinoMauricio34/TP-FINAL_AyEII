#ifndef ABM_PROFESORES_C
#define ABM_PROFESORES_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
void ABM_profesores(profesor **ini_profesor,actividad *ini_actividad){
	profesor *nv=NULL;
	actividad *aux_actividad;
	int op,buscar=0,dni_profesor,buscar_dni=0,op_mod;
	long int buscar_borrar,modificar;
	do{
		system("cls");
		printf("1-Aniadir un nuevo profesor\n");
		printf("2-Eliminar un profesor\n");
		printf("3-Modificar un profesor\n");
		printf("0-Finalizar");
		scanf("%d",&op);
		
		switch(op){













			case 1://aniadir un nuevo profesor
			nv = malloc(sizeof(reserva));
			if(nv != NULL){

				do{
					printf("ingrese el dni del profesor\n");
					scanf("%ld",&nv->dni);
					buscar_dni = buscar_dni_profesor(nv->dni,*ini_profesor);
					// printf("\nbuscar = %d\n",buscar_dni);
				}while(buscar_dni == 1 && nv->dni !=0);
				if(nv->dni != 0){
					fflush(stdin);
					printf("ingrese el nombre del profesor\n");
					gets(nv->nombre);
					printf("ingrese el telefono del profesor\n");
					scanf("%ld",&nv->telefono);
					nv->sgte = NULL;
					insertar_profesor(&nv,&*ini_profesor);
					
				}
				
			}
			break;















			case 2://Eliminar un profesor
				// eliminar = 1;
				do{//no se saldra del bucle a no ser de que, se encuentre un profesor o el dni ingresado sea 0
						system("cls");
						if(buscar_dni == -1){
							printf("EL PROFESOR NO PUEDE SER ELIMINADO, DEBIDO A QUE ES TITULAR EN 1 O MAS ACTIVIDADES.\nDEBE MODIFICAR EL DNI DEL PROFESOR A ELIMINAR EN CADA UNA DE LAS ACTIVIDADES.\n");
						}
						printf("Ingrese el dni del profesor que desee borrar\n");
						scanf("%ld",&buscar_borrar);
						printf("\naaa\n");
						buscar_dni = buscar_dni_profesor(buscar_borrar,*ini_profesor);
						aux_actividad = ini_actividad;
						// eliminar = 1;
						while(aux_actividad != NULL && buscar_dni != -1){
							// printf("aux; %ld, bor; %ld\n",aux_actividad->dni_profesor,buscar_borrar);
							if(aux_actividad->dni_profesor == buscar_borrar){
								printf("asdfasdfadsf\n");
								buscar_dni = -1;
							}else
								aux_actividad = aux_actividad->sgte;
						}
// 						if(buscar_dni != 1 && eliminar!=1 && buscar_borrar !=0){
// printf("243589983585\n");
// 						}
				}while(buscar_dni != 1 && buscar_borrar !=0);

				if(buscar_borrar != 0){//si ebcontro el dni


					printf("Esta seguro/a de que quiere eliminar al profesor (1. SI | 0. NO): ");scanf("%d",&op_mod);
					if(op_mod == 1){
						borrar_nodo_profesor(buscar_borrar,&*ini_profesor);
					}
				}
			break;















			case 3:
				

				do{//no se saldra del bucle a no ser de que, se encuentre un profesor o el dni ingresado sea 0
						printf("Ingrese el dni que desea buscar para modificarlo\n");
						scanf("%d",&modificar);
						buscar_dni = buscar_dni_profesor(modificar,*ini_profesor);
				}while(buscar_dni != 1 && modificar !=0);

				if(modificar != 0){
					do{
						printf("1-modificar nombre del profesor\n");
						printf("2-modificar telefono del profesor\n");
						//agregar opcion para modificar la actividad del profesor (trabajo Mauri)
						printf("0-Finalizar\n");
						scanf("%d",&op_mod);
					}while(op_mod<0 || op_mod>2);
					modificar_profesor(modificar,op_mod,&*ini_profesor);
				}
			break;
















		}	
	}while(op != 0);
	free(nv);
}

void listar_all_profesores(profesor *ini){
	if(ini!=NULL){
		while(ini != NULL){
			printf("%15ld | %30s | %15ld |\n",ini->dni,ini->nombre,ini->telefono);
			ini = ini->sgte;
		}
	}else
		printf("\nSIN PROFESORES\n");
}

#endif

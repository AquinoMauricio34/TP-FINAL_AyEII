#ifndef ABM_PROFESORES_C
#define ABM_PROFESORES_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
void ABM_profesores(profesor **ini_profesor,actividad *ini_actividad){
	profesor *nv=NULL;
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
				//se debe pedir espacio en la memoria ------------------------------------------------------------------
				do{//mientras se encuentre el dni ingresado o el dni es igual a 0, el bucle se repetira
					listar_codigo_actividades(*ini_actividad);
					printf("ingrese el codigo de la actividad que desee\n");scanf("%d",&nv->cod_act);
					buscar = buscar_actividades(nv->cod_act,*ini_actividad);
				}while(buscar!=1 && nv->cod_act !=0);

				if(buscar == 1){
					do{
						printf("ingrese el dni del profesor\n");
						scanf("%ld",&nv->dni);
						buscar_dni = buscar_dni_profesor(nv->dni,*ini_profesor);
					}while(buscar_dni != 1 && nv->dni !=0);
					if(nv->dni != 0){
						printf("ingrese el nombre del profesor\n");
						scanf("%s",nv->nombre);
						printf("ingrese el telefono del profesor\n");
						scanf("%ld",&nv->telefono);
						insertar_profesor(&nv,&*ini_profesor);
						
					}
				}

			break;















			case 2://Eliminar un profesor
				do{//no se saldra del bucle a no ser de que, se encuentre un profesor o el dni ingresado sea 0
						printf("ingrese el dni del profesor que desee borrar\n");
						scanf("%ld",&buscar_borrar);
						buscar_dni = buscar_dni_profesor(buscar_borrar,*ini_profesor);
				}while(buscar_dni != 1 && buscar_borrar !=0);

				if(buscar_borrar != 0){//si ebcontro el dni
					printf("Esta seguro/a de que quiere eliminar al profesor (1. SI | 0. NO): ");scanf("%d",&op);
					if(op == 1){
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
						printf("3-modificar actividad del profesor\n");
						//agregar opcion para modificar la actividad del profesor (trabajo Mauri)
						printf("0-Finalizar\n");
						scanf("%d",&op_mod);
					}while(op_mod<0 || op_mod>3);
					modificar_profesor(modificar,op_mod,&*ini_profesor,ini_actividad);
				}
			break;
















		}	
	}while(op != 0);
	free(nv);
}

#endif

//estado verificado
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
		printf("0-Finalizar\n>> ");
		scanf("%d",&op);
		
		switch(op){


			case 1://aniadir un nuevo profesor
			nv = malloc(sizeof(profesor));
			if(nv != NULL){

				do{
					system("cls");
					printf("Ingrese el dni del profesor: ");
					scanf("%ld",&nv->dni);
					buscar_dni = buscar_dni_profesor(nv->dni,*ini_profesor);
				}while(buscar_dni == 1 && nv->dni !=0);
				if(nv->dni != 0){
					fflush(stdin);
					printf("Ingrese el nombre del profesor: ");
					gets(nv->nombre);
					printf("Ingrese el telefono del profesor: ");
					scanf("%ld",&nv->telefono);
					nv->sgte = NULL;
					insertar_profesor(&nv,&*ini_profesor);
				}
				
			}
			break;



			case 2://Eliminar un profesor
				do{//no se saldra del bucle a no ser de que, se encuentre un profesor o el dni ingresado sea 0
						system("cls");
						if(buscar_dni == -1){
							printf("EL PROFESOR NO PUEDE SER ELIMINADO, DEBIDO A QUE ES TITULAR EN 1 O MAS ACTIVIDADES.\nDEBE MODIFICAR EL DNI DEL PROFESOR A ELIMINAR EN CADA UNA DE LAS ACTIVIDADES.\n");
						}
						printf("Ingrese el dni del profesor que desee borrar: ");
						scanf("%ld",&buscar_borrar);
						buscar_dni = buscar_dni_profesor(buscar_borrar,*ini_profesor);
						aux_actividad = ini_actividad;
						while(aux_actividad != NULL && buscar_dni != -1){
							if(aux_actividad->dni_profesor == buscar_borrar){
								buscar_dni = -1;
							}else
								aux_actividad = aux_actividad->sgte;
						}
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
						system("cls");
						printf("Ingrese el dni que desea buscar para modificarlo\n");
						scanf("%d",&modificar);
						buscar_dni = buscar_dni_profesor(modificar,*ini_profesor);
				}while(buscar_dni != 1 && modificar !=0);

				if(modificar != 0){
					do{
						do{
							printf("1-modificar nombre del profesor\n");
							printf("2-modificar telefono del profesor\n");
							printf("0-Finalizar\n");
							scanf("%d",&op_mod);
						}while(op_mod<0 || op_mod>2);
						system("cls");
						modificar_profesor(modificar,op_mod,&*ini_profesor);
					}while(op_mod != 0);
				}
			break;


		}	
	}while(op != 0);
	free(nv);
}

void listar_all_profesores(profesor *ini){
	if(ini!=NULL){
			printf("%-15s | %-30s | %-15s |\n\n","DNI","NOMBRE","TELEFONO");
		while(ini != NULL){
			printf("%-15ld | %-30s | %-15ld |\n",ini->dni,ini->nombre,ini->telefono);
			ini = ini->sgte;
		}
	}else
		printf("SIN PROFESORES\n");
}



void borrar_nodo_profesor(int dato,profesor **ini_profesor){
    profesor *bor=*ini_profesor,*ant=NULL;
    buscar_borrar_profesor(dato,&bor,&ant);
    if(bor != NULL){
        if(ant == NULL){
           *ini_profesor = (*ini_profesor)->sgte;
        }else{
            ant->sgte = bor->sgte;
        }
        bor->sgte = NULL;
        free(bor);
    }else
         printf("no existe el dato no esta en la lista\n");
}


void buscar_borrar_profesor(long int dato,profesor **bor,profesor **ant){
    *ant = NULL;
    int encontrado=0;
    while(*bor != NULL && encontrado != 1){
        if(dato == (*bor)->dni){
            encontrado = 1;
        }else{
            *ant = *bor;
            *bor = (*bor)->sgte;
        }
    }
}


int buscar_dni_profesor(long int dni,profesor *ini_profesor){
    int buscar=0;
	while(ini_profesor != NULL && buscar != 1){
		if(ini_profesor->dni == dni)
			buscar = 1;
		ini_profesor = ini_profesor->sgte;
	}
	return buscar;
}


void insertar_profesor(profesor **nv, profesor **ini_profesor){
    profesor *aux = *ini_profesor;
    if(*ini_profesor != NULL){
        while(aux->sgte != NULL){
            aux = aux->sgte;
        }
        aux->sgte = *nv;
        *nv = NULL;
    }else{
        *ini_profesor = *nv;
        *nv = NULL;
	}
    
}





void modificar_profesor(long int dato,int op,profesor **ini_profesor){
	int buscar,codigo;
	int encontrado = 0;
	profesor *aux = *ini_profesor;
	while(aux != NULL && encontrado != 1){
		if(aux->dni == dato){
			if(op==1){
				fflush(stdin);
				gets(aux->nombre);
			}else if(op==2){
				scanf("%ld",&aux->telefono);
			}
			encontrado = 1;
		}
		
		aux = aux->sgte;	
	}
}

#endif

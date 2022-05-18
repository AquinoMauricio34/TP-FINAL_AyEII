#ifndef MODIFICAR_PROFESOR_C
#define MODIFICAR_PROFESOR_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
void modificar_profesor(long int dato,int op,profesor **ini_profesor, actividad *ini_actividad){
	int buscar,codigo;
	while(*ini_profesor != NULL){
		
		if((*ini_profesor)->dni == dato){
		
			if(op==1){
				fflush(stdin);
				gets((*ini_profesor)->nombre);
			}else if(op==2){
				scanf("%ld",&(*ini_profesor)->telefono);
			}else if(op==3){
				do{
					system("cls");
					printf("\nActividades Disponibles\n");
					listar_actividades(ini_actividad);
					printf("Ingresar codigo de la actividad deseada: \n");
					scanf("%d",&codigo);
					buscar = buscar_actividades_profesores(codigo,ini_actividad);
				}while(buscar != 1 || codigo != 0);
				
				if(buscar == 1){
					(*ini_profesor)->cod_act = codigo;
				}
			}
			*ini_profesor = NULL;
		}
		
		*ini_profesor = (*ini_profesor)->sgte;	
	}
}


#endif

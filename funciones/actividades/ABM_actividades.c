#ifndef ABM_ACTIVIDADES_C
#define ABM_ACTIVIDADES_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
void ABM_actividades(actividad **ini_actividad,tipo_turno **ini_turno_cliente){
//	cliente *nv=NULL;
	actividad *p=*ini_actividad, *nv=NULL ,*aux=NULL;
	int op,buscar=0,dni_cliente,buscar_cod=0,op_mod;
    int encontrado;
	long int buscar_borrar,modificar;
	do{
		system("cls");
		printf("1-Aniadir una nueva actividad\n");
		printf("2-Eliminar una actividad\n");
		printf("3-Modificar una actividad\n");
		printf("0-Finalizar");
		scanf("%d",&op);
		
		switch(op){
			case 1://aniadir una nueva actividad
				//se pide espacio en la memoria ------------------------------------------------------------------
                 nv = malloc(sizeof( actividad));
                 if(nv != NULL){
                     if(p != NULL){
                        nv->cod_act =1;
                    }else{
                        aux=p;
                        while(aux!=NULL){
                            aux= aux->sgte;
                        }
                        nv->cod_act= aux->cod_act + 1;
                    }
					if(nv->cod_act != 0 ){
                        fflush(stdin);
						printf("ingrese el nombre de la actividad\n");
						gets(nv->nombre);
                        //...
						printf("ingrese la cantidad de personas que se tendra por actividad\n");
						scanf("%ld",&nv->cant_personas);
                        printf("ingrese la sede en la que se realiza esta actividad\n");
                        scanf("%ld",&nv->sede);
                        printf("ingrese el estado en que se encuentra esta actividad\n");
                        scanf("%ld",&nv->estado);
						insertar_actividad(&nv,&*ini_actividad);
						
					}
                }else printf("\nErrorde asignacion de memoria\n");
			break;
			case 2://Eliminar una actividad
				do{//no se saldra del bucle a no ser de que, se encuentre un cliente o el dni ingresado sea 0
						printf("ingrese el cod de la actividad que desee borrar\n");
						scanf("%ld",&buscar_borrar);
						buscar_cod = buscar_actividad(buscar_borrar,*ini_actividad);
				}while(buscar_cod != 1 && buscar_borrar !=0);

				if(buscar_borrar != 0){//si ebcontro el cod
					printf("Esta seguro/a de que quiere eliminar la actividad (1. SI | 0. NO): ");
					scanf("%d",&op_mod);
					if(op_mod == 1){
						encontrado = 0;
						/*do{
							encontrado = borrar_Tcliente();
						}while(encontrado == 1);*/
						borrar_actividad(buscar_borrar,&*ini_actividad);
					}
				}
			break;
			case 3:
				do{//no se saldra del bucle a no ser de que, se encuentre un cliente o el dni ingresado sea 0
						printf("Ingrese el codigo de la actividad que desea buscar para modificar\n");
						scanf("%d",&modificar);
						buscar_cod = buscar_actividad(modificar,*ini_actividad);
				}while(buscar_cod != 1 && modificar !=0);

				if(modificar != 0){
					do{
						printf("1-modificar nombre de la actividad \n");
						printf("2-modificar la cantidad de personas \n");
						printf("0-Finalizar\n");
						scanf("%d",&op_mod);
					}while(op_mod<0 || op_mod>2);
					modificar_actividad(modificar,op_mod,&*ini_actividad);
				}
			break;
		}	
	}while(op != 0);
	free(nv);
}
#endif
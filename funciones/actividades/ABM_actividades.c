//verificacion de que se ingresen los datos correctamente
#ifndef ABM_ACTIVIDADES_C
#define ABM_ACTIVIDADES_C
//si elimino una actividad, todos los tipo turno y los turnos clientes con el codigo de esa actividad deben ser eliminados
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"

extern fecha fecha_global;

void ABM_actividades(actividad **ini_actividad,tipo_turno **ini_turno_cliente,profesor *ini_profesor){
//	cliente *nv=NULL;
	actividad *p=*ini_actividad, *nv=NULL ,*aux=NULL;
	int op,buscar=0,buscar_cod=0,op_mod;
	long int buscar_borrar,modificar,dni_profesor;
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
					//  printf("\naaa\n");
                    if(*ini_actividad == NULL){
						// printf("\naaa111\n");
                        nv->cod_act = 1;
                    }else{
						// printf("\naaa222\n");
                        aux=*ini_actividad;
                        while(aux->sgte!=NULL){
                            aux = aux->sgte;
							// printf("\naaa2233\n");
                        }
						// printf("\naaa333\n");
                        nv->cod_act= aux->cod_act + 1;
						// printf("\naaa444\n");
                    }
					// printf("\nbbb\n");
					if(nv->cod_act != 0 ){
                        fflush(stdin);
						printf("ingrese el nombre de la actividad: \n");
						gets(nv->nombre);
                        //...
						do{
							printf("ingrese la cantidad de personas que se tendra por actividad: ");
							scanf("%d",&nv->cant_personas);
						}while(nv->cant_personas < 0);
						if(nv->cant_personas > 0){
							do{
								printf("ingrese la sede en la que se realiza esta actividad: ");
								scanf("%d",&nv->sede);
							}while(nv->sede < -1 && nv->sede > 2 && nv->sede!=0);
							if(nv->sede != 0){
								if(ini_profesor!=NULL){
									listar_all_profesores(ini_profesor);
									do{
										printf("Ingresar el dni del profesor: ");scanf("%ld",&dni_profesor);
										buscar = buscar_dni_profesor(dni_profesor,ini_profesor);
									}while(buscar != 1 && dni_profesor != 0);
									if(dni_profesor!=0){
										nv->fecha_baja.dd=0;
										nv->fecha_baja.mm=0;
										nv->fecha_baja.yy=0;
										nv->dni_profesor=dni_profesor;
										nv->estado = 1;
										nv->sgte = NULL;
										insertar_actividad(&nv,&*ini_actividad);
									}
								}else{
									system("cls");
									printf("NO SE PUEDE REGISTRAR UNA ACTIVIDAD SIN NO SE TIENE PROFESORES.\n");
									system("pause");

								}
							}
						}
						
					}
					// free(nv);
                }else printf("\nErrorde asignacion de memoria\n");
			break;
			case 2://Eliminar una actividad
				do{//no se saldra del bucle a no ser de que, se encuentre un cliente o el dni ingresado sea 0
						printf("ingrese el cod de la actividad que desee borrar\n");
						scanf("%d",&buscar_borrar);
						buscar_cod = buscar_actividadx(buscar_borrar,*ini_actividad);
				}while(buscar_cod != 1 && buscar_borrar !=0);

				if(buscar_borrar != 0){//si ebcontro el cod
					printf("Esta seguro/a de que quiere eliminar la actividad (1. SI | 0. NO): ");
					scanf("%d",&op_mod);
					if(op_mod == 1){
						/*do{
							encontrado = borrar_Tcliente();
						}while(encontrado == 1);*/
						// borrar_nodo_actividad(buscar_borrar,&*ini_actividad);



						//dar de baja a la actividad
						aux=*ini_actividad;
						buscar = 0;
						while(aux != NULL && buscar != 1){
							if(aux->cod_act == buscar_borrar){
								aux->estado = -1;
								aux->fecha_baja.dd = fecha_global.dd;
								aux->fecha_baja.mm = fecha_global.mm;
								aux->fecha_baja.yy = fecha_global.yy;
								buscar =1;
							}
							aux = aux->sgte;
						}




						system("pause");
					}
				}
			break;
			case 3:
				do{//no se saldra del bucle a no ser de que, se encuentre un cliente o el dni ingresado sea 0
						printf("Ingrese el codigo de la actividad que desea buscar para modificar\n");
						scanf("%d",&modificar);
						buscar_cod = buscar_actividadx(modificar,*ini_actividad);
				}while(buscar_cod != 1 && modificar !=0);

				if(modificar != 0){
					do{
						system("cls");
						do{
							printf("1-modificar nombre de la actividad \n");
							printf("2-modificar la cantidad de personas \n");
							printf("3-modificar la sede de la actividad \n");
							printf("4-modificar dni del profesor \n");
							printf("0-Finalizar\n");
							scanf("%d",&op_mod);
						}while(op_mod<0 || op_mod>4);
						system("cls");
						modificar_actividad(modificar,op_mod,&*ini_actividad);
					}while(op_mod!=0);
				}
			break;
		}	
	}while(op != 0);
	// printf("asdfasdfsadf");
	free(nv);
	// printf("123412341234");
}


void baja_actividad_estado(actividad **ini_actividad,tipo_turno **ini_tipo_turno,turno_cliente **ini_turno_cliente){
	actividad *aux_actividad;
	tipo_turno *aux_tipo_turno;
	turno_cliente *aux_turno_cliente;
	aux_actividad=aux_tipo_turno=aux_turno_cliente=NULL;
	aux_actividad = *ini_actividad;
	while(aux_actividad != NULL){
		if(aux_actividad->estado == -1 && aux_actividad->fecha_baja.dd != 0 && aux_actividad->fecha_baja.mm != 0 && aux_actividad->fecha_baja.yy != 0){
			if((aux_actividad->fecha_baja.yy < fecha_global.yy) || aux_actividad->fecha_baja.mm+1 <= fecha_global.mm && aux_actividad->fecha_baja.yy == fecha_global.yy){
				aux_actividad->estado = 0;
				baja_tipo_turnos_actividad(aux_actividad->cod_act,&*ini_tipo_turno,&*ini_turno_cliente);
			}
		}
		aux_actividad = aux_actividad->sgte;
	}
}

void baja_tipo_turnos_actividad(int codigo_actividad,tipo_turno **ini_tipo_turno,turno_cliente **ini_turno_cliente){
	tipo_turno *aux_tipo_turno=*ini_tipo_turno;
	while(aux_tipo_turno != NULL){

		if(aux_tipo_turno->cod_act == codigo_actividad && aux_tipo_turno->estado == 1){
			aux_tipo_turno->estado = 0;
			baja_turnos_cliente_seguntturno(aux_tipo_turno->cod_turno,&*ini_turno_cliente);
		}

		aux_tipo_turno = aux_tipo_turno->sgte;
	}
}

void baja_turnos_cliente_seguntturno(int codigo_tt,turno_cliente **ini_turno_cliente){
	turno_cliente *aux_turno_cliente=*ini_turno_cliente;
	while(aux_turno_cliente != NULL){
		printf("\n444\n");
		if(aux_turno_cliente->baja == 0 && aux_turno_cliente->cod_turno == codigo_tt){
			printf("\n555\n");
			aux_turno_cliente->baja = 1;
		}
		aux_turno_cliente = aux_turno_cliente->sgte;
	}
}



void listar_all_actividades(actividad *ini){
	if(ini!=NULL){
		while(ini != NULL){
			printf("%10d | %30s | %7d | %d | estado: %d | %d/%d/%d\n",ini->cod_act,ini->nombre,ini->cant_personas,ini->sede,ini->estado,ini->fecha_baja.dd,ini->fecha_baja.mm,ini->fecha_baja.yy);
			ini = ini->sgte;
		}
	}else
		printf("\nSIN ACTIVIDADES\n");
}
#endif

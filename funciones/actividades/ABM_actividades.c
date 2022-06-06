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
		printf("0-Finalizar\n>> ");
		scanf("%d",&op);
		
		switch(op){
			case 1://aniadir una nueva actividad
				//se pide espacio en la memoria ------------------------------------------------------------------
				system("cls");
                 nv = malloc(sizeof( actividad));
                 if(nv != NULL){
                    if(*ini_actividad == NULL){
                        nv->cod_act = 1;
                    }else{
                        aux=*ini_actividad;
                        while(aux->sgte!=NULL){
                            aux = aux->sgte;
                        }
                        nv->cod_act= aux->cod_act + 1;
                    }
					if(nv->cod_act != 0 ){
                        fflush(stdin);
						printf("Ingrese el nombre de la actividad: \n");
						gets(nv->nombre);
						do{
							printf("Ingrese la cantidad de personas que se tendra por actividad: ");
							scanf("%d",&nv->cant_personas);
						}while(nv->cant_personas < 0);
						if(nv->cant_personas > 0){
							do{
								printf("Ingrese la sede en la que se realiza esta actividad: ");
								scanf("%d",&nv->sede);
							}while(nv->sede < -1 && nv->sede > 2 && nv->sede!=0);
							if(nv->sede != 0){
								if(ini_profesor!=NULL){
									do{
										system("cls");
										listar_all_profesores(ini_profesor);
										printf("Ingresar el dni del profesor a cargo de la actividad: ");scanf("%ld",&dni_profesor);
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
						system("cls");
						printf("Ingrese el cod de la actividad que desee borrar: ");
						scanf("%d",&buscar_borrar);
						buscar_cod = buscar_actividadx(buscar_borrar,*ini_actividad);
				}while(buscar_cod != 1 && buscar_borrar !=0);

				if(buscar_borrar != 0){//si ebcontro el cod
					printf("Esta seguro/a de que quiere eliminar la actividad (1. SI | 0. NO): ");
					scanf("%d",&op_mod);
					if(op_mod == 1){



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
						system("cls");
						printf("Ingrese el codigo de la actividad que desea buscar para modificar: ");
						scanf("%d",&modificar);
						buscar_cod = buscar_actividadx(modificar,*ini_actividad);
				}while(buscar_cod != 1 && modificar !=0);

				if(modificar != 0){
					do{
						do{
							system("cls");
							printf("1-modificar nombre de la actividad \n");
							printf("2-modificar la cantidad de personas \n");
							printf("3-modificar la sede de la actividad \n");
							printf("4-modificar dni del profesor \n");
							printf("0-Finalizar\n>> ");
							scanf("%d",&op_mod);
						}while(op_mod<0 || op_mod>4);
						system("cls");
						modificar_actividad(modificar,op_mod,&*ini_actividad);
					}while(op_mod!=0);
				}
			break;
		}	
	}while(op != 0);
	free(nv);
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
			printf("%10s | %30s | %8s | %8s | %8s | %8s\n\n","CODIGO","NOMBRE","CUPO","SEDE","ESTADO","FECHA BAJA");
		while(ini != NULL){
			printf("%10d | %30s | %8d | %8d | %8d | %8d/%d/%d\n",ini->cod_act,ini->nombre,ini->cant_personas,ini->sede,ini->estado,ini->fecha_baja.dd,ini->fecha_baja.mm,ini->fecha_baja.yy);
			ini = ini->sgte;
		}
	}else
		printf("\nSIN ACTIVIDADES\n");
}

int buscar_actividadx(int codigo,actividad *ini_actividad){
	int buscar=0;
	while(ini_actividad != NULL && buscar != 1){
		if(ini_actividad->cod_act == codigo){
			buscar = 1;
		}else{
			buscar = 0;
		}
		ini_actividad = ini_actividad->sgte;
	}
	
	return buscar;
}



void insertar_actividad(actividad **nv, actividad **ini_actividad){
    actividad *aux = *ini_actividad;
    if(*ini_actividad != NULL){
        while(aux->sgte != NULL){
            aux = aux->sgte;
        }
        aux->sgte = *nv;
        *nv = NULL;
    }else{
        *ini_actividad = *nv;
        *nv = NULL;
	}
    
}




void modificar_actividad(long int dato,int op,actividad **ini_actividad){
	int encontrado = 0;
	actividad *aux = *ini_actividad;
	while(aux != NULL && encontrado != 1){
		
		if(aux->cod_act== dato && aux->estado != 0){
		
			if(op==1){
				fflush(stdin);
				printf("NOMBRE DE LA ACTIVIDAD\n");
				printf("Nombre actual: ");puts(aux->nombre);
				printf("Nuevo nombre: ");
				fflush(stdin);
				gets(aux->nombre);
			}else if(op==2){
				printf("CANTIDAD DE CUPOS DE LA ACTIVIDAD\n");
				printf("Cantidad actual: %d\n",aux->cant_personas);
				printf("Nueva cantidad: ");
				scanf("%d",&aux->cant_personas);
			}else if(op==3){
				printf("SEDE DE LA ACTIVIDAD\n");
				printf("Sede actual: %d\n",aux->sede);
				printf("Nueva sede: ");
				scanf("%d",&aux->sede);
			}else if(op==4){
				printf("DNI PROFESOR DE LA ACTIVIDAD\n");
				printf("Dni profesor actual: %d\n",aux->dni_profesor);
				printf("Nueva dni profesor: ");
				scanf("%d",&aux->dni_profesor);

			}
			encontrado = 1;
		}
		
		aux = aux->sgte;	
	}
}

#endif

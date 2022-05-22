#ifndef ABM_CLIENTESTA_C
#define ABM_CLIENTESTA_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
//controlar tope de alumnos permitidos
void abm_clientes_ta(turno_cliente **ini_clientesta,tipo_turno **ini_turno,actividad *ini_actividad,cliente *ini_cliente){
	turno_cliente *nv=NULL;
	int op,buscar_act,sede,cod_act,buscara=0,opcion;
	long int buscar_borrar,buscar_mod,buscar_dni,buscar_dni_clientest,buscar_dni_clientes;
	do{
		printf("1-Ingresar un cliente del turno\n");
		printf("2-Borrar un cliente del turno\n");
		printf("3-Modifcar un cliente del turno\n");
		printf("0-Finalizar\n>> ");
		scanf("%d",&op);
		switch(op){
			case 1:
			nv = malloc(sizeof(turno_cliente));
			if(nv != NULL){
				nv->sgte = NULL;
				printf("ingrese la sede que desee 1-2\n");
				scanf("%d",&sede);
					//chequear si no existe el codigo
				if(sede == 1 ||sede == 2 ){
					recorrer_actividades(sede,ini_actividad);
					do{//mientras se encuentre el dni ingresado o el dni es igual a 0, el bucle se repetira
						printf("ingrese el codigo de la actividad que desee\n");
                   		scanf("%d",&cod_act);//codigo y sede 
						printf("\n111\n");
						buscara = buscar_actividades_clientesta(cod_act,sede,ini_actividad);
						printf("\n222 = %d\n",buscara);
				}while(buscara!=1 && cod_act !=0);//modifcar por un or
				if(buscara == 1){
					buscara = 0;
					nv->cod_act = cod_act;
					recorrer_turnos(cod_act,*ini_turno);
					do{//mientra no se encuentre el turno ingresado o es igual a 0, el bucle se repetira
						printf("ingrese el turno que desee\n");
						scanf("%d",&nv->cod_turno);
						printf("\n000\n");
						buscara = buscar_turno(nv->cod_turno,nv->cod_act,*ini_turno);
						printf("\naaa\n");
					}while(buscara!=1 && nv->cod_turno !=0);
					
 		

						if(buscara == 1){
							//ingresar dni
							do{//no se saldra del bucle a no ser de que, se encuentre un cliente o el dni ingresado sea 0
									printf("ingrese el dni del cliente: ");
									scanf("%ld",&nv->dni);
									buscar_dni = buscar_dni_cliente(nv->dni,ini_cliente);
							}while(buscar_dni != 1 && nv->dni !=0);

							if(nv->dni !=0){
								nv->debe = 0;
								nv->f_ultima_vez.dd =0;
								nv->f_ultima_vez.mm = 0;
								nv->f_ultima_vez.yy = 0;
								
								do{
									printf("Esta seguro de que quiere realizar la reserva? (1.Si | 0.No): ");scanf("%d",&opcion);
								}while(opcion<0 || opcion>1);
								if(opcion){
									insertar_codigo_cliente(&nv,&*ini_clientesta);
									insertar_clientesta(&nv,&*ini_clientesta);
								}
							}

						}
				}
			}else
					printf("La sede ingresada es incorrecta\n");
			}
				break;








			case 2:
					// printf("ingrese el dni del cliente que se quiere dar de baja en el turno\n");
					// scanf("%ld",&buscar_borrar);
			     	// if(buscar_dni != 0){//si encontro el dni
					// 	printf("Esta seguro/a de que quiere eliminar al cliente en este turno (1. SI | 0. NO): ");scanf("%d",&op);
					// 		if(op == 1){
					// 			borrar_nodo_clientest(buscar_borrar,&*ini_clientesta);
					// 		}
					// }


					// buscar = 0;
					// do{
					// 	printf("Ingresar dni guardado en el reserva: ");scanf("%ld",&dni_cliente);
					// 	buscar = buscar_dni_reserva(dni_cliente,*ini_reserva);
					// }while(buscar != 1 && dni_cliente != 0);

					// if(dni_cliente!=0){
					// 	printf("Esta seguro/a de que quiere eliminar al cliente (1. SI | 0. NO): ");
					// 	scanf("%d",&op);
					// 	if(op == 1){
					// 		borrar_nodo_reserva(dni_cliente,&*ini_reserva);
					// 	}
					// }
				break;	








			// case 3:
			// 		printf("ingrese el dni del cliente que quiere modificar el turno\n");
			// 		scanf("%ld",&buscar_mod);
			// 		buscar_dni_clientes = buscar_dni_clientesta(buscar_mod,&*ini_clientesta);
				
			// break;
		}
	}while(op != 0);
}

void listar_all_turnos_clientes(turno_cliente *ini){
	if(ini!=NULL){
		while(ini != NULL){
			printf("cod_t: %d | cod_a: %d | cod_clientesta: %d | dni: %ld |\n",ini->cod_turno,ini->cod_act,ini->cod_clientesta,ini->dni);
			printf("debe: %d | ult_v: %d/%d",ini->debe,ini->f_ultima_vez.dd,ini->f_ultima_vez.mm,ini->f_ultima_vez.yy);
            printf("--------------");
			ini = ini->sgte;
		}
	}else
		printf("\nSIN RESERVAS\n");
}

#endif
#ifndef ABM_CLIENTESTA_C
#define ABM_CLIENTESTA_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"

extern fecha fecha_global;
//controlar tope de alumnos permitidos
void abm_clientes_ta(turno_cliente **ini_clientesta,tipo_turno **ini_turno,actividad *ini_actividad,cliente *ini_cliente,cuenta **ini_cuenta){
	turno_cliente *nv=NULL, *aux_turno_cliente;
	tipo_turno *aux_tipo_turno=NULL;
	cuenta *nv_cuenta=NULL;
	int op,buscar,sede,cod_act,buscara=0,opcion,numero_cod_clientesta,numero_cod_turno;
	long int buscar_borrar,buscar_mod,buscar_dni,buscar_dni_clientest,buscar_dni_clientes;
	int dni_cliente, eleccion_turno_cliente;
	do{
		printf("1-Ingresar un cliente del turno\n");
		printf("2-Borrar un cliente del turno\n");
		// printf("3-Modifcar un cliente del turno\n");
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
					do{//mientras se encuentre el dni ingresado o el dni es igual a 0, el bucle se repetira
						system("cls");
						recorrer_actividades(sede,ini_actividad);
						if(buscara == -1){
							printf("Cupo de actividad lleno.\nTiene la posibilidad de realizar una reserva.\n");
						}
						printf("ingrese el codigo de la actividad que desee\n");
                   		scanf("%d",&cod_act);//codigo y sede 
						// printf("\n111\n");
						buscara = buscar_actividades_clientesta(cod_act,sede,ini_actividad,*ini_clientesta);
						// printf("\n222 = %d\n",buscara);
				}while(buscara!=1 && cod_act !=0);//modifcar por un or
				if(buscara == 1){
					buscara = 0;
					nv->cod_act = cod_act;
					do{//mientra no se encuentre el turno ingresado o es igual a 0, el bucle se repetira
						system("cls");
						recorrer_turnos(cod_act,*ini_turno);
						printf("ingrese el turno que desee\n");
						scanf("%d",&nv->cod_turno);
						// printf("\n000\n");
						buscara = buscar_turno(nv->cod_turno,nv->cod_act,*ini_turno);
						// printf("\naaa\n");
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
								nv->f_ultima_vez.dd = fecha_global.dd;
								nv->f_ultima_vez.mm = fecha_global.mm;
								nv->f_ultima_vez.yy = fecha_global.yy;
								nv->baja = 0;
								nv->incrementado = 0;
								do{
									printf("Esta seguro de que quiere realizar la reserva? (1.Si | 0.No): ");scanf("%d",&opcion);
								}while(opcion<0 || opcion>1);
								if(opcion){
									insertar_codigo_cliente(&nv,&*ini_clientesta);
									numero_cod_clientesta = nv->cod_clientesta;
									numero_cod_turno = nv->cod_turno;
									insertar_clientesta(&nv,&*ini_clientesta);
									// crear cuenta pagada
									// printf("\n111\n");
									nv_cuenta = malloc(sizeof(cuenta));
									if(nv_cuenta != NULL){
										// printf("\n222\n");
										nv_cuenta->sgte = NULL;
										nv_cuenta->cod_clientesta = numero_cod_clientesta;
										// printf("\n333\n");
										nv_cuenta->f_pago.dd = fecha_global.dd;
										nv_cuenta->f_pago.mm = fecha_global.mm;
										nv_cuenta->f_pago.yy = fecha_global.yy;
										// printf("\n444\n");
										aux_tipo_turno=*ini_turno;
										// printf("\n555\n");
										buscar = 0;
										while(aux_tipo_turno != NULL && buscar != 1){
											// printf("\ncod_t: %d, aux: %d\n",nv->cod_turno,aux_tipo_turno->cod_turno);
											if(numero_cod_turno == aux_tipo_turno->cod_turno){
												
												// printf("\n222111 %f\n",aux_tipo_turno->precio);
												nv_cuenta->precio = aux_tipo_turno->precio;
												// break;
												buscar = 1;//reutilizo la variable para no crear otra
											}
											aux_tipo_turno = aux_tipo_turno->sgte;
										}
										// printf("\n666\n");
										insertar_cuenta(&nv_cuenta,&*ini_cuenta);
									}else
										printf("No se puede crear la cuenta");
								}
							}

						}
				}
			}else
					printf("La sede ingresada es incorrecta\n");
			}
				break;








			case 2:
					buscar = 0;
					do{
						printf("Ingresar dni del cliente: ");scanf("%ld",&dni_cliente);
						buscar = buscar_dni_turno_cliente(dni_cliente,*ini_clientesta);
					}while(buscar != 1 && dni_cliente != 0);

					if(dni_cliente != 0){

						listar_turnos_cliente(dni_cliente,*ini_clientesta);

						do{
							printf("Ingresar codigo del turno del cliente: ");scanf("%d",&eleccion_turno_cliente);
							buscar = buscar_turno_cliente(eleccion_turno_cliente,dni_cliente,*ini_clientesta);
						}while(buscar != 1 && eleccion_turno_cliente != 0);

						if(eleccion_turno_cliente != 0){
							printf("Esta seguro/a de que quiere dar de baja el turno del cliente (1. SI | 0. NO): ");
							scanf("%d",&op);
							if(op == 1){
								// borrar_nodo_clientest(eleccion_turno_cliente,&*ini_clientesta);
								buscar = 0;
								aux_turno_cliente = *ini_clientesta;
								while(aux_turno_cliente != NULL && buscar != 1){

									if(aux_turno_cliente->cod_clientesta == eleccion_turno_cliente){
										aux_turno_cliente->baja = 1;
										buscar = 1;
									}

									aux_turno_cliente = aux_turno_cliente->sgte;
								}
							}
						}

					}
				break;	








			// case 3:
			// 		// printf("ingrese el dni del cliente que quiere modificar el turno\n");
			// 		// scanf("%ld",&buscar_mod);
			// 		// buscar_dni_clientes = buscar_dni_clientesta(buscar_mod,&*ini_clientesta);
				

			// 	buscar = 0;
			// 	do{
			// 		printf("Ingresar dni del cliente: ");scanf("%ld",&dni_cliente);
			// 		buscar = buscar_dni_turno_cliente(dni_cliente,*ini_clientesta);
			// 	}while(buscar != 1 && dni_cliente != 0);

			// 	if(dni_cliente != 0){

			// 		listar_turnos_cliente(dni_cliente,*ini_clientesta);

			// 		do{
			// 			printf("Ingresar codigo del tipo turno: ");scanf("%d",&eleccion_turno_cliente);
			// 			buscar = buscar_turno_cliente(eleccion_turno_cliente,dni_cliente,*ini_clientesta);
			// 		}while(buscar != 1 && eleccion_turno_cliente != 0);

			// 		if(eleccion_turno_cliente != 0){
			// 			do{
			// 			system("cls");
			// 			do{
			// 				printf("1-modificar precio del turno \n");
			// 				printf("0-Finalizar\n>> ");
			// 				scanf("%d",&op);
			// 			}while(op<0 || op>4);
			// 			// system("cls");
			// 			// modificar_tipo_turno(codigo_turno,op,&*ini_tipo_turno);
			// 		}while(op!=0);
			// 		}

			// 	}
			// break;
		}
	}while(op != 0);
	free(nv);
}

void listar_all_turnos_clientes(turno_cliente *ini){
	if(ini!=NULL){
		while(ini != NULL){
			printf("cod_t: %d | cod_a: %d | cod_clientesta: %d | dni: %ld |\n",ini->cod_turno,ini->cod_act,ini->cod_clientesta,ini->dni);
			printf("debe: %f | ult_v: %d/%d/%d | baja: %d\n",ini->debe,ini->f_ultima_vez.dd,ini->f_ultima_vez.mm,ini->f_ultima_vez.yy,ini->baja);
            printf("--------------\n");
			ini = ini->sgte;
		}
	}else
		printf("\nSIN TURNOS CLIENTES\n");
}


void listar_turnos_cliente(long int dni_cliente,turno_cliente *ini){
	if(ini!=NULL){
		while(ini != NULL){
			if(ini->dni == dni_cliente){
				printf("cod_t: %d | cod_a: %d | cod_clientesta: %d | dni: %ld |\n",ini->cod_turno,ini->cod_act,ini->cod_clientesta,ini->dni);
				printf("debe: %d | ult_v: %d/%d\n",ini->debe,ini->f_ultima_vez.dd,ini->f_ultima_vez.mm,ini->f_ultima_vez.yy);
				printf("--------------");
			}
			ini = ini->sgte;
		}
	}
}

int buscar_turno_cliente(int eleccion_turno_cliente,long int dni_cliente,turno_cliente *ini_clientesta){
	int buscar=0;
	printf("1Eleccion: %d, dni cliente: %ld\n",eleccion_turno_cliente,dni_cliente);
	while(ini_clientesta != NULL && buscar != 1){
		printf("Eleccion: %d, dni cliente: %ld\n",ini_clientesta->cod_clientesta,ini_clientesta->dni);
		if(ini_clientesta->cod_clientesta == eleccion_turno_cliente && ini_clientesta->dni == dni_cliente){
			buscar = 1;
		}
		ini_clientesta = ini_clientesta->sgte;
	}
	
	return buscar;
}

int buscar_dni_turno_cliente(long int dni,turno_cliente *ini_turno_cliente){
    int encontrado=0;
	while(ini_turno_cliente != NULL && encontrado != 1){
		if(ini_turno_cliente->dni == dni && ini_turno_cliente->baja == 0){
			encontrado = 1;
		}
		ini_turno_cliente = ini_turno_cliente->sgte;
	}
	
	return encontrado;
}

#endif

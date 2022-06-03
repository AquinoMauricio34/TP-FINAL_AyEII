//tenemos que comprobar que el cliente exista
//quitar los datos personales de la estructura
#ifndef ABM_RESERVAS_C
#define ABM_RESERVAS_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"

extern fecha fecha_global;

void ABM_reservas(reserva **ini_reserva,actividad *ini_actividad, tipo_turno *ini_tipo_turno,turno_cliente **ini_turno_cliente,cuenta **ini_cuenta){
    int opcion,encontrado,buscar,op,cont;
    long int dni_cliente;
    int eleccion_sede,eleccion_actividad,eleccion_tipo_turno;
    int numero_cod_clientesta;
    int numero_cod_turno;
    reserva *nv=NULL;
    actividad *aux_actividad = NULL;
    turno_cliente *aux_turno_cliente = NULL,*nv_t_cliente=NULL;
    cuenta *nv_cuenta=NULL;
    tipo_turno *aux_tipo_turno = NULL;
    do{

        do{
            system("cls");
            printf("1. Alta reserva\n");
            printf("2. Baja reserva\n");
            printf("3. Modificacion reserva\n");
            printf("4. Verificar lugar Disponible\n");
            printf("0.Atras\n");
            printf(">> ");scanf("%d",&opcion);
        }while(opcion<0 || opcion>4);

        //opcion 1
        switch(opcion){
            case 1:
                nv = malloc(sizeof(reserva));
                if(nv != NULL){
                    buscar = -1;
                    do{
                        if(buscar != -1){
                            printf("El dni ingresado ya esta registrado al sistema.\n");
                        }
                        printf("Ingresar dni del cliente: ");scanf("%ld",&dni_cliente);
                        buscar = buscar_dni_reserva(dni_cliente,*ini_reserva);
                    }while(buscar == 1 && dni_cliente != 0);

                    if(dni_cliente != 0){




                        

                        //elegimos entre sede 1 y sede 2
                        printf("Eliga la sede: ");scanf("%d",&eleccion_sede);
                        //luego
                        listar_actividades_sede(ini_actividad,eleccion_sede);
                        //elegimos una actividad
                        do{
                            printf("Ingresar codigo de la actividad: ");scanf("%d",&eleccion_actividad);
                            buscar = buscar_actividad_sede(eleccion_actividad,eleccion_sede,ini_actividad);
                        }while(buscar != 1 && eleccion_actividad != 0);
                        //ya elegida la actividad entra en un if(eleccion_actividad != 0)
                        if(eleccion_actividad != 0){
                            // printf("\nmmmmmmmmm\n");
                            // if(ini_tipo_turno==NULL){
                            //     printf("\nqwetqwetqr\n");
                            // }
                            listar_tipo_turno(ini_tipo_turno,eleccion_actividad);
                            //elegimos tipo turno
                            do{
                                printf("Ingresar codigo del tipo turno: ");scanf("%d",&eleccion_tipo_turno);
                                buscar = buscar_tipo_turno_actividad(eleccion_tipo_turno,eleccion_actividad,ini_tipo_turno);
                            }while(buscar != 1 && eleccion_tipo_turno != 0);
                            //ya elegido el tipo turno entra en un if(eleccion_tipo_turno != 0)
                            if(eleccion_tipo_turno != 0){
                                //guardamos el codigo el tipo_turno
                                nv->cod_turno = eleccion_tipo_turno;
                                //guardamos el codigo la activadad
                                nv->cod_act = eleccion_actividad;
                                fflush(stdin);
                                printf("Ingresar nombre del cliente: ");gets(nv->nombre);
                                nv->dni = dni_cliente;
                                printf("Ingresar telefono del cliente: ");scanf("%ld",&nv->telefono);
                                printf("Ingresar fecha de nacimiento del cliente (formato dd/mm/aa): ");scanf("%d/%d/%d",&nv->f_nacimiento.dd,&nv->f_nacimiento.mm,&nv->f_nacimiento.yy);
                                nv->ant = NULL;
                                nv->sgte = NULL;
                                // do{
                                //     printf("Esta seguro de que quiere realizar la reserva? (1.Si | 0.No): ");scanf("%d",&opcion);
                                // }while(opcion<0 || opcion>1);
                                // if(opcion){
                                    insertar_reserva(&nv,&*ini_reserva);
                                // }
                            }
                        }











                    }
                }

            break;
            case 2:
                buscar = 0;
                do{
                    printf("Ingresar dni guardado en el reserva: ");scanf("%ld",&dni_cliente);
                    buscar = buscar_dni_reserva(dni_cliente,*ini_reserva);
                }while(buscar != 1 && dni_cliente != 0);

                if(dni_cliente!=0){
                    printf("Esta seguro/a de que quiere eliminar al cliente (1. SI | 0. NO): ");
                    scanf("%d",&op);
                    if(op == 1){
                        borrar_nodo_reserva(dni_cliente,&*ini_reserva);
                    }
                }
            break;
            case 3:
                do{
                    printf("Ingresar dni del cliente: ");scanf("%ld",&dni_cliente);
                    buscar = buscar_dni_reserva(dni_cliente,*ini_reserva);
                }while(buscar != 1 && dni_cliente != 0);

                if(dni_cliente != 0){
                    do{
						system("cls");
						do{
							printf("1-modificar nombre del cliente \n");
							printf("2-modificar el telefono del cliente \n");
							printf("0-Finalizar\n>> ");
							scanf("%d",&op);
						}while(op<0 || op>2);
						// system("cls");
						modificar_reserva(dni_cliente,op,&*ini_reserva);
					}while(op!=0);
                }
                
            break;



            case 4:
                if(*ini_reserva != NULL){

                    cont = -1;//por si no existe la actividad
                    encontrado = 0;
                    eleccion_actividad = (*ini_reserva)->cod_act;
                    aux_actividad = ini_actividad;
                    while(aux_actividad != NULL){

                        if(aux_actividad->cod_act == eleccion_actividad){
                            // printf("\ncod: %d | %s\n",aux_actividad->cod_act,aux_actividad->nombre);
                            aux_turno_cliente = *ini_turno_cliente;
                            cont = 0;//se verifica que existe la actividad, entonces cont = 0
                            while(aux_turno_cliente != NULL){
                                if(aux_turno_cliente->cod_act == eleccion_actividad && aux_turno_cliente->baja == 0){
                                    cont++;
                                }
                                aux_turno_cliente = aux_turno_cliente->sgte;
                            }
                            // printf("\ncont = %d\n",cont);
                            if(cont < aux_actividad->cant_personas){
                                encontrado = 1;
                                // printf("\n111\n");
                            }

                            aux_actividad = NULL;
                        }else
                            aux_actividad = aux_actividad->sgte;
                    }
                    // system("pause");
                    if(encontrado == 1){
                        do{
                            system("cls");
                            printf("Lugar disponibles para reserva con dni: %ld\n",(*ini_reserva)->dni);
                            printf("Desea dar de alta al turno? (1. SI | 2. NO | 0. SALIR): ");
                            scanf("%d",&op);
                        }while(op<0 || op>2);

                        if(op == 1){
                            //antes de subir a la lista, de debe crear cuenta
                            if(*ini_reserva != NULL){
                                nv_t_cliente = malloc(sizeof(turno_cliente));
                                if(nv_t_cliente!= NULL){
                                // printf("\naaa %d\n",(*ini_reserva)->cod_act);
                            
                                nv_t_cliente->cod_act = (*ini_reserva)->cod_act;
                                // printf("\naaa111\n");
                                nv_t_cliente->cod_turno = (*ini_reserva)->cod_turno;
                                nv_t_cliente->dni = (*ini_reserva)->dni;
                                nv_t_cliente->debe = 0;
								nv_t_cliente->f_ultima_vez.dd = fecha_global.dd;
								nv_t_cliente->f_ultima_vez.mm = fecha_global.mm;
								nv_t_cliente->f_ultima_vez.yy = fecha_global.yy;
                                // printf("\naaa22222\n");
								nv_t_cliente->baja = 0;
								nv_t_cliente->incrementado = 0;
                                nv_t_cliente->sgte = NULL;
// printf("\nbbb\n");
                                *ini_reserva = (*ini_reserva)->sgte;

								
									insertar_codigo_cliente(&nv_t_cliente,&*ini_turno_cliente);
									numero_cod_clientesta = nv_t_cliente->cod_clientesta;
									numero_cod_turno = nv_t_cliente->cod_turno;
									insertar_clientesta(&nv_t_cliente,&*ini_turno_cliente);
									// crear cuenta pagada
									// printf("\n111\n");
									nv_cuenta = malloc(sizeof(cuenta));
									if(nv_cuenta != NULL){
										// printf("\n222\n");
										nv_cuenta->sgte = NULL;
										// printf("\n222111 %d\n",nv_t_cliente->cod_clientesta);
										nv_cuenta->cod_clientesta = numero_cod_clientesta;
										// printf("\n333\n");
										nv_cuenta->f_pago.dd = fecha_global.dd;
										nv_cuenta->f_pago.mm = fecha_global.mm;
										nv_cuenta->f_pago.yy = fecha_global.yy;
										// printf("\n444\n");
										aux_tipo_turno=ini_tipo_turno;
										// printf("\n555\n");
										while(aux_tipo_turno != NULL && buscar != 1){
											// printf("\ncod_t: %d, aux: %d\n",nv_t_cliente->cod_turno,aux_tipo_turno->cod_turno);
											if(numero_cod_turno == aux_tipo_turno->cod_turno){
                                                // printf("\n56565\n");
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
                        }else if(op == 2){
                            //eliminar el nodo
                        }
                    }else
                        printf("La reserva del cliente con el dni \"%ld\" no tiene lugar disponible.",(*ini_reserva)->dni);
                        system("pause");

                }else
                    printf("\nSIN RESERVAS\n");
                    system("pause");
            break;
        }
    }while(opcion != 0);
    free(nv);
}






void listar_actividades_sede(actividad *ini_actividad,int eleccion_sede){
    while(ini_actividad != NULL){
        // printf("elecc = %d, ini = %d\n",eleccion_sede,ini_actividad->sede);
        if(eleccion_sede == ini_actividad->sede || ini_actividad->sede == -1/* && ini_actividad->estado == 1*/){
            printf("%-10d| %s\n",ini_actividad->cod_act,ini_actividad->nombre);
        }
        ini_actividad = ini_actividad->sgte;
	}
}
int buscar_actividad_sede(int eleccion_actividad,int eleccion_sede,actividad *ini_actividad){
    int buscar=0;
	while(ini_actividad != NULL && buscar != 1){
		if(ini_actividad->cod_act == eleccion_actividad && (ini_actividad->sede == eleccion_sede || ini_actividad->sede == -1) && ini_actividad->estado != 0){
			buscar = 1;
		}
		ini_actividad = ini_actividad->sgte;
	}
	
	return buscar;
}



void listar_tipo_turno(tipo_turno *ini_tipo_turno,int eleccion_actividad){
    char nombres_dias_sem[5][15]={"Lunes","Martes","Miercoles","Jueves","Vienes"};
    int i;
    
    // printf("\n111\n");
    while(ini_tipo_turno != NULL){
        // printf("\n222\n");
        if(eleccion_actividad == ini_tipo_turno->cod_act && ini_tipo_turno->estado == 1){
            printf("\n----------\n");
            printf("cod_t: %7d | cod_act: %7d | precio: %.2f | est: %d\n",ini_tipo_turno->cod_turno,ini_tipo_turno->cod_act,ini_tipo_turno->precio,ini_tipo_turno->estado);
            printf("%d:%d | %d:%d\n",ini_tipo_turno->hora_inicio_turno.hh,ini_tipo_turno->hora_inicio_turno.mm,ini_tipo_turno->hora_fin_turno.hh,ini_tipo_turno->hora_fin_turno.mm);
            // printf("\n444\n");
            for(i=0;i<5;i++){
                // printf("\n444\n");
                if(ini_tipo_turno->dias[i]==1){
                    printf("%s, \n",nombres_dias_sem[i]);
                    // printf("\n555\n");
                }
            }
            printf("\n");
        }
        ini_tipo_turno = ini_tipo_turno->sgte;
	}
    // printf("\n666\n");
}

int buscar_tipo_turno_actividad(int eleccion_tipo_turno,int eleccion_actividad,tipo_turno *ini_tipo_turno){
    int buscar=0;
	while(ini_tipo_turno != NULL && buscar != 1){
		if(ini_tipo_turno->cod_turno == eleccion_tipo_turno && ini_tipo_turno->cod_act == eleccion_actividad){
			buscar = 1;
		}else{
			buscar = 0;
		}
		ini_tipo_turno = ini_tipo_turno->sgte;
	}
	
	return buscar;
}














void borrar_nodo_reserva(long int dni_borrar, reserva **ini){
	reserva *bor=NULL,*ant=NULL,*aux=NULL;
	int proceder = 0;
	bor = *ini;
	buscar_borrar_reserva(dni_borrar,&bor,&ant,&proceder);
	if(bor != NULL){
		if(ant==NULL){
			*ini = (*ini)->sgte;
			bor->sgte = NULL;
			if(*ini!=NULL){
				(*ini)->ant = NULL;
			}
			// printf("d\n");
		}else{
			ant->sgte = bor->sgte;
			if(bor->sgte != NULL){
				aux = bor->sgte;
				aux->ant = ant;
				bor->sgte = NULL;
				aux = NULL;
			}else
			bor->ant = NULL;
			ant = NULL;
		}
	}
	free(bor);

}	

void buscar_borrar_reserva(long int dni_borrar,reserva **rc,reserva **ant,int *proceder){
	*proceder = 0;
	
	*ant = NULL;
	while(rc!=NULL && *proceder == 0){
		if((*rc)->dni == dni_borrar){
			*proceder = 1;
		}else{
			*ant = *rc;
			*rc = (*rc)->sgte;
		}
	}
}


























int buscar_dni_reserva(long int dni,reserva *ini_reserva){
    int encontrado=0;
	while(ini_reserva != NULL && encontrado != 1){
		if(ini_reserva->dni == dni){
			encontrado = 1;
		}else{
			encontrado = 0;
		}
		ini_reserva = ini_reserva->sgte;
	}
	
	return encontrado;
}


















void insertar_reserva(reserva **nv,reserva **ini_reserva){
    reserva *aux=NULL;
    aux=*ini_reserva;
    if(*ini_reserva != NULL){

        while(aux->sgte != NULL){
            aux = aux->sgte;
        }

        aux->sgte = *nv;
        (*nv)->ant = aux;
        *nv = NULL;
    }else{
        *ini_reserva = *nv;
        *nv = NULL;
    }
}


















void modificar_reserva(long int dato,int op,reserva **ini_reserva){
	int buscar=0;
    reserva *aux=*ini_reserva;
	while(aux != NULL){
		
		if(aux->dni == dato && buscar != 1){
		
			if(op==1){
				fflush(stdin);
				gets(aux->nombre);
			}else if(op==2){
				scanf("%ld",&aux->telefono);
			}
			buscar = 1;
		}
		
		aux = aux->sgte;	
	}
}















void listar_reservas(reserva *ini){
	if(ini!=NULL){
		while(ini != NULL){
			printf("dni: %-10ld| nomb: %30s| tel: %10ld| nacim: %d/%d/%d\n",ini->dni,ini->nombre,ini->telefono,ini->f_nacimiento.dd,ini->f_nacimiento.mm,ini->f_nacimiento.yy);
            printf("cod_act: %7d | cod_tt: %7d |\n",ini->cod_act,ini->cod_turno);
            printf("--------------");
			ini = ini->sgte;
		}
	}else
		printf("\nSIN RESERVAS\n");
}


#endif

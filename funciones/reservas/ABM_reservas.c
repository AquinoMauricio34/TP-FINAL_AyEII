//estado verificado
#ifndef ABM_RESERVAS_C
#define ABM_RESERVAS_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"

extern fecha fecha_global;

void ABM_reservas(reserva **ini_reserva,actividad *ini_actividad, tipo_turno *ini_tipo_turno,turno_cliente **ini_turno_cliente,cuenta **ini_cuenta,cliente *ini_cliente){
    int opcion,encontrado,buscar,op,cont;
    long int dni_cliente;
    int eleccion_sede,eleccion_actividad,eleccion_tipo_turno;
    int numero_cod_clientesta;
    int numero_cod_turno;
    reserva *nv=NULL,*aux_reserva= NULL;
    actividad *aux_actividad = NULL;
    turno_cliente *aux_turno_cliente = NULL,*nv_t_cliente=NULL;
    cuenta *nv_cuenta=NULL;
    tipo_turno *aux_tipo_turno = NULL;
    do{

        do{
            system("cls");
            printf("1. Alta reserva\n");
            printf("2. Baja reserva\n");
            printf("3. Verificar lugar Disponible\n");
            printf("0.Atras\n");
            printf(">> ");scanf("%d",&opcion);
        }while(opcion<0 || opcion>3);

        //opcion 1
        switch(opcion){
            case 1:
                nv = malloc(sizeof(reserva));
                if(nv != NULL){
                    buscar = -1;
                    // do{
                        system("cls");
                    //     if(buscar != -1){
                    //         printf("El DNI ingresado ya esta registrado al sistema.\n");
                    //     }
                        printf("Ingresar dni del cliente: ");scanf("%ld",&dni_cliente);
                    //     buscar = buscar_dni_reserva(dni_cliente,*ini_reserva);
                    // }while(buscar == 1 && dni_cliente != 0);

                    if(dni_cliente != 0){




                        

                        //elegimos entre sede 1 y sede 2
                        printf("Eliga la sede 1 | 2: ");scanf("%d",&eleccion_sede);
                        //luego
                        //elegimos una actividad
                        do{
                            system("cls");
                            listar_actividades_sede(ini_actividad,eleccion_sede);
                            printf("Ingresar codigo de la actividad: ");scanf("%d",&eleccion_actividad);
                            buscar = buscar_actividad_sede(eleccion_actividad,eleccion_sede,ini_actividad);
                        }while(buscar != 1 && eleccion_actividad != 0);
                        //ya elegida la actividad entra en un if(eleccion_actividad != 0)
                        if(eleccion_actividad != 0){
                            //elegimos tipo turno
                            do{
                                system("cls");
                                listar_tipo_turno(ini_tipo_turno,eleccion_actividad);
                                printf("Ingresar codigo del tipo turno: ");scanf("%d",&eleccion_tipo_turno);
                                buscar = buscar_tipo_turno_actividad(eleccion_tipo_turno,eleccion_actividad,ini_tipo_turno);
                            }while(buscar != 1 && eleccion_tipo_turno != 0);
                            //ya elegido el tipo turno entra en un if(eleccion_tipo_turno != 0)
                            if(eleccion_tipo_turno != 0){
                                //guardamos el codigo el tipo_turno
                                nv->cod_turno = eleccion_tipo_turno;
                                //guardamos el codigo la activadad
                                nv->cod_act = eleccion_actividad;
                                nv->dni = dni_cliente;
                                printf("Ingresar el telefono del cliente a reservar: ");scanf("%ld",&nv->telefono);
                                nv->ant = NULL;
                                nv->sgte = NULL;
                                insertar_reserva(&nv,&*ini_reserva);
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
            // case 3:
            case 3:
                if(*ini_reserva != NULL){

                    cont = -1;//por si no existe la actividad
                    encontrado = 0;
                    eleccion_actividad = (*ini_reserva)->cod_act;
                    aux_actividad = ini_actividad;
                    while(aux_actividad != NULL){

                        if(aux_actividad->cod_act == eleccion_actividad){
                            aux_turno_cliente = *ini_turno_cliente;
                            cont = 0;//se verifica que existe la actividad, entonces cont = 0
                            while(aux_turno_cliente != NULL){
                                if(aux_turno_cliente->cod_act == eleccion_actividad && aux_turno_cliente->baja == 0){
                                    cont++;
                                }
                                aux_turno_cliente = aux_turno_cliente->sgte;
                            }
                            if(cont < aux_actividad->cant_personas){
                                encontrado = 1;
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
                            printf("Telefono del cliente: %ld\n",(*ini_reserva)->telefono);
                            printf("Desea dar de alta al turno? (1. SI | 2. NO (ELMINAR) | 0. SALIR): ");
                            scanf("%d",&op);
                        }while(op<0 || op>2);

                        if(op == 1){
                            //antes de subir a la lista, de debe crear cuenta
                            if(*ini_reserva != NULL){
                                buscar = 0;
                                buscar = buscar_dni_cliente((*ini_reserva)->dni,ini_cliente);
                                if(buscar != 0){
                                    nv_t_cliente = malloc(sizeof(turno_cliente));
                                    if(nv_t_cliente!= NULL){
                                
                                    nv_t_cliente->cod_act = (*ini_reserva)->cod_act;
                                    nv_t_cliente->cod_turno = (*ini_reserva)->cod_turno;
                                    nv_t_cliente->dni = (*ini_reserva)->dni;
                                    nv_t_cliente->debe = 0;
                                    nv_t_cliente->f_ultima_vez.dd = fecha_global.dd;
                                    nv_t_cliente->f_ultima_vez.mm = fecha_global.mm;
                                    nv_t_cliente->f_ultima_vez.yy = fecha_global.yy;
                                    nv_t_cliente->baja = 0;
                                    nv_t_cliente->incrementado = 0;
                                    nv_t_cliente->sgte = NULL;
                                    aux_reserva = *ini_reserva;
                                    *ini_reserva = (*ini_reserva)->sgte;

                                    
                                        insertar_codigo_cliente(&nv_t_cliente,&*ini_turno_cliente);
                                        numero_cod_clientesta = nv_t_cliente->cod_clientesta;
                                        numero_cod_turno = nv_t_cliente->cod_turno;
                                        insertar_clientesta(&nv_t_cliente,&*ini_turno_cliente);
                                        // crear cuenta pagada
                                        nv_cuenta = malloc(sizeof(cuenta));
                                        if(nv_cuenta != NULL){
                                            nv_cuenta->sgte = NULL;
                                            nv_cuenta->cod_clientesta = numero_cod_clientesta;
                                            nv_cuenta->f_pago.dd = fecha_global.dd;
                                            nv_cuenta->f_pago.mm = fecha_global.mm;
                                            nv_cuenta->f_pago.yy = fecha_global.yy;
                                            aux_tipo_turno=ini_tipo_turno;
                                            buscar = 0;
                                            while(aux_tipo_turno != NULL && buscar != 1){
                                                if(numero_cod_turno == aux_tipo_turno->cod_turno){
                                                    nv_cuenta->precio = aux_tipo_turno->precio;
                                                    // break;
                                                    buscar = 1;//reutilizo la variable para no crear otra
                                                }
                                                aux_tipo_turno = aux_tipo_turno->sgte;
                                            }
                                            insertar_cuenta(&nv_cuenta,&*ini_cuenta);
                                        }else
                                            printf("No se puede crear la cuenta");
                                        printf("TURNO DE CLIENTE CREADO EXITOSAMENTE.\n");
                                    free(aux_reserva);
                                    }
                                }else
                                    printf("EL CLIENTE DEBE SER REGISTRADO ANTES DE CARGAR SU TURNO.\n");
                                    system("pause");
                            }
                            
                        }else if(op == 2){
                            //eliminar el nodo
                            aux_reserva = *ini_reserva;
                            *ini_reserva = (*ini_reserva)->sgte;
                            free(aux_reserva);
                            printf("RESERVA ELIMINADA\n");
                            system("pause");
                        }
                    }else
                        printf("La reserva del cliente con el dni \"%ld\" no tiene lugar disponible.\n",(*ini_reserva)->dni);
                        system("pause");
                aux_actividad=NULL;
                aux_turno_cliente=NULL;
                aux_tipo_turno=NULL;
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
        if((eleccion_sede == ini_actividad->sede || ini_actividad->sede == -1) && ini_actividad->estado == 1){
            printf("%-10d| %s\n",ini_actividad->cod_act,ini_actividad->nombre);
        }
        ini_actividad = ini_actividad->sgte;
	}
}
int buscar_actividad_sede(int eleccion_actividad,int eleccion_sede,actividad *ini_actividad){
    int buscar=0;
	while(ini_actividad != NULL && buscar != 1){
		if(ini_actividad->cod_act == eleccion_actividad && (ini_actividad->sede == eleccion_sede || ini_actividad->sede == -1) && ini_actividad->estado == 1){
			buscar = 1;
		}
		ini_actividad = ini_actividad->sgte;
	}
	
	return buscar;
}



void listar_tipo_turno(tipo_turno *ini_tipo_turno,int eleccion_actividad){
    char nombres_dias_sem[5][15]={"Lunes","Martes","Miercoles","Jueves","Vienes"};
    int i;
    
    while(ini_tipo_turno != NULL){
        if(eleccion_actividad == ini_tipo_turno->cod_act && ini_tipo_turno->estado == 1){
            printf("\n----------\n");
            printf("cod_t: %7d | cod_act: %7d | precio: %.2f | est: %d\n",ini_tipo_turno->cod_turno,ini_tipo_turno->cod_act,ini_tipo_turno->precio,ini_tipo_turno->estado);
            printf("%d:%d | %d:%d\n",ini_tipo_turno->hora_inicio_turno.hh,ini_tipo_turno->hora_inicio_turno.mm,ini_tipo_turno->hora_fin_turno.hh,ini_tipo_turno->hora_fin_turno.mm);
            for(i=0;i<5;i++){
                if(ini_tipo_turno->dias[i]==1){
                    printf("%s, \n",nombres_dias_sem[i]);
                }
            }
            printf("\n");
        }
        ini_tipo_turno = ini_tipo_turno->sgte;
	}
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
		
			// if(op==1){
			// 	fflush(stdin);
			// 	gets(aux->nombre);
			// }else if(op==2){
			// 	scanf("%ld",&aux->telefono);
			// }
			buscar = 1;
		}
		
		aux = aux->sgte;	
	}
}



void listar_reservas(reserva *ini){
	if(ini!=NULL){
		while(ini != NULL){
			printf("dni: %-10ld\n",ini->dni);
            printf("cod_act: %7d | cod_tt: %7d |\n",ini->cod_act,ini->cod_turno);
            printf("--------------");
			ini = ini->sgte;
		}
	}else
		printf("\nSIN RESERVAS\n");
}


#endif

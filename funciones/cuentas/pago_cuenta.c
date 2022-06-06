
#ifndef PAGO_CUENTA_C
#define PAGO_CUENTA_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"

extern fecha fecha_global;

void pago_cuenta(turno_cliente **ini_turno_cliente,actividad *ini_actividad,tipo_turno *ini_tipo_turno,cuenta **ini_cuenta){
    int buscar;
    long int dni_cliente;
    int eleccion_sede,eleccion_actividad,eleccion_turno_cliente;
    cuenta *nv_cuenta=NULL;
    tipo_turno *aux_tipo_turno=NULL;
    turno_cliente *aux_turno_cliente=NULL;
    buscar = 0;
    do{
        system("cls");
        printf("Ingresar dni del cliente: ");scanf("%ld",&dni_cliente);
        buscar = buscar_dni_turno_cliente_cuenta(dni_cliente,*ini_turno_cliente);
    }while(buscar != 1 && dni_cliente != 0);

    if(dni_cliente != 0){
        do{
            system("cls");
            printf("Elegir la sede 1 | 2 (0 para salir): ");
            scanf("%d",&eleccion_sede);
        }while(eleccion_sede<0 || eleccion_sede>2);
        if(eleccion_sede != 0){
            listar_actividades_sede(ini_actividad,eleccion_sede);

            do{
                system("cls");
                printf("Ingresar codigo de la actividad: ");scanf("%d",&eleccion_actividad);
                buscar = buscar_actividad_sede(eleccion_actividad,eleccion_sede,ini_actividad);
            }while(buscar != 1 && eleccion_actividad != 0);

            if(eleccion_actividad != 0){
                buscar = 0;
                do{
                    system("cls");
                    listar_turnos_cliente_segunactividad(dni_cliente,eleccion_actividad,*ini_turno_cliente);
                    if(buscar == -1){
                        printf("Cuenta ya pagada.\n");
                    }
                    aux_turno_cliente = *ini_turno_cliente;
                    printf("Ingresar codigo del turno cliente: ");scanf("%d",&eleccion_turno_cliente);
                    buscar = buscar_turno_cliente_cuenta(eleccion_turno_cliente,eleccion_actividad,dni_cliente,&aux_turno_cliente);
                }while(buscar != 1 && eleccion_turno_cliente != 0);

                if(eleccion_turno_cliente != 0){
                    //una vez que encontramos el turno, creamos la cuenta
                    //el precio que se paga es el que tiene el debe en el turno
                    nv_cuenta = malloc(sizeof(cuenta));
                    if(nv_cuenta != NULL){
                        nv_cuenta->cod_clientesta = eleccion_turno_cliente;
                        nv_cuenta->f_pago.dd = fecha_global.dd;
                        nv_cuenta->f_pago.mm = fecha_global.mm;
                        nv_cuenta->f_pago.yy = fecha_global.yy;
                        nv_cuenta->precio = aux_turno_cliente->debe;
                        nv_cuenta->sgte = NULL;
                        insertar_cuenta(&nv_cuenta,&*ini_cuenta);

                        aux_turno_cliente->debe = 0;
                        aux_turno_cliente = NULL;
                        aux_tipo_turno = NULL;
                    }
                }
            }

        }

    }
}

void insertar_cuenta(cuenta **nv,cuenta **ini_cuenta){
    cuenta *aux=NULL;
    aux=*ini_cuenta;
    if(*ini_cuenta != NULL){

        while(aux->sgte != NULL){
            aux = aux->sgte;
        }

        aux->sgte = *nv;
        *nv = NULL;
    }else{
        *ini_cuenta = *nv;
        *nv = NULL;
    }
}

int buscar_turno_cliente_cuenta(int eleccion_turno_cliente,int eleccion_actividad,long int dni_cliente,turno_cliente **ini_clientesta){
	int buscar=0;
	while(*ini_clientesta != NULL && buscar != 1 && buscar != -1){
		if((*ini_clientesta)->cod_clientesta == eleccion_turno_cliente && (*ini_clientesta)->cod_act == eleccion_actividad && (*ini_clientesta)->dni == dni_cliente){
			if((*ini_clientesta)->debe > 0)
				buscar = 1;
			else
				buscar = -1;
		}else
	        *ini_clientesta =(*ini_clientesta)->sgte;
	}
	
	return buscar;
}

int buscar_dni_turno_cliente_cuenta(long int dni,turno_cliente *ini_turno_cliente){
    int encontrado=0;
	while(ini_turno_cliente != NULL && encontrado != 1){
		if(ini_turno_cliente->dni == dni){
			encontrado = 1;
		}
		ini_turno_cliente = ini_turno_cliente->sgte;
	}
	
	return encontrado;
}

void listar_turnos_cliente_segunactividad(long int dni_cliente,int eleccion_actividad,turno_cliente *ini){
    if(ini!=NULL){
        printf("%-10s | %-13s | %-13s | %-10s | %-7s | %-17s | %-7s |\n","CODIGO","CODIGO","CODIGO","DNI","DEBE","F. ULTIMA","BAJA");
 		printf("%-10s | %-13s | %-13s | %-10s | %-7s | %-17s | %-7s |\n\n","TURNO","ACTIVIDAD","T. CLIENTE","","","VEZ","");
		while(ini != NULL){
			if(ini->dni == dni_cliente && ini->cod_act == eleccion_actividad){
                printf("%-10d | %-13d | %-13d | %-10ld | %-7.2f | %-10d/%d/%d | %-7d |\n",ini->cod_turno,ini->cod_act,ini->cod_clientesta,ini->dni, ini->debe,ini->f_ultima_vez.dd,ini->f_ultima_vez.mm,ini->f_ultima_vez.yy,ini->baja);
			}
			ini = ini->sgte;
		}
	}
}


void listar_all_cuentas(cuenta *ini){
    if(ini!=NULL){
			printf("%-10s | %-7s | %-13s |\n","CODIGO","PRECIO","FECHA");
			printf("%-10s | %-7s | %-13s |\n\n","T. CLIENTE","","PAGO");
		while(ini != NULL){
			printf("%-10d | %-7.2f | %-13d/%d/%d |\n",ini->cod_clientesta,ini->precio,ini->f_pago.dd,ini->f_pago.mm,ini->f_pago.yy);
			ini = ini->sgte;
		}
	}else
		printf("\nSIN CUENTAS\n");
}

#endif
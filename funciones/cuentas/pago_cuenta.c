
#ifndef PAGO_CUENTA_C
#define PAGO_CUENTA_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"

void pago_cuenta(turno_cliente *ini_turno_cliente,actividad *ini_actividad){
    int buscar;
    long int dni_cliente;
    int eleccion_sede,eleccion_actividad,eleccion_turno_cliente;
    buscar = 0;
    do{
        printf("Ingresar dni del cliente: ");scanf("%ld",&dni_cliente);
        buscar = buscar_dni_turno_cliente(dni_cliente,ini_turno_cliente);
    }while(buscar != 1 && dni_cliente != 0);

    if(dni_cliente != 0){
        do{
            printf("Elegir la sede 1 | 2 (0 para salir): ");
            scanf("%d",&eleccion_sede);
        }while(eleccion_sede<1 || eleccion_sede>2);

        listar_actividades_sede(ini_actividad,eleccion_sede);

        do{
            printf("Ingresar codigo de la actividad: ");scanf("%d",&eleccion_actividad);
            buscar = buscar_actividad_sede(eleccion_actividad,eleccion_sede,ini_actividad);
        }while(buscar != 1 && eleccion_actividad != 0);

        if(eleccion_actividad != 0){
            listar_turnos_cliente_segunactividad(dni_cliente,eleccion_actividad,ini_turno_cliente);

            do{
                printf("Ingresar codigo del tipo turno: ");scanf("%d",&eleccion_turno_cliente);
                buscar = buscar_turno_cliente_cuenta(eleccion_turno_cliente,eleccion_actividad,dni_cliente,ini_turno_cliente);
            }while(buscar != 1 && eleccion_turno_cliente != 0);

            if(eleccion_turno_cliente != 0){

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

int buscar_turno_cliente_cuenta(int eleccion_turno_cliente,int eleccion_actividad,long int dni_cliente,turno_cliente *ini_clientesta){
	int buscar=0;
	printf("1Eleccion: %d, dni cliente: %ld\n",eleccion_turno_cliente,dni_cliente);
	while(ini_clientesta != NULL && buscar != 1){
		printf("Eleccion: %d, dni cliente: %ld\n",ini_clientesta->cod_clientesta,ini_clientesta->dni);
		if(ini_clientesta->cod_clientesta == eleccion_turno_cliente && ini_clientesta->cod_act == eleccion_actividad && ini_clientesta->dni == dni_cliente){
			buscar = 1;
		}
		ini_clientesta = ini_clientesta->sgte;
	}
	
	return buscar;
}

void listar_turnos_cliente_segunactividad(long int dni_cliente,int eleccion_actividad,turno_cliente *ini){
    if(ini!=NULL){
		while(ini != NULL){
			if(ini->dni == dni_cliente && ini->cod_act == eleccion_actividad){
				printf("cod_t: %d | cod_a: %d | cod_clientesta: %d | dni: %ld |\n",ini->cod_turno,ini->cod_act,ini->cod_clientesta,ini->dni);
				printf("debe: %d | ult_v: %d/%d\n",ini->debe,ini->f_ultima_vez.dd,ini->f_ultima_vez.mm,ini->f_ultima_vez.yy);
				printf("--------------");
			}
			ini = ini->sgte;
		}
	}
}

#endif
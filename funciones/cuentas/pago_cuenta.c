
#ifndef PAGO_CUENTA_C
#define PAGO_CUENTA_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"

// void pago_cuenta(turno_cliente **ini_turno_cliente,actividad *ini_actividad){
//     int buscar;
//     long int dni_cliente;
//     int eleccion_sede;
//     buscar = 0;
//     do{
//         printf("Ingresar dni del cliente: ");scanf("%ld",&dni_cliente);
//         buscar = buscar_dni_turno_cliente(dni_cliente,*ini_turno_cliente);
//     }while(buscar != 1 && dni_cliente != 0);

//     if(dni_cliente != 0){
//         do{
//             printf("Elegir la sede 1 | 2 (0 para salir): ");
//             scanf("%d",&eleccion_sede);
//         }while(eleccion_sede<1 || eleccion_sede>2);

//         listar_actividades_sede(ini_actividad,eleccion_sede);




//     }
// }

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


#endif
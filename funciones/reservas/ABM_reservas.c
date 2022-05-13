#ifndef ABM_RESERVAS_C
#define ABM_RESERVAS_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"

void ABM_reservas(reserva **ini_reserva){
    int opcion,encontrado,buscar;
    long int dni_quitar;
    reserva *nv=NULL;
    do{
        system("cls");
        printf("1. Alta reserva\n");
        printf("2. Baja reserva\n");
        printf("3. Modificacion reserva\n");
        printf("0.Atras\n");
        printf(">> ");scanf("%d",&opcion);
    }while(opcion<0 || opcion>3);

    //opcion 1
    switch(opcion){
        case 1:
            nv = malloc(sizeof(reserva));
            if(nv != NULL){
                fflush(stdin);
                printf("Ingresar nombre del cliente: ");gets(nv->nombre);
                printf("Ingresar DNI del cliente: ");scanf("%ld",&nv->dni);
                printf("Ingresar telefono del cliente: ");scanf("%ld",&nv->telefono);
                printf("Ingresar fecha de nacimiento del cliente (formato dd/mm/aa): ");scanf("%d/%d/%d",&nv->f_nacimiento.dd,&nv->f_nacimiento.mm,&nv->f_nacimiento.yy);
                do{
                    printf("Esta seguro de que quiere realizar la reserva? (1.Si, 0.No): ");scanf("%d",&opcion);
                }while(opcion<0 || opcion>1);
                if(opcion){
                    insertar_reserva(&nv,&*ini_reserva);
                }
            }
        break;
        case 2:
            do{
                printf("Ingresar dni guardado en el reserva: ");scanf("%ld",&dni_quitar);
                buscar = buscar_dni_reserva(dni_quitar,*ini_reserva);
            }while(buscar != 1 || dni_quitar != 0);
        break;
        case 3:

        break;
    }
}

#endif

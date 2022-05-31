#ifndef BORRAR_NODO_CLIENTEST_C
#define BORRAR_NODO_CLIENTEST_C


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"

void borrar_nodo_clientest(int buscar_borrar,turno_cliente **ini_clientest){
    turno_cliente *bor=*ini_clientest,*ant=NULL;
    // printf("\n111\n");
    buscar_borrar_clientest(buscar_borrar,&bor,&ant);
    // printf("\n222\n");
    if(bor != NULL){
        if(ant == NULL){
            *ini_clientest = (*ini_clientest)->sgte;
            // printf("\n333\n");
        }else{
        ant->sgte = bor->sgte;
        // printf("\n444\n");
        }
        bor->sgte = NULL;
        free(bor);
        // printf("\n555\n");
    }else
        printf("no existe el dato no esta en la lista\n");
}

void borrar_nodo_baja(turno_cliente **ini_turno_cliente){
    turno_cliente *aux_turno_cliente=*ini_turno_cliente,*aux2=NULL;
    while(aux_turno_cliente != NULL){
        printf("\ncod; %d, baja; %d, debe; %f\n",aux_turno_cliente->cod_clientesta,aux_turno_cliente->debe);
        if(aux_turno_cliente->baja == 1 && aux_turno_cliente->debe == 0){
            printf("\n222\n");
            aux2 = aux_turno_cliente->sgte;
            borrar_nodo_clientest(aux_turno_cliente->cod_clientesta,&*ini_turno_cliente);
            aux_turno_cliente = aux2;
        }else
            aux_turno_cliente = aux_turno_cliente->sgte;
    }
    system("pause");
}
#endif

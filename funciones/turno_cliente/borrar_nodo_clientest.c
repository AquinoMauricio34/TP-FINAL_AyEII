#ifndef BORRAR_NODO_CLIENTEST_C
#define BORRAR_NODO_CLIENTEST_C


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"

void borrar_nodo_clientest(int buscar_borrar,turno_cliente **ini_clientest){
    turno_cliente *bor=*ini_clientest,*ant=NULL;
    printf("\n111\n");
    buscar_borrar_clientest(buscar_borrar,&bor,&ant);
    printf("\n222\n");
    if(bor != NULL){
        if(ant == NULL){
            *ini_clientest = (*ini_clientest)->sgte;
            printf("\n333\n");
        }else{
        ant->sgte = bor->sgte;
        printf("\n444\n");
        }
        bor->sgte = NULL;
        free(bor);
        printf("\n555\n");
    }else
        printf("no existe el dato no esta en la lista\n");
}
#endif
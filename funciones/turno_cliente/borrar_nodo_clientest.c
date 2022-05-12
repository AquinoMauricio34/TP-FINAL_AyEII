#ifndef BORRAR_NODO_CLIENTEST_C
#define BORRAR_NODO_CLIENTEST_C


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"

void borrar_nodo_clientest(long int buscar_borrar,turno_cliente **ini_clientest){
turno_cliente *bor=*ini_clientest,*ant=NULL;
buscar_borrar_clientest(dato,bor,ant);
if(bor != NULL){
    if(ant != NULL){
       *ini_clientest = (*ini_clientest)->sgte;
    }else{
    ant->sgte = bor->sgte;
    }
    bor->sgte = NULL;
    free(bor);
}else
     printf("no existe el dato no esta en la lista\n");
}
#endif
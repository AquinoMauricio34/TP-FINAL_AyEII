#ifndef BORRAR_CLIENTE_C
#define BORRAR_CLIENTE_C


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"

void borrar_nodo_cliente(int dato,cliente **ini_cliente){
cliente *bor=*ini_cliente,*ant=NULL;
//la funcion no está creada--------------------------------------------------
// buscar_borrar_cliente(dato,&bor,&ant);
if(bor != NULL){
    if(ant != NULL){
       *ini_cliente = (*ini_cliente)->sgte;
    }else{
    ant->sgte = bor->sgte;
    }
    bor->sgte = NULL;
    free(bor);
}else
     printf("no existe el dato no esta en la lista\n");
}
#endif
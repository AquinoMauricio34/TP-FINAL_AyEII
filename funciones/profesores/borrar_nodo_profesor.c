#ifndef BORRAR_PROFESOR_C
#define BORRAR_PROFESOR_C


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"

void borrar_nodo_profesor(int dato,profesor **ini_profesor){
    profesor *bor=*ini_profesor,*ant=NULL;
    buscar_borrar_profesor(dato,&bor,&ant);
    if(bor != NULL){
        if(ant == NULL){
           *ini_profesor = (*ini_profesor)->sgte;
        }else{
            ant->sgte = bor->sgte;
        }
        bor->sgte = NULL;
        free(bor);
    }else
         printf("no existe el dato no esta en la lista\n");
}
#endif

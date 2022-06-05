#ifndef BORRAR_ACTIVIDAD_C
#define BORRAR_ACTIVIDAD_C


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"

void borrar_nodo_actividad(int dato,actividad **ini_actividad){
actividad *bor=*ini_actividad,*ant=NULL;
//la funcion no está creada--------------------------------------------------
buscar_borrar_actividad(dato,&bor,&ant);
if(bor != NULL){
    if(ant == NULL){
       *ini_actividad = (*ini_actividad)->sgte;
    }else{
    ant->sgte = bor->sgte;
    }
    bor->sgte = NULL;
    free(bor);
}else
     printf("no existe el dato no esta en la lista\n");
}


void buscar_borrar_actividad(int dato,actividad **bor,actividad **ant){
    *ant = NULL;
    int encontrado=0;
    
    while(*bor != NULL && encontrado != 1){
        if(dato == (*bor)->cod_act){
            encontrado = 1;
        }else{
            *ant = *bor;
            *bor = (*bor)->sgte;
        }
    }
}

#endif
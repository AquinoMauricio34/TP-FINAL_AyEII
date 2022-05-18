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
printf("\naaa\n");
buscar_borrar_actividad(dato,&bor,&ant);
printf("\nbbb\n");
if(bor != NULL){
    // printf("bor->nombre = ");puts(bor->nombre);
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
    printf("\naaa111\n");
    int encontrado=0;
    printf("\naaa222\n");
    
    while(*bor != NULL && encontrado != 1){
        printf("\naaa333\n");
        printf("1bor->cod_act = %d, bor->nombre = \n",(*bor)->cod_act);puts((*bor)->nombre);
        system("pause");
        if(dato == (*bor)->cod_act){
            printf("\naaa444\n");
            encontrado = 1;
        }else{
            printf("\naaa555\n");
            *ant = *bor;
            *bor = (*bor)->sgte;
        }
    }
}

#endif
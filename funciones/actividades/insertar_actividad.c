#ifndef INSERTAR_ACTIVIDAD_C
#define INSERTAR_ACTIVIDAD_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
void insertar_actividad(actividad **nv, actividad **ini_actividad){
    actividad *aux = *ini_actividad;
    if(*ini_actividad != NULL){
        while(aux->sgte != NULL){
            aux = aux->sgte;
        }
        aux->sgte = *nv;
        *nv = NULL;
    }else{
        *ini_actividad = *nv;
        *nv = NULL;
	}
    
}
#endif
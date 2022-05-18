#ifndef BUSCAR_BORRAR_C
#define BUSCAR_BORRAR_C


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
void buscar_borrar_profesor(long int dato,profesor **bor,profesor **ant){
    *ant = NULL;
    int encontrado=0;
    while(*bor != NULL && encontrado != 1){
        if(dato == (*bor)->dni){
            encontrado = 1;
        }else{
            *ant = *bor;
            *bor = (*bor)->sgte;
        }
    }
}
#endif
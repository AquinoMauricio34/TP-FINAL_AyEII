#ifndef BUSCAR_BORRAR_CLIENTEST_C
#define BUSCAR_BORRAR_CLIENTEST_C


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
void buscar_borrar_clientest(long int dato,turno_cliente **bor,turno_cliente **ant){
    *ant = NULL;
    int encontrado=0;
    while(*bor != NULL && encontrado != 1){
        if(dato == (*bor)->cod_clientesta){
            encontrado = 1;
        }else{
            *ant = *bor;
            *bor = (*bor)->sgte;
        }
    }
}
#endif
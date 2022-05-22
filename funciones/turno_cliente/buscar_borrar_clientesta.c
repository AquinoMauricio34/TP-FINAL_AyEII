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
        printf("\n111222\n");
        if(dato == (*bor)->cod_clientesta){
            encontrado = 1;
            printf("\n111333\n");
        }else{
            *ant = *bor;
            *bor = (*bor)->sgte;
            printf("\n111444\n");
        }
    }
}
#endif
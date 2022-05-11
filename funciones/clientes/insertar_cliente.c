#ifndef INSERTAR_CLIENTE_C
#define INSERTAR_CLIENTE_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
void insertar_cliente(cliente **nv, cliente **ini_cliente){
    cliente *aux = *ini_cliente;
    if(*ini_cliente != NULL){
        while(aux->sgte != NULL){
            aux = aux->sgte;
        }
        aux->sgte = *nv;
        *nv = NULL;
    }else{
        *ini_cliente = *nv;
        *nv = NULL;
	}
    
}
#endif

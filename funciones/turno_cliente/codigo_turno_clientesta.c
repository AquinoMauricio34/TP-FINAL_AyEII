#ifndef insertar_codigo_cliente_C
#define insertar_codigo_cliente_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
void insertar_codigo_cliente(turno_cliente **nv,turno_cliente **ini_clientesta){
	turno_cliente *aux = *ini_clientesta;
	if(*ini_clientesta == NULL){
		(*nv)->cod_clientesta = 1;
	}else{
		while(aux->sgte != NULL){
			aux = aux->sgte;
		}
		(*nv)->cod_clientesta = aux->cod_clientesta+1;
	}
}
#endif
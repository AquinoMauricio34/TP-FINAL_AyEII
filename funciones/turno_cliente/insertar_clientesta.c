#ifndef INSERTAR_CLIENTESTA_C
#define INSERTAR_CLIENTESTA_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
void insertar_clientesta(turno_cliente **nv,turno_cliente **ini_clientesta){
     turno_cliente *aux = *ini_clientesta;
     if(*ini_clientesta != NULL){
          while(aux->sgte!= NULL){
               aux = aux->sgte;
          }
          aux->sgte = *nv;
          *nv = NULL;
     }else{
          *ini_clientesta = *nv;
          *nv = NULL;
     }
}
#endif


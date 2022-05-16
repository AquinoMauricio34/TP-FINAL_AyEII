#ifndef BORRAR_TCLIENTE_C
#define BORRAR_TCLIENTE_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
/*
tene en cuenta que al momento de borrar los nodos, puede que uno de los nodos a borrar
sea el que es apuntado por el inicio de la lista, cuidado de no borrarlo
y perder el inicio de la lista
*/
encontrado = 0;
/*do{
	encontrado = borrar_Tcliente();
}while(encontrado == 1);
//hasta aquí*/


//aqui se encuentran las funciones que se de deben agregar

int borrar_Tcliente(int dato,turno_cliente **ini_tcliente){
    turno_cliente *bor=*ini_tcliente,*ant=NULL;
    buscar_borrar_Tcliete(dato,bor,ant);
    if(bor != NULL){
		encontrado = 1;
        if(ant != NULL){
           *ini_tcliente = (*ini_tcliente)->sgte;
        }else{
            ant->sgte = bor->sgte;
        }
        bor->sgte = NULL;
        free(bor);
    }else
        printf("no existe el dato no esta en la lista\n");
		
	return encontrado;
}


void buscar_borrar_profeso(long int dato,turno_cliente **bor,turno_cliente **ant){
    *ant = NULL;
    int encontrado=0;
    while(*bor != NULL && encontrado != 0){
        if(dato == (*bor)->dni){
            encontrado = 1;
        }else{
            *ant = *bor;
            *bor = (*bor)->sgte;
        }
    }
}
#endif






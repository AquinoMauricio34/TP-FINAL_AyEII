#ifndef BORRAR_NODO_RESERVA_C
#define BORRAR_NODO_RESERVA_C

#include<stdio.h>
#include<stdlib.h>
#include"../../estructuras.h"
#include"../../prototipos.h"

// void desencolar(reserva **nv,reserva **S, reserva **E){
//     *nv = *S;
//     *S = (*S)->sgte;
//     if(*S==NULL){
//         *E = NULL;
//     }
// }


void borrar_nodo_reserva(long int dni_borrar, reserva **ini){
	reserva *bor,*ant,*aux;
	int proceder = 0;
	bor = *ini;
	buscar_borrar_reserva(dni_borrar,&bor,&ant,&proceder);
	if(bor != NULL){
		if(ant==NULL){
			*ini = (*ini)->sgte;
			(*ini)->ant = NULL;
			bor->sgte = NULL;
		}else{
			ant->sgte = bor->sgte;
			if(bor->sgte != NULL){
				aux = bor->sgte;
				aux->ant = ant;
				bor->sgte = NULL;
			}
			bor->ant = NULL;
		}
	}
	free(bor);
	free(aux);
	free(ant);
}	

void buscar_borrar_reserva(long int dni_borrar,reserva **rc,reserva **ant,int *proceder){
	*proceder = 0;
	
	*ant = NULL;
	while(rc!=NULL && *proceder == 0){
		if((*rc)->dni == dni_borrar){
			*proceder = 1;
		}else{
			*ant = *rc;
			*rc = (*rc)->sgte;
		}
	}
}

#endif
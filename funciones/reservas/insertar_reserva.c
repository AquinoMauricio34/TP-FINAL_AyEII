#ifndef INSERTAR_RESERVA_C
#define INSERTAR_RESERVA_C

#include<stdio.h>
#include<stdlib.h>
#include"../../estructuras.h"
#include"../../prototipos.h"

// void encolar(reserva **nv,reserva **S, reserva **E){
//     if(*E == NULL){
//         *S = *nv;
//     }else{
//         (*E)->sgte = *nv;
//     }
//     *E = *nv;
//     *nv = NULL;
// }


void insertar_reserva(reserva **nv,reserva **ini_reserva){
    reserva *aux=*ini_reserva;
    if(*ini_reserva != NULL){
        while(aux->sgte != NULL){
            aux = aux->sgte;
        }
        aux->sgte = *nv;
        (*nv)->ant = aux;
        *nv = NULL;
    }else{
        *ini_reserva = *nv;
        *nv = NULL;
    }
}

#endif
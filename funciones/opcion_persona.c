#ifndef OPCION_PERSONA_C
#define OPCION_PERSONA_C

#include<stdio.h>
#include<stdlib.h>
#include"../prototipos.h"

void opcion_persona(int *persona){
    do{
        printf("1. Administrador\n");
        printf("2. Operario\n>> ");scanf("%d",persona);
    }while(*persona < 1 || *persona > 2);
}

#endif
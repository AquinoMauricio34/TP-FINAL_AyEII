#ifndef listar_reservas_C
#define listar_reservas_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../prototipos.h"

int numero_aleatorio(int minimo, int maximo){
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

#endif
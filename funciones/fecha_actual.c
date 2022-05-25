#ifndef FECHA_ACTUAL_C
#define FECHA_ACTUAL_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"../estructuras.h"
#include"../prototipos.h"

fecha fecha_global;
hora hora_global;
int dia_sem_actual,fecha_modificada;
extern int fecha_modificada;

void fecha_actual(){
    time_t t;
	struct tm *fecha;
	
	// while(1){
		t = time(NULL);
		fecha = localtime(&t);
        
        if(fecha_modificada == 0){
            fecha_global.dd = fecha->tm_mday;
            fecha_global.mm = fecha->tm_mon + 1;
            fecha_global.yy = fecha->tm_year + 1900;
            dia_sem_actual = fecha->tm_wday;
        }else{
            fecha->tm_mday = fecha_global.dd;
            fecha->tm_mon = fecha_global.mm-1;
            fecha->tm_year = fecha_global.yy-1900;
            printf("\naaa\n");
            mktime(fecha);
            dia_sem_actual = fecha->tm_wday;

        }

        hora_global.hh = fecha->tm_hour;
        hora_global.mm = fecha->tm_min;
	// }

}

void modificar_fecha(){
    int op;
    do{
        printf("1. Fecha actual\n");
        printf("2. Fecha modificada\n>> ");scanf("%d",&op);
    }while(op<1 || op>2);

    if(op == 1)
        fecha_modificada = 0;
    else if(op == 2){
        fecha_modificada = 1;
        printf("Ingresar fecha con formato (dd/mm/yy): ");scanf("%d/%d/%d",&fecha_global.dd,&fecha_global.mm,&fecha_global.yy);
    }


}


#endif
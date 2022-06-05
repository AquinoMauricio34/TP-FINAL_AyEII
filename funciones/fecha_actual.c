//derificar que la fecha y hora sea real
#ifndef FECHA_ACTUAL_C
#define FECHA_ACTUAL_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../estructuras.h"
#include "../prototipos.h"

fecha fecha_global;
hora hora_global;
int dia_sem_actual,fecha_modificada,hora_modificada;

void fecha_actual(){
    time_t t;
	struct tm *fecha;
	
		t = time(NULL);
		fecha = localtime(&t);
        
        if(fecha_modificada == 0){
            fecha_global.dd = fecha->tm_mday;
            fecha_global.mm = fecha->tm_mon + 1;
            fecha_global.yy = fecha->tm_year + 1900;
            dia_sem_actual = fecha->tm_wday;
        }else if(fecha_modificada == 1){
            fecha->tm_mday = fecha_global.dd;
            fecha->tm_mon = fecha_global.mm-1;
            fecha->tm_year = fecha_global.yy-1900;
            mktime(fecha);
            dia_sem_actual = fecha->tm_wday;

        }

        if(hora_modificada == 0){
            hora_global.hh = fecha->tm_hour;
            hora_global.mm = fecha->tm_min;
        }
	// }

}

void modificar_fecha(){
    int op;
    int dd,mm,yy,hh,min;
    do{
        printf("1. Fecha actual\n");
        printf("2. Fecha modificada\n");
        printf("3. Hora actual\n");
        printf("4. Hora modificada\n");
        printf("0. Atras\n>> ");scanf("%d",&op);
    }while(op<0 || op>4);

    if(op == 1){
        fecha_modificada = 0;
    }
    else if(op == 2){
        do{
            printf("Ingresar fecha con formato (dd/mm/yy): ");scanf("%d/%d/%d",&dd,&mm,&yy);
        }while((dd<0 || dd>31) || (mm<0 || mm>12) || (yy<0));
        if(dd != 0 && mm != 0 && yy != 0){
            fecha_modificada = 1;
            fecha_global.dd = dd;
            fecha_global.mm = mm;
            fecha_global.yy = yy;
        }
    }else if(op == 3){
        hora_modificada = 0;
    }else if(op == 4){


        do{
            printf("Ingresar la hora con formato (hh:mm): ");scanf("%d:%d",&hh,&min);
        }while((hh<(-1) || hh>23) || (min<(-1) || min>59));
        if(hh != -1 && min != -1){
            hora_modificada = 1;
            hora_global.hh = hh;
            hora_global.mm = min;
        }
    }


}


#endif

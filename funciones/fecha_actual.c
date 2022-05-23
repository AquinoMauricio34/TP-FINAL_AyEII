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
int dia_sem_actual;

void fecha_actual(){
    time_t t;
	struct tm *fecha;
	
	// while(1){
		t = time(NULL);
		fecha = localtime(&t);

        fecha_global.dd = fecha->tm_mday;
        fecha_global.mm = fecha->tm_mon + 1;
        fecha_global.yy = fecha->tm_year + 1900;
        dia_sem_actual = fecha->tm_wday;
        hora_global.hh = fecha->tm_hour;
        hora_global.mm = fecha->tm_min;
	// }

}



#endif
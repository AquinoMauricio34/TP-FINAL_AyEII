#ifndef listar_reservas_C
#define listar_reservas_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"

void listar_reservas(reserva *ini){
	while(ini != NULL){
		printf("%-10ld| %30s| %10ld| %d/%d/%d\n",ini->dni,ini->nombre,ini->telefono,ini->f_nacimiento.dd,ini->f_nacimiento.mm,ini->f_nacimiento.yy);
		ini = ini->sgte;
	}
}

/*
long int dni,telefono;
	fecha f_nacimiento;
	char nombre[100];
*/
#endif
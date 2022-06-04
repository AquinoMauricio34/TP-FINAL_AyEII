#ifndef GUARDADO_LISTAS_C
#define GUARDADO_LISTAS_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"

void guardado_listas(actividad *ini_actividad,tipo_turno *ini_tipo_turno,cliente *ini_cliente,profesor *ini_profesor,cuenta *ini_cuenta,reserva *ini_reserva,turno_cliente *ini_turno_cliente){
    guardado_actividad(ini_actividad);
	guardado_tipo_turno(ini_tipo_turno);
	guardado_cliente(ini_cliente);
	guardado_profesor(ini_profesor);
	guardado_cuenta(ini_cuenta);
	guardado_reserva(ini_reserva);
	guardado_turno_cliente(ini_turno_cliente);
}

void guardado_turno_cliente(turno_cliente *ini_turno_cliente){
	FILE *a_turnos_cliente;
	if((a_turnos_cliente=fopen("turnos_cliente.dat","wb"))!=NULL){
		turno_cliente c_turno_cliente;
		turno_cliente *aux = ini_turno_cliente;
		while(aux != NULL){
			// printf("aux %s | %d | %d\n",aux->nombre,aux->cant_personas,aux->sede);
			fwrite(aux,sizeof(turno_cliente),1,a_turnos_cliente);
			aux = aux->sgte;
		}

		fclose(a_turnos_cliente);
	}else{
		printf("El archivo no se pudo abrir.");
	}
}

void guardado_reserva(reserva *ini_reserva){
	FILE *a_reservas;
	if((a_reservas=fopen("reservas.dat","wb"))!=NULL){
		reserva c_reserva;
		reserva *aux = ini_reserva;
		while(aux != NULL){
			// printf("aux %s | %d | %d\n",aux->nombre,aux->cant_personas,aux->sede);
			fwrite(aux,sizeof(reserva),1,a_reservas);
			aux = aux->sgte;
		}

		fclose(a_reservas);
	}else{
		printf("El archivo no se pudo abrir.");
	}
}

void guardado_cuenta(cuenta *ini_cuenta){
	FILE *a_cuentas;
	if((a_cuentas=fopen("cuentas.dat","wb"))!=NULL){
		cuenta c_cuenta;
		cuenta *aux = ini_cuenta;
		while(aux != NULL){
			// printf("aux %s | %d | %d\n",aux->nombre,aux->cant_personas,aux->sede);
			fwrite(aux,sizeof(cuenta),1,a_cuentas);
			aux = aux->sgte;
		}

		fclose(a_cuentas);
	}else{
		printf("El archivo no se pudo abrir.");
	}
}

void guardado_actividad(actividad *ini_actividad){
	FILE *a_actividades;
	if((a_actividades=fopen("actividades.dat","wb"))!=NULL){
		actividad c_actividad;
		actividad *aux = ini_actividad;
		while(aux != NULL){
			// printf("aux %s | %d | %d\n",aux->nombre,aux->cant_personas,aux->sede);
			fwrite(aux,sizeof(actividad),1,a_actividades);
			aux = aux->sgte;
		}

		fclose(a_actividades);
	}else{
		printf("El archivo no se pudo abrir.");
	}
}

void guardado_tipo_turno(tipo_turno *ini_tipo_turno){
	FILE *a_tipo_turnos;
	if((a_tipo_turnos=fopen("tipo_turnos.dat","wb"))!=NULL){
		tipo_turno c_tipo_turno;
		tipo_turno *aux = ini_tipo_turno;
		while(aux != NULL){
			// printf("aux %s | %d | %d\n",aux->nombre,aux->cant_personas,aux->sede);
			fwrite(aux,sizeof(tipo_turno),1,a_tipo_turnos);
			aux = aux->sgte;
		}

		fclose(a_tipo_turnos);
	}else{
		printf("El archivo no se pudo abrir.");
	}
}


void guardado_cliente(cliente *ini_cliente){
	FILE *a_clientes;
	if((a_clientes=fopen("clientes.dat","wb"))!=NULL){
		cliente c_cliente;
		cliente *aux = ini_cliente;
		while(aux != NULL){
			// printf("aux %s | %d | %d\n",aux->nombre,aux->cant_personas,aux->sede);
			fwrite(aux,sizeof(cliente),1,a_clientes);
			aux = aux->sgte;
		}

		fclose(a_clientes);
	}else{
		printf("El archivo no se pudo abrir.");
	}
}


void guardado_profesor(profesor *ini_profesor){
	FILE *a_profesores;
	if((a_profesores=fopen("profesores.dat","wb"))!=NULL){
		profesor c_profesor;
		profesor *aux = ini_profesor;
		while(aux != NULL){
			// printf("aux %s | %d | %d\n",aux->nombre,aux->cant_personas,aux->sede);
			fwrite(aux,sizeof(profesor),1,a_profesores);
			aux = aux->sgte;
		}

		fclose(a_profesores);
	}else{
		printf("El archivo no se pudo abrir.");
	}
}

#endif
#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H

#include"estructuras.h"

void insertar_reserva(reserva **nv,reserva **ini_reserva);
void borrar_nodo_reserva(long int dni_borrar, reserva **ini);
void buscar_borrar_reserva(long int dni_borrar,reserva **rc,reserva **ant,int *proceder);
int buscar_dni_reserva(long int dni,reserva *ini_reserva);
void listar_reservas(reserva *ini);

void insertar_profesor(profesor **nv, profesor **ini_profesor);
int buscar_dni_profesor(long int dni,profesor *ini_profesor);
void ABM_profesores(profesor **ini_profesor,actividad *ini_actividad);
void borrar_nodo_profesor(int dato,profesor **ini_profesor);
int buscar_actividades(int codigo,actividad *ini_actividad);
void buscar_borrar_profesor(long int dato,profesor **bor,profesor **ant);
void insertar_profesor(profesor **nv, profesor **ini_profesor);
void listar_actividades(actividad *ini);
void modificar_profesor(long int dato,int op,profesor **ini_profesor,actividad *ini_actividad);
// clientes
void ABM_clientes(cliente **ini_cliente,actividad **ini_actividad);
int buscar_dni_cliente(long int dni,cliente *ini_cliente);
void insertar_cliente(cliente **nv, cliente **ini_cliente);
void modificar_cliente(long int dato,int op,cliente **ini_cliente);
void borrar_nodo_cliente(int dato,cliente **ini_cliente);
int borrar_Tcliente(int dato,turno_cliente **ini_tcliente);
int buscar_actividades(int codigo,actividad *ini_actividad);

// actividades
void ABM_actividades(actividad **ini_actividad,tipo_turno **ini_turno_cliente);
void modificar_actividad(long int dato,int op,actividad **ini_actividad);
void insertar_actividad(actividad **nv, actividad **ini_actividad);
int buscar_actividad(int codigo,actividad *ini_actividad);
void borrar_nodo_actividad(int dato,actividad **ini_actividad);

//turno_clientes
void abm_clientes_ta(turno_cliente **ini_clientesta,tipo_turno **ini_turno,actividad *ini_actividad);
void borrar_nodo_clientest(long int buscar_borrar,turno_cliente **ini_clientest);
int buscar_actividades(int cod_act,int sede,actividad *ini_actividad);
void buscar_borrar_clientest(long int dato,turno_cliente **bor,turno_cliente **ant);
int buscar_dni_clientesta(long int dni,turno_cliente *ini_clientesta);
int buscar_turno_clientesta(int turno,tipo_turno *ini_turno);
void insertar_clientesta(turno_cliente **nv,turno_cliente **ini_clientesta);
int buscar_dni_clientest(long int dni,turno_cliente *ini_clientesta,tipo_turno *ini_turno,actividad *ini_actividad);
void recorrer_actividades(int sede,actividad *ini);
void recorrer_turnos(int cod_act,tipo_turno *ini_turno);
int borrar_Tcliente(int dato,turno_cliente **ini_tcliente);
void buscar_borrar_profeso(long int dato,turno_cliente **bor,turno_cliente **ant);

int numero_aleatorio(int minimo, int maximo);
#endif
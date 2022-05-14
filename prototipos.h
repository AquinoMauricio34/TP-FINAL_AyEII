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

int numero_aleatorio(int minimo, int maximo);
#endif
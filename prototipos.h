#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H

#include"estructuras.h"

void ABM_reservas(reserva **ini_reserva,actividad *ini_actividad, tipo_turno *ini_tipo_turno);
void insertar_reserva(reserva **nv,reserva **ini_reserva);
void borrar_nodo_reserva(long int dni_borrar, reserva **ini);
void buscar_borrar_reserva(long int dni_borrar,reserva **rc,reserva **ant,int *proceder);
int buscar_dni_reserva(long int dni,reserva *ini_reserva);
void listar_reservas(reserva *ini);
void listar_actividades_sede(actividad *ini_actividad,int eleccion_sede);
int buscar_actividad_sede(int eleccion_actividad,int eleccion_sede,actividad *ini_actividad);
void listar_tipo_turno(tipo_turno *ini_tipo_turno,int eleccion_actividad);
int buscar_tipo_turno_actividad(int eleccion_tipo_turno,int eleccion_actividad,tipo_turno *ini_tipo_turno);

//tipo_turno
void ABM_tipo_turno(tipo_turno **ini_tipo_turno,actividad *ini_actividad);
void listar_actividades_sede(actividad *ini_actividad,int eleccion_sede);
int buscar_actividad_sede(int eleccion_actividad,int eleccion_sede,actividad *ini_actividad);
void borrar_nodo_tipo_turno(long int tipo_turno_borrar, tipo_turno **ini);
void buscar_borrar_tipo_turno(long int tipo_turno_borrar,tipo_turno **rc,tipo_turno **ant);
int buscar_codigo_turno(int codigo_turno,tipo_turno *ini_tipo_turno);
void insertar_tipo_turno(tipo_turno **nv,tipo_turno **ini_tipo_turno);
void listar_all_tipo_turnos(tipo_turno *ini);
void modificar_tipo_turno(long int dato,int op,reserva **ini_tipo_turno);


//profesor

void insertar_profesor(profesor **nv, profesor **ini_profesor);
int buscar_dni_profesor(long int dni,profesor *ini_profesor);
void ABM_profesores(profesor **ini_profesor);
void borrar_nodo_profesor(int dato,profesor **ini_profesor);
int buscar_actividades_profesores(int codigo,actividad *ini_actividad);
void buscar_borrar_profesor(long int dato,profesor **bor,profesor **ant);
void insertar_profesor(profesor **nv, profesor **ini_profesor);
void listar_actividades(actividad *ini);
void modificar_profesor(long int dato,int op,profesor **ini_profesor);
void listar_all_profesores(profesor *ini);
// clientes
void ABM_clientes(cliente **ini_cliente,actividad *ini_actividad,tipo_turno **ini_turno_cliente);
int buscar_dni_cliente(long int dni,cliente *ini_cliente);
void insertar_cliente(cliente **nv, cliente **ini_cliente);
void modificar_cliente(long int dato,int op,cliente **ini_cliente);
void borrar_nodo_cliente(int dato,cliente **ini_cliente);
int borrar_Tcliente(int dato,turno_cliente **ini_tcliente,int *encontrado);
int buscar_actividades_clientes(int codigo,actividad *ini_actividad);
void buscar_borrar_Tcliete(long int dato,turno_cliente **bor,turno_cliente **ant);
void listar_all_clientes(cliente *ini);

// actividades
void ABM_actividades(actividad **ini_actividad,tipo_turno **ini_turno_cliente);
void modificar_actividad(long int dato,int op,actividad **ini_actividad);
void insertar_actividad(actividad **nv, actividad **ini_actividad);
int buscar_actividadx(int codigo,actividad *ini_actividad);
void borrar_nodo_actividad(int dato,actividad **ini_actividad);
void listar_all_actividades(actividad *ini);
void buscar_borrar_actividad(int dato,actividad **bor,actividad **ant);

//turno_clientes
void abm_clientes_ta(turno_cliente **ini_clientesta,tipo_turno **ini_turno,actividad *ini_actividad,cliente *ini_cliente,cuenta **ini_cuenta);
void insertar_codigo_cliente(turno_cliente **nv,turno_cliente **ini_clientesta);
void borrar_nodo_clientest(int buscar_borrar,turno_cliente **ini_clientest);
int buscar_actividades_clientesta(int cod_act,int sede,actividad *ini_actividad);
void buscar_borrar_clientest(long int dato,turno_cliente **bor,turno_cliente **ant);
int buscar_dni_clientesta(long int dni,turno_cliente *ini_clientesta);
void insertar_clientesta(turno_cliente **nv,turno_cliente **ini_clientesta);
int buscar_dni_clientest(long int dni,turno_cliente *ini_clientesta,tipo_turno *ini_turno,actividad *ini_actividad);
void recorrer_actividades(int sede,actividad *ini);
void recorrer_turnos(int cod_act,tipo_turno *ini_turno);
int buscar_turno(int turno,int cod_actividad,tipo_turno *ini_turno);
void listar_all_turnos_clientes(turno_cliente *ini);
// int borrar_Tcliente(int dato,turno_cliente **ini_tcliente);
void listar_turnos_cliente(long int dni_cliente,turno_cliente *ini);
int buscar_turno_cliente(int eleccion_turno_cliente,long int dni_cliente,turno_cliente *ini_clientesta);
int buscar_dni_turno_cliente(long int dni,turno_cliente *ini_turno_cliente);

//cuentas

void insertar_cuenta(cuenta **nv,cuenta **ini_cuenta);


int numero_aleatorio(int minimo, int maximo);
void fecha_actual();

// carga de listas
void cargar_listas(actividad **ini_actividad,tipo_turno **ini_tipo_turno,cliente **ini_cliente);
void carga_actividades(actividad **ini_actividad);
void insertar_actividad_carga(actividad **nv,actividad **ini);
void carga_tipo_turnos(tipo_turno **ini_tipo_turno);
void insertar_tipo_turno_carga(tipo_turno **nv,tipo_turno **ini);
void carga_clientes(cliente **ini_cliente);
void insertar_cliente_carga(cliente **nv,cliente **ini);

// guardado de listas
void guardado_listas(actividad *ini_actividad,tipo_turno *ini_tipo_turno,cliente *ini_cliente);
void guardado_actividad(actividad *ini_actividad);
void guardado_tipo_turno(tipo_turno *ini_tipo_turno);
void guardado_cliente(cliente *ini_cliente);
#endif
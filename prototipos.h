#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H

#include"estructuras.h"

//listas
void listar_sede_actividades(actividad *ini_actividad,turno_cliente *ini_turno);

void ABM_reservas(reserva **ini_reserva,actividad *ini_actividad, tipo_turno *ini_tipo_turno,turno_cliente **ini_turno_cliente,cuenta **ini_cuenta,cliente *ini_cliente);
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
void ABM_profesores(profesor **ini_profesor,actividad *ini_actividad);
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
int buscar_dni_cliente_2(long int dni,cliente **ini_cliente,turno_cliente *ini_turno_cliente);
void insertar_cliente(cliente **nv, cliente **ini_cliente);
void modificar_cliente(long int dato,int op,cliente **ini_cliente);
void borrar_nodo_cliente(int dato,cliente **ini_cliente);
int borrar_Tcliente(int dato,turno_cliente **ini_tcliente,int *encontrado);
int buscar_actividades_clientes(int codigo,actividad *ini_actividad);
void buscar_borrar_Tcliete(long int dato,turno_cliente **bor,turno_cliente **ant);
void listar_all_clientes(cliente *ini);
void baja_nodo_cliente(long int buscar_borrar,cliente **ini_cliente);
void baja_turnos_cliente(long int buscar_borrar,turno_cliente **ini_turno_cliente);

// actividades
void ABM_actividades(actividad **ini_actividad,tipo_turno **ini_turno_cliente,profesor *ini_profesor);
void modificar_actividad(long int dato,int op,actividad **ini_actividad);
void insertar_actividad(actividad **nv, actividad **ini_actividad);
int buscar_actividadx(int codigo,actividad *ini_actividad);
void borrar_nodo_actividad(int dato,actividad **ini_actividad);
void listar_all_actividades(actividad *ini);
void buscar_borrar_actividad(int dato,actividad **bor,actividad **ant);
void baja_actividad_estado(actividad **ini_actividad,tipo_turno **ini_tipo_turno,turno_cliente **ini_turno_cliente);
void baja_tipo_turnos_actividad(int codigo_actividad,tipo_turno **ini_tipo_turno,turno_cliente **ini_turno_cliente);
void baja_turnos_cliente_seguntturno(int codigo_tt,turno_cliente **ini_turno_cliente);

//turno_clientes
void abm_clientes_ta(turno_cliente **ini_clientesta,tipo_turno **ini_turno,actividad *ini_actividad,cliente *ini_cliente,cuenta **ini_cuenta);
void insertar_codigo_cliente(turno_cliente **nv,turno_cliente **ini_clientesta);
void borrar_nodo_clientest(int buscar_borrar,turno_cliente **ini_clientest);
int buscar_actividades_clientesta(int cod_act,int sede,actividad *ini_actividad,turno_cliente *ini_turno_cliente);
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
int buscar_dni_clientesta_turno_repetido(long int dni,int codigo_turno,turno_cliente *ini_clientesta);
void baja_tipo_turno_estado(tipo_turno **ini_tipo_turno,turno_cliente **ini_turno_cliente);

//cuentas
int buscar_dni_turno_cliente_cuenta(long int dni,turno_cliente *ini_turno_cliente);
void insertar_cuenta(cuenta **nv,cuenta **ini_cuenta);
void listar_turnos_cliente_segunactividad(long int dni_cliente,int eleccion_actividad,turno_cliente *ini);
int buscar_turno_cliente_cuenta(int eleccion_turno_cliente,int eleccion_actividad,long int dni_cliente,turno_cliente **ini_turno_cliente);
void listar_all_cuentas(cuenta *ini);
void pago_cuenta(turno_cliente **ini_turno_cliente,actividad *ini_actividad,tipo_turno *ini_tipo_turno,cuenta **ini_cuenta);


int numero_aleatorio(int minimo, int maximo);
void baja_mes(cliente **ini_cliente,turno_cliente **ini_turno_cliente);
void fecha_actual();
void opcion_persona(int *persona);
void modificar_fecha();
void deudas(turno_cliente **ini_turno_cliente,tipo_turno *ini_tipo_turno,cuenta *ini_cuenta);
void asistencia(actividad *ini_actividad,turno_cliente **ini_turno_cliente,tipo_turno *ini_tipo_turno);

// carga de listas
void cargar_listas(actividad **ini_actividad,tipo_turno **ini_tipo_turno,cliente **ini_cliente,profesor **ini_profesor,turno_cliente **ini_turno_cliente,reserva **ini_reserva,cuenta **ini_cuenta);
void carga_actividades(actividad **ini_actividad);
void insertar_actividad_carga(actividad **nv,actividad **ini);
void carga_tipo_turnos(tipo_turno **ini_tipo_turno);
void insertar_tipo_turno_carga(tipo_turno **nv,tipo_turno **ini);
void carga_clientes(cliente **ini_cliente);
void insertar_cliente_carga(cliente **nv,cliente **ini);
void carga_profesores(profesor **ini_profesor);
void insertar_profesor_carga(profesor **nv,profesor **ini);
void carga_turnos_cliente(turno_cliente **ini_turno_cliente);
void insertar_turno_cliente_carga(turno_cliente **nv,turno_cliente **ini);
void carga_reservas(reserva **ini_reserva);
void insertar_reserva_carga(reserva **nv,reserva **ini);
void carga_cuentas(cuenta **ini_cuenta);
void insertar_cuenta_carga(cuenta **nv,cuenta **ini);

//arbol
void deudores_mayo(turno_cliente *ini_turno_cliente,cuenta *ini_cuenta,cliente *ini_cliente);
deudores * borrar_nodo(deudores *borrar);
deudores * vaciar_arbol(deudores *arbol);
void inorder(deudores *arbol);
deudores * insertar_deudor(deudores *arbol,deudores *nv);


// guardado de listas
void guardado_listas(actividad *ini_actividad,tipo_turno *ini_tipo_turno,cliente *ini_cliente,profesor *ini_profesor,cuenta *ini_cuenta,reserva *ini_reserva,turno_cliente *ini_turno_cliente);
void guardado_actividad(actividad *ini_actividad);
void guardado_tipo_turno(tipo_turno *ini_tipo_turno);
void guardado_cliente(cliente *ini_cliente);
void guardado_profesor(profesor *ini_profesor);
void guardado_turno_cliente(turno_cliente *ini_turno_cliente);
void guardado_reserva(reserva *ini_reserva);
void guardado_cuenta(cuenta *ini_cuenta);
// mostrar lista
void listar_sede_actividades_turno(actividad *ini_actividad,tipo_turno *ini_turno, turno_cliente *ini_turno_cliente);
void listar_reservas_actividad(actividad *ini_actividad,reserva *ini_reserva);
#endif
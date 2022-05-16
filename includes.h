#ifndef INCLUDES_H
#define INCLUDES_H


//reservas

#include"funciones/reservas/desencolar.c"
#include"funciones/reservas/encolar.c"
#include"funciones/reservas/vacio_reserva.c"
#include"funciones/reservas/ABM_reservas.c"
#include"funciones/reservas/buscar_dni_reserva.c"

// profesores


#include"funciones/profesores/insertar_profesor.c"
#include"funciones/profesores/ABM_profesores.c"
#include"funciones/profesores/borrar_nodo_profesor.c"
#include"funciones/profesores/buscar_actividad.c"
#include"funciones/profesores/buscar_borrar_profesor.c"
#include"funciones/profesores/buscar_dni_profesor.c"
#include"funciones/profesores/modificar_profesor.c"


#include"funciones/tipo_turnos/ABM_tipo_turno.c"

// clientes
#include"funciones/clientes/ABM_cliente.c"
#include"funciones/clientes/buscar_actividad.c"
#include"funciones/clientes/buscar_dni_cliente.c"
#include"funciones/clientes/modificar_cliente.c"
#include"funciones/clientes/buscar_nodo_cliente.c"


//turno_clientes
#include"funciones/turno_cliente/abm_clientesta.c"
#include"funciones/turno_cliente/borrar_nodo_clientest.c"
#include"funciones/turno_cliente/buscar_actividades_clientesta.c"
#include"funciones/turno_cliente/buscar_borrar_clientesta.c"
#include"funciones/turno_cliente/buscar_dni_clientesta.c"
#include"funciones/turno_cliente/buscar_turnos__clientes.c"
#include"funciones/turno_cliente/insertar_clientesta.c"
#include"funciones/turno_cliente/modificacion_clientesta.c"
#include"funciones/turno_cliente/recorrer_turnos.c"
#include"funciones/turno_cliente/listar_actividades.c"
#endif

#ifndef INCLUDES_H
#define INCLUDES_H


//reservas

// #include"funciones/reservas/borrar_nodo_reserva.c"
// #include"funciones/reservas/insertar_reserva.c"
#include"funciones/reservas/ABM_reservas.c"
// #include"funciones/reservas/buscar_dni_reserva.c"
// #include"funciones/reservas/listar_reservas.c"

#include"funciones/carga_listas.c"
#include"funciones/guardado_listas.c"



// profesores


#include"funciones/profesores/insertar_profesor.c"
#include"funciones/profesores/ABM_profesores.c"
#include"funciones/profesores/borrar_nodo_profesor.c"
#include"funciones/profesores/buscar_actividades.c"
#include"funciones/profesores/buscar_borrar_profesor.c"
#include"funciones/profesores/buscar_dni_profesor.c"
#include"funciones/profesores/modificar_profesor.c"
#include"funciones/profesores/listar_actividades.c"


#include"funciones/tipo_turnos/ABM_tipo_turno.c"

// clientes
#include"funciones/clientes/ABM_cliente.c"
#include"funciones/clientes/buscar_actividad.c"
#include"funciones/clientes/buscar_dni_cliente.c"
#include"funciones/clientes/buscar_dni_cliente_2.c"
#include"funciones/clientes/modificar_cliente.c"
#include"funciones/clientes/borrar_nodo_cliente.c"
#include"funciones/clientes/insertar_cliente.c"
#include"funciones/clientes/borrar_Tcliente.c"



//turno_clientes
#include"funciones/turno_cliente/abm_clientesta.c"
#include"funciones/turno_cliente/borrar_nodo_clientest.c"
#include"funciones/turno_cliente/buscar_actividades_clientesta.c"
#include"funciones/turno_cliente/buscar_borrar_clientesta.c"
#include"funciones/turno_cliente/buscar_dni_clientesta.c"
#include"funciones/turno_cliente/buscar_turnos_clientes.c"
#include"funciones/turno_cliente/insertar_clientesta.c"
#include"funciones/turno_cliente/modificacion_clientesta.c"
#include"funciones/turno_cliente/recorrer_actividades.c"
#include"funciones/turno_cliente/recorrer_turnos.c"
#include"funciones/turno_cliente/codigo_turno_clientesta.c"
// #include"funciones/turno_cliente/listar_actividades.c"

//actividades

#include"funciones/actividades/ABM_actividades.c"
#include"funciones/actividades/borrar_actividad.c"
#include"funciones/actividades/buscar_actividad.c"
#include"funciones/actividades/insertar_actividad.c"
#include"funciones/actividades/modificar_actividad.c"


//cuentas
#include"funciones/cuentas/pago_cuenta.c"


//sin categoría
#include"funciones/fecha_actual.c"
#include"funciones/opcion_persona.c"
#include"funciones/deudas.c"
#include"funciones/asistencia.c"
#include"funciones/deudores_mayo.c"


// mostrar lista
#include"funciones/listar_cliente_sd_act_tur/listar_csat.c"
#include"funciones/listar_clientes_sede_actvidad/listar_clientes.c"
#include"funciones/reservas/listar_reservas.c"

#endif


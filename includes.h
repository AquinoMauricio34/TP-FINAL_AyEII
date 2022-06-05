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


#include"funciones/profesores/ABM_profesores.c"


#include"funciones/tipo_turnos/ABM_tipo_turno.c"

// clientes
#include"funciones/clientes/ABM_cliente.c"



//turno_clientes
#include"funciones/turno_cliente/abm_clientesta.c"
// #include"funciones/turno_cliente/listar_actividades.c"

//actividades

#include"funciones/actividades/ABM_actividades.c"


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

#endif


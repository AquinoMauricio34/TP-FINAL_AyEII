#ifndef ESTRUCTURAS_C
#define ESTRUCTURAS_C

typedef struct{
	int dd,mm,yy;
}fecha;

typedef struct{
	int hh,mm,ss;
}hora;

typedef struct{
	long int dni,telefono;
	fecha f_nacimiento;
	char nombre[100];
	struct cliente *sgte;
}cliente;

typedef struct{
	int cod_clientesta;
	int mes,anio;
	float precio;
	fecha f_pago;
	struct cuenta *sgte;
}cuenta;

typedef struct{
	int cod_act;
	int cant_personas;
	int sede;
	int estado;//1(activa), 0(inactiva a activar), -1(inactiva a eliminar);
	char nombre[100];
	struct actividad *sgte;
}actividad;

typedef struct{
	int cod_act,cod_turno;
	float precio;
	int estado;//1(activa), 0(inactiva a activar), -1(inactiva a eliminar);
	hora hora_inicio_turno,hora_fin_turno;
	int dias[5];/*
	cada espacio en el vector representa un dia de la semana (de lunes a viernes). EL 0 represente no y el 1 representa si.
	EJ: para poner dias lun, mierc, vier seria dias[0]=1 (lunes si), dias[1]=0 (martes no), dias[2]=1 (miercoles si), dias[3]=0 (jueves no), dias[4]=1 (viernes si)
	*/
	struct tipo_turno *sgte;
}tipo_turno;

typedef struct{
	int cod_turno,cod_actividad,cod_clientesta;
	long int dni;
	fecha f_ultima_vez;
	struct turno_cliente *sgte;
}turno_cliente;

typedef struct{
	int cod_act;
	char nombre[100];
	long int dni,telefono;
	struct profesor *sgte;
}profesor;

typedef struct{
	int cod_act,cod_turno;
	long int dni,telefono;
	fecha f_nacimiento;
	char nombre[100];
	struct reserva *sgte;
	struct reserva *ant;
}reserva;

#endif
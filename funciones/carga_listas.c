#ifndef CARGAR_LISTAS_C
#define CARGAR_LISTAS_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"

void cargar_listas(actividad **ini_actividad,tipo_turno **ini_tipo_turno,cliente **ini_cliente,profesor **ini_profesor,turno_cliente **ini_turno_cliente,reserva **ini_reserva,cuenta **ini_cuenta){
    carga_actividades(&*ini_actividad);
    carga_tipo_turnos(&*ini_tipo_turno);
	carga_clientes(&*ini_cliente);
	carga_profesores(&*ini_profesor);
	//turno_cliente
	carga_turnos_cliente(&*ini_turno_cliente);
	//reservas
	carga_reservas(&*ini_reserva);
	//cuentas
	carga_cuentas(&*ini_cuenta);
}

void carga_turnos_cliente(turno_cliente **ini_turno_cliente){
	FILE *a_turnos_cliente;
	if((a_turnos_cliente=fopen("turnos_cliente.dat","rb"))!=NULL){
		
		turno_cliente c_turno_cliente;
		turno_cliente *nv=NULL;
		
		// printf("\n111\n");
		
		fread(&c_turno_cliente,sizeof(turno_cliente),1,a_turnos_cliente);
		// printf("\n111\n");
		while(!feof(a_turnos_cliente)){
			// printf("%s | %d | %d\n",c_turno_cliente.nombre,c_turno_cliente.cant_personas,c_turno_cliente.sede);
			// printf("\n222\n");
			nv = malloc(sizeof(turno_cliente));
			if(nv!=NULL){
				// printf("\n333\n");
				//carga datos
				nv->baja = c_turno_cliente.baja;
				nv->cod_act = c_turno_cliente.cod_act;
				nv->cod_clientesta = c_turno_cliente.cod_clientesta;
				nv->dni = c_turno_cliente.dni;
				nv->debe = c_turno_cliente.debe;
				nv->incrementado = c_turno_cliente.incrementado;
				nv->cod_turno = c_turno_cliente.cod_turno;
				nv->dni = c_turno_cliente.dni;
				nv->f_ultima_vez.dd = c_turno_cliente.f_ultima_vez.dd;
				nv->f_ultima_vez.mm = c_turno_cliente.f_ultima_vez.mm;
				nv->f_ultima_vez.yy = c_turno_cliente.f_ultima_vez.yy;
				nv->sgte = NULL;
				//insertar
				insertar_turno_cliente_carga(&nv,&*ini_turno_cliente);
			}
			
			
			fread(&c_turno_cliente,sizeof(turno_cliente),1,a_turnos_cliente);
		}
		fclose(a_turnos_cliente);
	}else{
		// printf("\naaaa111\n");
		if((a_turnos_cliente=fopen("turnos_cliente.dat","wb"))!=NULL){
			fclose(a_turnos_cliente);
		}
	}
}

void insertar_turno_cliente_carga(turno_cliente **nv,turno_cliente **ini){
	// (*nv)->sgte = *ini;
	// *ini = *nv;
	// *nv = NULL;
	turno_cliente *aux = *ini;
    if(*ini != NULL){
		while(aux->sgte!= NULL){
            aux = aux->sgte;
        }
        aux->sgte = *nv;
        *nv = NULL;
    }else{
        *ini = *nv;
        *nv = NULL;
    }
}



void carga_reservas(reserva **ini_reserva){
	FILE *a_reservas;
	if((a_reservas=fopen("reservas.dat","rb"))!=NULL){
		
		reserva c_reserva;
		reserva *nv=NULL;
		
		// printf("\n111\n");
		
		fread(&c_reserva,sizeof(reserva),1,a_reservas);
		// printf("\n111\n");
		while(!feof(a_reservas)){
			// printf("%s | %d | %d\n",c_reserva.nombre,c_reserva.cant_personas,c_reserva.sede);
			// printf("\n222\n");
			nv = malloc(sizeof(reserva));
			if(nv!=NULL){
				// printf("\n333\n");
				//carga datos
				nv->cod_act = c_reserva.cod_act;
				nv->cod_turno = c_reserva.cod_turno;
				nv->dni = c_reserva.dni;
				nv->telefono = c_reserva.telefono;
				nv->ant = NULL;
				nv->sgte = NULL;
				//insertar
				insertar_reserva_carga(&nv,&*ini_reserva);
			}
			
			
			fread(&c_reserva,sizeof(reserva),1,a_reservas);
		}
		fclose(a_reservas);
	}else{
		// printf("\naaaa111\n");
		if((a_reservas=fopen("reservas.dat","wb"))!=NULL){
			fclose(a_reservas);
		}
	}
}

void insertar_reserva_carga(reserva **nv,reserva **ini){
	// (*nv)->sgte = *ini;
	// *ini = *nv;
	// *nv = NULL;
	reserva *aux = *ini;
    if(*ini != NULL){
		while(aux->sgte!= NULL){
            aux = aux->sgte;
        }
        aux->sgte = *nv;
		(*nv)->ant = aux;
        *nv = NULL;
    }else{
        *ini = *nv;
        *nv = NULL;
    }
}




void carga_cuentas(cuenta **ini_cuenta){
	FILE *a_cuentas;
	if((a_cuentas=fopen("cuentas.dat","rb"))!=NULL){
		
		cuenta c_cuenta;
		cuenta *nv=NULL;
		
		// printf("\n111\n");
		
		fread(&c_cuenta,sizeof(cuenta),1,a_cuentas);
		// printf("\n111\n");
		while(!feof(a_cuentas)){
			// printf("%s | %d | %d\n",c_cuenta.nombre,c_cuenta.cant_personas,c_cuenta.sede);
			// printf("\n222\n");
			nv = malloc(sizeof(cuenta));
			if(nv!=NULL){
				// printf("\n333\n");
				//carga datos
				nv->cod_clientesta = c_cuenta.cod_clientesta;
				nv->precio = c_cuenta.precio;
				nv->f_pago.dd = c_cuenta.f_pago.dd;
				nv->f_pago.mm = c_cuenta.f_pago.mm;
				nv->f_pago.yy = c_cuenta.f_pago.yy;
				nv->sgte = NULL;
				//insertar
				insertar_cuenta_carga(&nv,&*ini_cuenta);
			}
			
			
			fread(&c_cuenta,sizeof(cuenta),1,a_cuentas);
		}
		fclose(a_cuentas);
	}else{
		// printf("\naaaa111\n");
		if((a_cuentas=fopen("cuentas.dat","wb"))!=NULL){
			fclose(a_cuentas);
		}
	}
}

void insertar_cuenta_carga(cuenta **nv,cuenta **ini){
	// (*nv)->sgte = *ini;
	// *ini = *nv;
	// *nv = NULL;
	cuenta *aux = *ini;
    if(*ini != NULL){
		while(aux->sgte!= NULL){
            aux = aux->sgte;
        }
        aux->sgte = *nv;
        *nv = NULL;
    }else{
        *ini = *nv;
        *nv = NULL;
    }
}










//esto no
void carga_actividades(actividad **ini_actividad){
	FILE *a_actividades;
	if((a_actividades=fopen("actividades.dat","rb"))!=NULL){
		
		actividad c_actividad;
		actividad *nv=NULL;
		
		// printf("\n111\n");
		
		fread(&c_actividad,sizeof(actividad),1,a_actividades);
		// printf("\n111\n");
		while(!feof(a_actividades)){
			// printf("%s | %d | %d\n",c_actividad.nombre,c_actividad.cant_personas,c_actividad.sede);
			// printf("\n222\n");
			nv = malloc(sizeof(actividad));
			if(nv!=NULL){
				// printf("\n333\n");
				//carga datos
				strcpy(nv->nombre,c_actividad.nombre);
				nv->cant_personas = c_actividad.cant_personas;
				nv->sede = c_actividad.sede;
                nv->cod_act = c_actividad.cod_act;
                nv->estado = c_actividad.estado;
				nv->dni_profesor = c_actividad.dni_profesor;
				nv->fecha_baja.dd = c_actividad.fecha_baja.dd;
				nv->fecha_baja.mm = c_actividad.fecha_baja.mm;
				nv->fecha_baja.yy = c_actividad.fecha_baja.yy;
				nv->sgte = NULL;
				//insertar
				insertar_actividad_carga(&nv,&*ini_actividad);
			}
			
			
			fread(&c_actividad,sizeof(actividad),1,a_actividades);
		}
		fclose(a_actividades);
	}else{
		// printf("\naaaa111\n");
		if((a_actividades=fopen("actividades.dat","wb"))!=NULL){
			fclose(a_actividades);
		}
	}
}

void insertar_actividad_carga(actividad **nv,actividad **ini){
	// (*nv)->sgte = *ini;
	// *ini = *nv;
	// *nv = NULL;
	actividad *aux = *ini;
    if(*ini != NULL){
		while(aux->sgte!= NULL){
            aux = aux->sgte;
        }
        aux->sgte = *nv;
        *nv = NULL;
    }else{
        *ini = *nv;
        *nv = NULL;
    }
}

















void carga_tipo_turnos(tipo_turno **ini_tipo_turno){
	FILE *a_tipo_turnos;
	if((a_tipo_turnos=fopen("tipo_turnos.dat","rb"))!=NULL){
		
		tipo_turno c_tipo_turno;
		tipo_turno *nv=NULL;
		
		// printf("\n111\n");
		
		fread(&c_tipo_turno,sizeof(tipo_turno),1,a_tipo_turnos);
		// printf("\n111\n");
		while(!feof(a_tipo_turnos)){
			// printf("%s | %d | %d\n",c_actividad.nombre,c_actividad.cant_personas,c_actividad.sede);
			// printf("\n222\n");
			nv = malloc(sizeof(tipo_turno));
			if(nv!=NULL){
				// printf("\n333\n");
				//carga datos
				nv->cod_act = c_tipo_turno.cod_act;
				nv->cod_turno = c_tipo_turno.cod_turno;
				nv->dias[0] = c_tipo_turno.dias[0];
				nv->dias[1] = c_tipo_turno.dias[1];
				nv->dias[2] = c_tipo_turno.dias[2];
				nv->dias[3] = c_tipo_turno.dias[3];
				nv->dias[4] = c_tipo_turno.dias[4];
				nv->estado = c_tipo_turno.estado;
				nv->hora_fin_turno.hh = c_tipo_turno.hora_fin_turno.hh;
				nv->hora_fin_turno.mm = c_tipo_turno.hora_fin_turno.mm;
				nv->hora_inicio_turno.hh = c_tipo_turno.hora_inicio_turno.hh;
				nv->hora_inicio_turno.mm = c_tipo_turno.hora_inicio_turno.mm;
				nv->precio = c_tipo_turno.precio;
				nv->fecha_baja.dd = c_tipo_turno.fecha_baja.dd;
				nv->fecha_baja.mm = c_tipo_turno.fecha_baja.mm;
				nv->fecha_baja.yy = c_tipo_turno.fecha_baja.yy;
				nv->sgte = NULL;
				//insertar
				insertar_tipo_turno_carga(&nv,&*ini_tipo_turno);
			}
			
			
			fread(&c_tipo_turno,sizeof(tipo_turno),1,a_tipo_turnos);
		}
		fclose(a_tipo_turnos);
	}else{
		// printf("\naaaa111\n");
		if((a_tipo_turnos=fopen("tipo_turnos.dat","wb"))!=NULL){
			fclose(a_tipo_turnos);
		}
	}
}

void insertar_tipo_turno_carga(tipo_turno **nv,tipo_turno **ini){
	// (*nv)->sgte = *ini;
	// *ini = *nv;
	// *nv = NULL;
	tipo_turno *aux = *ini;
    if(*ini != NULL){
		while(aux->sgte!= NULL){
            aux = aux->sgte;
        }
        aux->sgte = *nv;
        *nv = NULL;
    }else{
        *ini = *nv;
        *nv = NULL;
    }
}












void carga_clientes(cliente **ini_cliente){
	FILE *a_clientes;
	if((a_clientes=fopen("clientes.dat","rb"))!=NULL){
		
		cliente c_cliente;
		cliente *nv=NULL;
		
		// printf("\n111\n");
		
		fread(&c_cliente,sizeof(cliente),1,a_clientes);
		// printf("\n111\n");
		while(!feof(a_clientes)){
			// printf("%s | %d | %d\n",c_cliente.nombre,c_cliente.cant_personas,c_cliente.sede);
			// printf("\n222\n");
			nv = malloc(sizeof(cliente));
			if(nv!=NULL){
				// printf("\n333\n");
				//carga datos
				strcpy(nv->nombre,c_cliente.nombre);
				nv->dni = c_cliente.dni;
				nv->telefono = c_cliente.telefono;
				nv->baja = c_cliente.baja;
				nv->f_nacimiento.dd = c_cliente.f_nacimiento.dd;
				nv->f_nacimiento.mm = c_cliente.f_nacimiento.mm;
				nv->f_nacimiento.yy = c_cliente.f_nacimiento.yy;
				nv->sgte = NULL;
				//insertar
				insertar_cliente_carga(&nv,&*ini_cliente);
			}
			
			
			fread(&c_cliente,sizeof(cliente),1,a_clientes);
		}
		fclose(a_clientes);
	}else{
		// printf("\naaaa111\n");
		if((a_clientes=fopen("clientes.dat","wb"))!=NULL){
			fclose(a_clientes);
		}
	}
}

void insertar_cliente_carga(cliente **nv,cliente **ini){
	// (*nv)->sgte = *ini;
	// *ini = *nv;
	// *nv = NULL;
	cliente *aux = *ini;
    if(*ini != NULL){
		while(aux->sgte!= NULL){
            aux = aux->sgte;
        }
        aux->sgte = *nv;
        *nv = NULL;
    }else{
        *ini = *nv;
        *nv = NULL;
    }
}
















void carga_profesores(profesor **ini_profesor){
	FILE *a_profesores;
	if((a_profesores=fopen("profesores.dat","rb"))!=NULL){
		
		profesor c_profesor;
		profesor *nv=NULL;
		
		// printf("\n111\n");
		
		fread(&c_profesor,sizeof(profesor),1,a_profesores);
		// printf("\n111\n");
		while(!feof(a_profesores)){
			// printf("%s | %d | %d\n",c_profesor.nombre,c_profesor.cant_personas,c_profesor.sede);
			// printf("\n222\n");
			nv = malloc(sizeof(profesor));
			if(nv!=NULL){
				// printf("\n333\n");
				//carga datos
				nv->dni = c_profesor.dni;
				strcpy(nv->nombre,c_profesor.nombre);
				nv->telefono = c_profesor.telefono;
				nv->sgte = NULL;
				//insertar
				insertar_profesor_carga(&nv,&*ini_profesor);
			}
			
			
			fread(&c_profesor,sizeof(profesor),1,a_profesores);
		}
		fclose(a_profesores);
	}else{
		// printf("\naaaa111\n");
		if((a_profesores=fopen("profesores.dat","wb"))!=NULL){
			fclose(a_profesores);
		}
	}
}

void insertar_profesor_carga(profesor **nv,profesor **ini){
	// (*nv)->sgte = *ini;
	// *ini = *nv;
	// *nv = NULL;
	profesor *aux = *ini;
    if(*ini != NULL){
		while(aux->sgte!= NULL){
            aux = aux->sgte;
        }
        aux->sgte = *nv;
        *nv = NULL;
    }else{
        *ini = *nv;
        *nv = NULL;
    }
}


#endif
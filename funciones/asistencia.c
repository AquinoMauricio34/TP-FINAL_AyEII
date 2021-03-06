#ifndef ASISTENCIA_C
#define ASISTENCIA_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"

extern fecha fecha_global;
extern hora hora_global;
extern int dia_sem_actual;

void asistencia(actividad *ini_actividad,turno_cliente **ini_turno_cliente,tipo_turno *ini_tipo_turno){
    long int dni_cliente;
    int buscar,eleccion_sede,eleccion_actividad;
    int encontrado,verificado=0,sede_encontrada;
    turno_cliente *aux_turno_cliente=NULL;
    tipo_turno *aux_tipo_turno=NULL;
    do{
        printf("Ingresar sede 1 | 2 (0 para salir): ");//1
        scanf("%d",&eleccion_sede);
    }while(eleccion_sede < 0 || eleccion_sede >2);
    if(eleccion_sede != 0){
        do{
            printf("Ingresar dni: ");//111111
            scanf("%ld",&dni_cliente);
            buscar = buscar_dni_turno_cliente(dni_cliente,*ini_turno_cliente);
        }while(buscar != 1 && dni_cliente != 0);
        if(dni_cliente != 0){
            listar_actividades_sede(ini_actividad,eleccion_sede);
            do{
                printf("Ingresar codigo de la actividad: ");//13
                scanf("%d",&eleccion_actividad);
                buscar = buscar_actividad_sede(eleccion_actividad,eleccion_sede,ini_actividad);
            }while(buscar != 1 && eleccion_actividad!= 0);

            if(eleccion_actividad != 0){
                aux_turno_cliente = *ini_turno_cliente;
                while(aux_turno_cliente != NULL && verificado != 1){
                    if(aux_turno_cliente->baja != 1 && aux_turno_cliente->dni == dni_cliente && aux_turno_cliente->cod_act == eleccion_actividad && (aux_turno_cliente->debe == 0 || (aux_turno_cliente->debe != 0 && (fecha_global.dd>=1 && fecha_global.dd<= 10)))){
                        encontrado = 0;
                        aux_tipo_turno = ini_tipo_turno;
                        while(aux_tipo_turno != NULL && encontrado != 1){
                            if(aux_turno_cliente->cod_turno == aux_tipo_turno->cod_turno && aux_tipo_turno->estado != 0){
                                encontrado = 1;
                                if(aux_tipo_turno->dias[dia_sem_actual-1]==1){
                                    sede_encontrada = buscar_sede(eleccion_actividad,ini_actividad);
                                	if(((aux_tipo_turno->hora_inicio_turno.hh < hora_global.hh && (hora_global.hh < aux_tipo_turno->hora_fin_turno.hh || (hora_global.hh == aux_tipo_turno->hora_fin_turno.hh && hora_global.mm < aux_tipo_turno->hora_fin_turno.mm))) || (aux_tipo_turno->hora_inicio_turno.hh == hora_global.hh && hora_global.mm >= aux_tipo_turno->hora_inicio_turno.mm)) || sede_encontrada == -1){
                                        verificado = 1;
                                        system("cls");
                                        printf("VERIFICADO\n");
                                        system("pause");
                                    }

                                }
                            }
                            aux_tipo_turno = aux_tipo_turno->sgte;
                        }
                    }
                    if(verificado == 1){
                        aux_turno_cliente->f_ultima_vez.dd = fecha_global.dd;
                        aux_turno_cliente->f_ultima_vez.mm = fecha_global.mm;
                        aux_turno_cliente->f_ultima_vez.yy = fecha_global.yy;
                    }
                    aux_turno_cliente = aux_turno_cliente->sgte;
                }


            }
        }
    }

    if(verificado != 1){
        system("cls");
        printf("NO PUEDE ASISTIR\n");
        system("pause");
    }
}

int buscar_sede(int eleccion_actividad,actividad *ini_actividad){
    int sede_encontrada=0;
    while(ini_actividad != NULL){
        if(ini_actividad->cod_act == eleccion_actividad){
            sede_encontrada = ini_actividad->sede;
            ini_actividad = NULL;
        }else
            ini_actividad=ini_actividad->sgte;
    }
    return sede_encontrada;
}

#endif

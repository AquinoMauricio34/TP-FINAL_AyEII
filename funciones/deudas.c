#ifndef DEUDAS_C
#define DEUDAS_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"

extern fecha fecha_global;

void deudas(turno_cliente **ini_turno_cliente,tipo_turno *ini_tipo_turno,cuenta *ini_cuenta){
    turno_cliente *aux = *ini_turno_cliente;
    tipo_turno *aux_turno=NULL;
    cuenta *aux_cuenta=NULL;
    int cuenta_encontrada=0;
    printf("\nDEUDAS\n");
        printf("\n111\n");
        while(aux != NULL){
            printf("\n2\n");
            if(aux->baja == 0 && aux->debe>=0){
                printf("\n3\n");
                aux_cuenta = ini_cuenta;
                cuenta_encontrada = 0;
                while(aux_cuenta != NULL && cuenta_encontrada != 1){
                    printf("\n4\n");
                    if(aux_cuenta->cod_clientesta == aux->cod_clientesta && aux_cuenta->f_pago.mm == fecha_global.mm){
                        cuenta_encontrada = 1;
                        printf("\n5\n");
                    }
                    aux_cuenta = aux_cuenta->sgte;
                }
                if(cuenta_encontrada == 1){
                    aux->debe = 0.00;
                    printf("\n6\n");
                }else{
                    if(fecha_global.dd >= 1 && fecha_global.dd <= 10 && aux->debe == 0){
                        printf("\n7\n");
                        aux_turno = ini_tipo_turno;
                        while(aux_turno != NULL){
                            printf("\n8\n");
                            if(aux_turno->cod_turno == aux->cod_turno){
                                aux->debe = aux_turno->precio;
                                aux->incrementado = 0;
                                printf("\n9\n");
                            }
                            aux_turno = aux_turno->sgte;
                        }
                    }else if(fecha_global.dd >= 11 && aux->incrementado == 0){
                        printf("\n10\n");
                        aux_turno = ini_tipo_turno;
                        while(aux_turno != NULL){
                            printf("\n11\n");
                            if(aux_turno->cod_turno == aux->cod_turno){
                                printf("\n12 auxtprecio = %f\n",aux_turno->precio);
                                aux->debe =aux_turno->precio + (aux_turno->precio * 0.1);
                                printf("\n12 auxdebe = %f\n",aux->debe);
                                aux->incrementado = 1;
                            }
                            aux_turno = aux_turno->sgte;
                        }
                    }
                }
            }
            printf("\n13 auxdebe = %f\n",aux->debe);
            // break;
            aux = aux->sgte;
        }
    
    system("pause");
    printf("\n123412341234123412342134\n");
}




// void pago_deuda(turno_cliente **ini_turno_cliente,actividad *ini_actividad){
//     int buscar,eleccion_sede,eleccion_actividad;
//     long int dni_cliente;
//     //ingreso y verificacion de dni (se lo busca en turnos_cliente)
//     buscar = 0;
//     do{
//         printf("Ingresar dni del cliente: ");scanf("%ld",&dni_cliente);
//         buscar = buscar_dni_turno_cliente(dni_cliente,*ini_turno_cliente);
//     }while(buscar != 1 && dni_cliente != 0);

//     if(dni_cliente != 0){
//         do{
//             printf("Ingresar sede 1 | 2 : ");scanf("%d",&eleccion_sede);
//         }while(eleccion_sede < 1 || eleccion_sede > 2);
//         listar_actividades_sede(ini_actividad,eleccion_sede);

//         do{
//             printf("Ingresar codigo de la actividad: ");scanf("%d",&eleccion_actividad);
//             buscar = buscar_actividad_sede(eleccion_actividad,eleccion_sede,ini_actividad);
//         }while(buscar != 1 && eleccion_actividad != 0);



//     }
//     //listar, leer y verificar actividad
//     //listar , leer y verificar los tipo turnos
//     //Hacer pregunta, CONFIRMACION DE PAGO 1. SI | 2. NO
// }

#endif
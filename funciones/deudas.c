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
    // printf("\nDEUDAS\n");
        // printf("\n111\n");
        while(aux != NULL){
            // printf("\n2\n");
            if(aux->baja == 0 && aux->debe>=0){
                // printf("\n3\n");
                aux_cuenta = ini_cuenta;
                cuenta_encontrada = 0;
                while(aux_cuenta != NULL && cuenta_encontrada != 1){
                    // printf("\n4\n");
                    if(aux_cuenta->cod_clientesta == aux->cod_clientesta && aux_cuenta->f_pago.mm == fecha_global.mm && aux_cuenta->f_pago.yy && fecha_global.yy){
                        cuenta_encontrada = 1;
                        // printf("\n5\n");
                    }
                    aux_cuenta = aux_cuenta->sgte;
                }
                if(cuenta_encontrada == 1){
                    aux->debe = 0.00;
                    // printf("\n6\n");
                }else{
                    if(fecha_global.dd >= 1 && fecha_global.dd <= 10 && aux->debe == 0){
                        // printf("\n7\n");
                        aux_turno = ini_tipo_turno;
                        while(aux_turno != NULL){
                            // printf("\n8\n");
                            if(aux_turno->cod_turno == aux->cod_turno){
                                aux->debe = aux_turno->precio;
                                aux->incrementado = 0;
                                // printf("\n9\n");
                            }
                            aux_turno = aux_turno->sgte;
                        }
                    }else if(fecha_global.dd >= 11 && aux->incrementado == 0){
                        // printf("\n10\n");
                        aux_turno = ini_tipo_turno;
                        while(aux_turno != NULL){
                            // printf("\n11\n");
                            if(aux_turno->cod_turno == aux->cod_turno){
                                // printf("\n12 auxtprecio = %f\n",aux_turno->precio);
                                aux->debe =aux_turno->precio + (aux_turno->precio * 0.1);
                                // printf("\n12 auxdebe = %f\n",aux->debe);
                                aux->incrementado = 1;
                            }
                            aux_turno = aux_turno->sgte;
                        }
                    }
                }
            }
            // printf("\n13 auxdebe = %f\n",aux->debe);
            // break;
            aux = aux->sgte;
        }
    
    // system("pause");
    // printf("\n123412341234123412342134\n");
}

void baja_mes(cliente **ini_cliente,turno_cliente **ini_turno_cliente){
    int max_dd,max_mm,max_yy,tomar=0,mayor;
    turno_cliente *aux_turno_cliete;
    cliente *aux_cliente=*ini_cliente;
    while(aux_cliente != NULL){
        if(aux_cliente->baja == 0){
            aux_turno_cliete = *ini_turno_cliente;
            max_dd = max_mm = max_yy = 0;
            while(aux_turno_cliete != NULL){

                //toma de la ultima vez que asistió

                if(aux_turno_cliete->dni == aux_cliente->dni && aux_turno_cliete->baja == 0){
                    printf("\n---%d/%d/%d---\n",aux_turno_cliete->f_ultima_vez.dd,aux_turno_cliete->f_ultima_vez.mm,aux_turno_cliete->f_ultima_vez.yy);
                    tomar = 0;
                    if(aux_turno_cliete->f_ultima_vez.yy > max_yy){
                        tomar = 1;
                    }else if(aux_turno_cliete->f_ultima_vez.yy == max_yy && aux_turno_cliete->f_ultima_vez.mm > max_mm){
                        tomar = 1;
                    }else if(aux_turno_cliete->f_ultima_vez.yy == max_yy && aux_turno_cliete->f_ultima_vez.mm == max_mm && aux_turno_cliete->f_ultima_vez.dd > max_dd){
                        tomar = 1;
                    }

                    if(tomar == 1){
                        max_dd = aux_turno_cliete->f_ultima_vez.dd;
                        max_mm = aux_turno_cliete->f_ultima_vez.mm;
                        max_yy = aux_turno_cliete->f_ultima_vez.yy;
                    }
                //FIN toma de la ultima vez que asistió
                }
                aux_turno_cliete = aux_turno_cliete -> sgte;
            }

            printf("\nNombre: %s  -----%d/%d/%d-----\n",aux_cliente->nombre,max_dd,max_mm,max_yy);
            mayor = 0;
            if(max_dd != 0){
                if((max_yy < fecha_global.yy && max_mm != 12))
			        mayor = 1;
			    else if(max_yy+1 == fecha_global.yy && max_mm == 12){
					if(fecha_global.mm==1){
						if(max_dd<=fecha_global.dd)
							mayor = 1;
					}else
						mayor = 1;
					
				}else if(max_yy+1 < fecha_global.yy)
					mayor = 1;
				else if(fecha_global.yy == max_yy && max_mm+1 < fecha_global.mm)
			        mayor = 1;
			    else if(fecha_global.yy == max_yy && max_mm < fecha_global.mm && max_dd <= fecha_global.dd)
			        mayor = 1;
                
                if(mayor == 1){
                    aux_cliente->baja = 1;
                    baja_turnos_cliente(aux_cliente->dni,&*ini_turno_cliente);
                }

            }
        }
        aux_cliente=aux_cliente->sgte;
    }
            system("pause");
}

#endif
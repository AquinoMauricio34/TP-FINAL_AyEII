#ifndef BUSCAR_DNI_CLIENTESTA_C
#define BUSCAR_DNI_CLIENTESTA_C


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"
// int buscar_dni_clientest(long int dni,turno_cliente *ini_clientesta,tipo_turno *ini_turno,actividad *ini_actividad){
//     int sede,cod_act,buscara,buscart,busqueda=0;
// 	while(ini_clientesta != NULL){
// 		if(ini_clientesta->dni == dni){
// 			printf("ingrese la sede que desee 1-2\n");
// 					scanf("%d",&sede);
// 					//chequear si no existe el codigo
// 					do{//mientras se encuentre el dni ingresado o el dni es igual a 0, el bucle se repetira
// 						recorrer_actividades(sede,*ini_actividad);
// 						printf("ingrese el codigo de la actividad que desee\n");
//                    			scanf("%d",&cod_act);//codigo y sede 
// 						buscara = buscar_actividades_clientesta(cod_act,sede,*ini_actividad);
// 				}while(buscara!=1 && nv->cod_act !=0);//modifcar por un or
// 				if(buscara == 1){
// 					do{//mientra no se encuentre el turno ingresado o es igual a 0, el bucle se repetira
// 						recorrer_turnos(cod_act,*ini_turno);
// 						printf("ingrese el turno que desee\n");
// 						scanf("%d",&nv->cod_turno);
// 						buscart = buscar_turno_clientesta(nv->cod_turno,*ini_turno);
// 					}while(buscart!=1 && nv->cod_turno !=0);
// 						if(buscart == 1){
// 							*ini_clientesta->cod_turno = nv->cod_turno;
// 						}
// 				}
// 			}else
// 				ini_clientesta = ini_clientesta->sgte;		
// 	}
// 		if(busqueda == 0){
// 			printf("el dni ingresado no existe\n");
// 		}
// }
#endif
// #ifndef ABM_TIPO_TURNO_C
// #define ABM_TIPO_TURNO_C

// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// #include"../../estructuras.h"
// #include"../../prototipos.h"

// void ABM_tipo_turno(tipo_turno **ini_tipo_turno,actividad *ini_actividad){
//     int opcion,encontrado,buscar,op;
//     int codigo_turno;
//     int eleccion_sede,eleccion_actividad;
//     reserva *nv=NULL;
//     do{

//         do{
//             system("cls");
//             printf("1. Alta tipo_turno\n");
//             printf("2. Baja tipo_turno\n");
//             printf("3. Modificacion tipo_turno\n");
//             printf("0.Atras\n");
//             printf(">> ");scanf("%d",&opcion);
//         }while(opcion<0 || opcion>3);

//         //opcion 1
//         switch(opcion){
//             case 1:
//                 nv = malloc(sizeof(tipo_turno));
//                 if(nv != NULL){
//                     //generamos codigo aleatorio, comprobando que no exista pero no lo guardamos hasta el final de la carga de datos
//                     //mostrar y elegir actividad
//                     //cargamos es precio
//                     //cargamos hora inicio turno
//                     //cargamos hora fin turno
//                     //cargar dias
//                     //el estado será 1, pero solo para pruebas, luego lo arreglaremos
//                     //insertamos
//                 }

//             break;
//             case 2:
//                 buscar = 0;
//                 do{
//                     printf("Ingresar codigo del turno a eliminar: ");scanf("%ld",&codigo_turno);
//                     buscar = buscar_codigo_turno(codigo_turno,*ini_tipo_turno);
//                 }while(buscar != 1 && codigo_turno != 0);

//                 if(codigo_turno!=0){
//                     printf("Esta seguro/a de que quiere eliminar al cliente (1. SI | 0. NO): ");
//                     scanf("%d",&op);
//                     if(op == 1){
//                         borrar_nodo_tipo_turno(codigo_turno,&*ini_tipo_turno);
//                     }
//                 }
//             break;
//             case 3:
//                 // do{
//                 //     printf("Ingresar dni del cliente: ");scanf("%ld",&dni_cliente);
//                 //     buscar = buscar_dni_reserva(dni_cliente,*ini_reserva);
//                 // }while(buscar != 1 && dni_cliente != 0);

//                 // if(dni_cliente != 0){
//                 //     printf("")
//                 // }
                
//             break;
//         }
//     }while(opcion != 0);
// }






// void listar_actividades_sede(actividad *ini_actividad,int eleccion_sede){
//     while(ini_actividad != NULL){
//         if(eleccion_sede = ini_actividad->sede && ini_actividad->estado == 1){
//             printf("%-10d| %s\n",ini_actividad->cod_act,ini_actividad->nombre);
//             ini_actividad = ini_actividad->sgte;
//         }
// 	}
// }
// int buscar_actividad_sede(int eleccion_actividad,int eleccion_sede,actividad *ini_actividad){
//     int buscar=0;
// 	while(ini_actividad != NULL){
// 		if(ini_actividad->cod_act == eleccion_actividad && ini_actividad->sede == eleccion_sede){
// 			buscar = 1;
// 			ini_actividad = NULL;
// 		}else{
// 			buscar = 0;
// 		}
// 		ini_actividad = ini_actividad->sgte;
// 	}
	
// 	return buscar;
// }
// void listar_tipo_turno(tipo_turno *ini_tipo_turno,int eleccion_actividad){
//     char nombres_dias_sem[5][15]={"Lunes","Martes","Mierceles","Jueves","Vienes"};
//     int i;
//     while(ini_tipo_turno != NULL){
//         if(eleccion_actividad = ini_tipo_turno->cod_act && ini_tipo_turno->estado == 1){
//             printf("%d:%d | %d:%d\n",ini_tipo_turno->hora_inicio_turno.hh,ini_tipo_turno->hora_inicio_turno.mm,ini_tipo_turno->hora_fin_turno.hh,ini_tipo_turno->hora_fin_turno.mm);
//             for(i=0;i<5;i++){
//                 if(ini_tipo_turno->dias[i]==1){
//                     printf("%s\n",nombres_dias_sem[i]);
//                 }
//             }
//             printf("\n");
//             ini_tipo_turno = ini_tipo_turno->sgte;
//         }
// 	}
// }

// int buscar_actividad_sede(int eleccion_tipo_turno,int eleccion_actividad,tipo_turno *ini_tipo_turno){
//     int buscar=0;
// 	while(ini_tipo_turno != NULL){
// 		if(ini_tipo_turno->cod_turno == eleccion_tipo_turno && ini_tipo_turno->cod_act == eleccion_actividad){
// 			buscar = 1;
// 			ini_tipo_turno = NULL;
// 		}else{
// 			buscar = 0;
// 		}
// 		ini_tipo_turno = ini_tipo_turno->sgte;
// 	}
	
// 	return buscar;
// }














// void borrar_nodo_tipo_turno(long int tipo_turno_borrar, tipo_turno **ini){
// 	tipo_turno *bor=*ini,*ant=NULL;
//     buscar_borrar_tipo_turno(tipo_turno_borrar,&bor,&ant);
//     if(bor != NULL){
//         if(ant != NULL){
//            *ini = (*ini)->sgte;
//         }else{
//             ant->sgte = bor->sgte;
//         }
//         bor->sgte = NULL;
//         free(bor);
//     }else
//         printf("no existe el dato no esta en la lista\n");
// }	

// void buscar_borrar_tipo_turno(long int tipo_turno_borrar,tipo_turno **rc,tipo_turno **ant){
//     int proceder = 0;
// 	*ant = NULL;
// 	while(rc!=NULL && proceder == 0){
// 		if((*rc)->cod_turno == tipo_turno_borrar){
// 			proceder = 1;
// 		}else{
// 			*ant = *rc;
// 			*rc = (*rc)->sgte;
// 		}
// 	}
// }


























// int buscar_codigo_turno(int codigo_turno,tipo_turno *ini_tipo_turno){
//     int encontrado=0;
// 	while(ini_tipo_turno != NULL && encontrado != 1){
// 		if(ini_tipo_turno->cod_turno == codigo_turno){
// 			encontrado = 1;
// 		}else{
// 			encontrado = 0;
// 		}
// 		ini_tipo_turno = ini_tipo_turno->sgte;
// 	}
	
// 	return encontrado;
// }


















// void insertar_tipo_turno(tipo_turno **nv,tipo_turno **ini_tipo_turno){
//     tipo_turno *aux=NULL;
//     aux=*ini_tipo_turno;
//     if(*ini_tipo_turno != NULL){
//         while(aux->sgte != NULL){
//             aux = aux->sgte;
//         }
//         aux->sgte = *nv;
//         *nv = NULL;
//     }else{
//         *ini_tipo_turno = *nv;
//         *nv = NULL;
//     }
// }


















// // void modificar_reserva(long int dato,int op,reserva **ini_reserva, actividad *ini_actividad){
// // 	int buscar,codigo;
// // 	while(*ini_reserva != NULL){
		
// // 		if((*ini_reserva)->dni == dato){
		
// // 			if(op==1){
// // 				fflush(stdin);
// // 				gets((*ini_reserva)->nombre);
// // 			}else if(op==2){
// // 				scanf("%ld",&(*ini_reserva)->telefono);
// // 			}else if(op==3){
// // 				do{
// // 					system("cls");
// // 					printf("\nActividades Disponibles\n");
// // 					listar_actividades(ini_actividad);
// // 					printf("Ingresar codigo de la actividad deseada: \n");
// // 					scanf("%d",&codigo);
// // 					buscar = buscar_actividades(codigo,ini_actividad);
// // 				}while(buscar != 1 || codigo != 0);
				
// // 				if(buscar == 1){
// // 					(*ini_reserva)->cod_act = codigo;
// // 				}
// // 			}
// // 			*ini_reserva = NULL;
// // 		}
		
// // 		*ini_reserva = (*ini_reserva)->sgte;	
// // 	}
// // }















// void listar_tipo_turnos(tipo_turno *ini){
// 	if(ini!=NULL){
// 		while(ini != NULL){
// 			printf("%-10ld| %30s| %10ld| %d/%d/%d\n",ini->dni,ini->nombre,ini->telefono,ini->f_nacimiento.dd,ini->f_nacimiento.mm,ini->f_nacimiento.yy);
// 			ini = ini->sgte;
// 		}
// 	}else
// 		printf("\nSIN TURNOS \n");
// }


// #endif

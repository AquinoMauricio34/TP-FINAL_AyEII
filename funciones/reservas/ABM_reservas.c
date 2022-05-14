#ifndef ABM_RESERVAS_C
#define ABM_RESERVAS_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"

void ABM_reservas(reserva **ini_reserva,actividad *ini_actividad, tipo_turno *ini_tipo_turno){
    int opcion,encontrado,buscar,op;
    long int dni_cliente;
    int eleccion_sede,eleccion_actividad,eleccion_tipo_turno;
    reserva *nv=NULL;
    do{

        do{
            system("cls");
            printf("1. Alta reserva\n");
            printf("2. Baja reserva\n");
            printf("3. Modificacion reserva\n");
            printf("0.Atras\n");
            printf(">> ");scanf("%d",&opcion);
        }while(opcion<0 || opcion>3);

        //opcion 1
        switch(opcion){
            case 1:
                nv = malloc(sizeof(reserva));
                if(nv != NULL){
                    buscar = -1;
                    do{
                        if(buscar != -1){
                            printf("El dni ingresado ya esta registrado al sistema.\n");
                        }
                        printf("Ingresar dni del cliente: ");scanf("%ld",&dni_cliente);
                        buscar = buscar_dni_reserva(dni_cliente,*ini_reserva);
                    }while(buscar == 1 && dni_cliente != 0);

                    if(dni_cliente != 0){




                        

                        //elegimos entre sede 1 y sede 2
                        printf("Eliga la sede: ");scanf("%d",&eleccion_sede);
                        //luego
                        listar_actividades_sede(ini_actividad,eleccion_sede);
                        //elegimos una actividad
                        do{
                            printf("Ingresar codigo de la actividad: ");scanf("%d",&eleccion_actividad);
                            buscar = buscar_actividad_sede(eleccion_actividad,eleccion_sede,ini_actividad);
                        }while(buscar != 1 && eleccion_actividad != 0);
                        //ya elegida la actividad entra en un if(eleccion_actividad != 0)
                        if(eleccion_actividad != 0){
                            listar_tipo_turno(ini_tipo_turno,eleccion_actividad);
                            //elegimos tipo turno
                            do{
                                printf("Ingresar codigo de la actividad: ");scanf("%d",&eleccion_tipo_turno);
                                buscar = buscar_actividad_sede(eleccion_tipo_turno,eleccion_actividad,ini_tipo_turno);
                            }while(buscar != 1 && eleccion_tipo_turno != 0);
                            //ya elegido el tipo turno entra en un if(eleccion_tipo_turno != 0)
                            if(eleccion_tipo_turno != 0){
                                //guardamos el codigo el tipo_turno
                                nv->cod_turno = eleccion_tipo_turno;
                                //guardamos el codigo la activadad
                                nv->cod_act = eleccion_actividad;
                            }
                        }











                        fflush(stdin);
                        printf("Ingresar nombre del cliente: ");gets(nv->nombre);
                        nv->dni = dni_cliente;
                        printf("Ingresar telefono del cliente: ");scanf("%ld",&nv->telefono);
                        printf("Ingresar fecha de nacimiento del cliente (formato dd/mm/aa): ");scanf("%d/%d/%d",&nv->f_nacimiento.dd,&nv->f_nacimiento.mm,&nv->f_nacimiento.yy);
                        nv->ant = NULL;
                        nv->sgte = NULL;
                        do{
                            printf("Esta seguro de que quiere realizar la reserva? (1.Si | 0.No): ");scanf("%d",&opcion);
                        }while(opcion<0 || opcion>1);
                        if(opcion){
                            insertar_reserva(&nv,&*ini_reserva);
                        }
                    }
                }

            break;
            case 2:
                buscar = 0;
                do{
                    printf("Ingresar dni guardado en el reserva: ");scanf("%ld",&dni_cliente);
                    buscar = buscar_dni_reserva(dni_cliente,*ini_reserva);
                }while(buscar != 1 && dni_cliente != 0);

                if(dni_cliente!=0){
                    printf("Esta seguro/a de que quiere eliminar al cliente (1. SI | 0. NO): ");
                    scanf("%d",&op);
                    if(op == 1){
                        borrar_nodo_reserva(dni_cliente,&*ini_reserva);
                    }
                }
            break;
            case 3:
                // do{
                //     printf("Ingresar dni del cliente: ");scanf("%ld",&dni_cliente);
                //     buscar = buscar_dni_reserva(dni_cliente,*ini_reserva);
                // }while(buscar != 1 && dni_cliente != 0);

                // if(dni_cliente != 0){
                //     printf("")
                // }
                
            break;
        }
    }while(opcion != 0);
}






void listar_actividades_sede(actividad *ini_actividad,int eleccion_sede){
    while(ini_actividad != NULL){
        if(eleccion_sede = ini_actividad->sede && ini_actividad->estado == 1){
            printf("%-10d| %s\n",ini_actividad->cod_act,ini_actividad->nombre);
            ini_actividad = ini_actividad->sgte;
        }
	}
}
int buscar_actividad_sede(int eleccion_actividad,int eleccion_sede,actividad *ini_actividad){
    int buscar=0;
	while(ini_actividad != NULL){
		if(ini_actividad->cod_act == eleccion_actividad && ini_actividad->sede == eleccion_sede){
			buscar = 1;
			ini_actividad = NULL;
		}else{
			buscar = 0;
		}
		ini_actividad = ini_actividad->sgte;
	}
	
	return buscar;
}
void listar_tipo_turno(tipo_turno *ini_tipo_turno,int eleccion_actividad){
    char nombres_dias_sem[5][15]={"Lunes","Martes","Mierceles","Jueves","Vienes"};
    int i;
    while(ini_tipo_turno != NULL){
        if(eleccion_actividad = ini_tipo_turno->cod_act && ini_tipo_turno->estado == 1){
            printf("%d:%d | %d:%d\n",ini_tipo_turno->hora_inicio_turno.hh,ini_tipo_turno->hora_inicio_turno.mm,ini_tipo_turno->hora_fin_turno.hh,ini_tipo_turno->hora_fin_turno.mm);
            for(i=0;i<5;i++){
                if(ini_tipo_turno->dias[i]==1){
                    printf("%s\n",nombres_dias_sem[i]);
                }
            }
            printf("\n");
            ini_tipo_turno = ini_tipo_turno->sgte;
        }
	}
}

int buscar_actividad_sede(int eleccion_tipo_turno,int eleccion_actividad,tipo_turno *ini_tipo_turno){
    int buscar=0;
	while(ini_tipo_turno != NULL){
		if(ini_tipo_turno->cod_turno == eleccion_tipo_turno && ini_tipo_turno->cod_act == eleccion_actividad){
			buscar = 1;
			ini_tipo_turno = NULL;
		}else{
			buscar = 0;
		}
		ini_tipo_turno = ini_tipo_turno->sgte;
	}
	
	return buscar;
}














void borrar_nodo_reserva(long int dni_borrar, reserva **ini){
	reserva *bor=NULL,*ant=NULL,*aux=NULL;
	int proceder = 0;
	bor = *ini;
	buscar_borrar_reserva(dni_borrar,&bor,&ant,&proceder);
	if(bor != NULL){
		if(ant==NULL){
			*ini = (*ini)->sgte;
			bor->sgte = NULL;
			if(*ini!=NULL){
				(*ini)->ant = NULL;
			}
			printf("d\n");
		}else{
			ant->sgte = bor->sgte;
			if(bor->sgte != NULL){
				aux = bor->sgte;
				aux->ant = ant;
				bor->sgte = NULL;
				aux = NULL;
			}else
			bor->ant = NULL;
			ant = NULL;
		}
	}
	free(bor);

}	

void buscar_borrar_reserva(long int dni_borrar,reserva **rc,reserva **ant,int *proceder){
	*proceder = 0;
	
	*ant = NULL;
	while(rc!=NULL && *proceder == 0){
		if((*rc)->dni == dni_borrar){
			*proceder = 1;
		}else{
			*ant = *rc;
			*rc = (*rc)->sgte;
		}
	}
}


























int buscar_dni_reserva(long int dni,reserva *ini_reserva){
    int encontrado=0;
	while(ini_reserva != NULL && encontrado != 1){
		if(ini_reserva->dni == dni){
			encontrado = 1;
		}else{
			encontrado = 0;
		}
		ini_reserva = ini_reserva->sgte;
	}
	
	return encontrado;
}


















void insertar_reserva(reserva **nv,reserva **ini_reserva){
    reserva *aux=NULL;
    aux=*ini_reserva;
    if(*ini_reserva != NULL){

        while(aux->sgte != NULL){
            aux = aux->sgte;
        }

        aux->sgte = *nv;
        (*nv)->ant = aux;
        *nv = NULL;
    }else{
        *ini_reserva = *nv;
        *nv = NULL;
    }
}


















// void modificar_reserva(long int dato,int op,reserva **ini_reserva, actividad *ini_actividad){
// 	int buscar,codigo;
// 	while(*ini_reserva != NULL){
		
// 		if((*ini_reserva)->dni == dato){
		
// 			if(op==1){
// 				fflush(stdin);
// 				gets((*ini_reserva)->nombre);
// 			}else if(op==2){
// 				scanf("%ld",&(*ini_reserva)->telefono);
// 			}else if(op==3){
// 				do{
// 					system("cls");
// 					printf("\nActividades Disponibles\n");
// 					listar_actividades(ini_actividad);
// 					printf("Ingresar codigo de la actividad deseada: \n");
// 					scanf("%d",&codigo);
// 					buscar = buscar_actividades(codigo,ini_actividad);
// 				}while(buscar != 1 || codigo != 0);
				
// 				if(buscar == 1){
// 					(*ini_reserva)->cod_act = codigo;
// 				}
// 			}
// 			*ini_reserva = NULL;
// 		}
		
// 		*ini_reserva = (*ini_reserva)->sgte;	
// 	}
// }















void listar_reservas(reserva *ini){
	if(ini!=NULL){
		while(ini != NULL){
			printf("%-10ld| %30s| %10ld| %d/%d/%d\n",ini->dni,ini->nombre,ini->telefono,ini->f_nacimiento.dd,ini->f_nacimiento.mm,ini->f_nacimiento.yy);
			ini = ini->sgte;
		}
	}else
		printf("\nSIN RESERVAS\n");
}


#endif

#ifndef ABM_TIPO_TURNO_C
#define ABM_TIPO_TURNO_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"

void ABM_tipo_turno(tipo_turno **ini_tipo_turno,actividad *ini_actividad){
    int opcion,encontrado,buscar,op;
    int codigo_turno;
    int eleccion_sede,eleccion_actividad;
    int i;
    long int dni_cliente;
    char nombres_dias_sem[5][15]={"Lunes","Martes","Miercoles","Jueves","Vienes"};
    tipo_turno *aux=NULL;
    tipo_turno *nv=NULL;
    do{

        do{
            system("cls");
            printf("1. Alta tipo_turno\n");
            printf("2. Baja tipo_turno\n");
            printf("3. Modificacion tipo_turno\n");
            printf("0.Atras\n");
            printf(">> ");scanf("%d",&opcion);
        }while(opcion<0 || opcion>3);

        //opcion 1
        switch(opcion){
            case 1:
                nv = malloc(sizeof(tipo_turno));
                if(nv != NULL){
                    //generamos codigo aleatorio, comprobando que no exista pero no lo guardamos hasta el final de la carga de datos
                    if(*ini_tipo_turno == NULL){
                        nv->cod_turno = 1;
                    }else{
                        aux=*ini_tipo_turno;
                        while(aux->sgte!=NULL){
                            aux = aux->sgte;
                        }
                        nv->cod_turno= aux->cod_turno + 1;
                    }


                    //elegimos entre sede 1 y sede 2
                    do{
                        printf("Eliga la sede 1 | 2 (0 para salir): ");scanf("%d",&eleccion_sede);
                    }while(eleccion_sede<0 || eleccion_sede>2);
                    //luego
                    if(eleccion_sede!=0){

                        listar_actividades_sede(ini_actividad,eleccion_sede);
                        //elegimos una actividad
                        do{
                            printf("Ingresar codigo de la actividad: ");scanf("%d",&eleccion_actividad);
                            buscar = buscar_actividad_sede(eleccion_actividad,eleccion_sede,ini_actividad);
                        }while(buscar != 1 && eleccion_actividad != 0);
                        
                        if(eleccion_actividad != 0){
                            //cargamos es precio
                            printf("Ingresar precio del turno: ");scanf("%f",&nv->precio);
                            //cargamos hora inicio turno
                            printf("Ingresar la hora de inicio del turno (formato hh:mm): ");scanf("%d:%d",&nv->hora_inicio_turno.hh,&nv->hora_inicio_turno.mm);
                            //cargamos hora fin turno
                            printf("Ingresar la hora de fin del turno (formato hh:mm): ");scanf("%d:%d",&nv->hora_fin_turno.hh,&nv->hora_fin_turno.mm);
                            //cargar dias
                            printf("Dias de la semana del turno:\n");
                            for(i=0;i<5;i++){
                                do{
                                    printf("%s: ",nombres_dias_sem[i]);scanf("%d",&nv->dias[i]);
                                }while(nv->dias[i]<0 || nv->dias[i]>1);
                            }
                            //el estado será 1, pero solo para pruebas, luego lo arreglaremos
                            printf("Ingresar el estado del tipo turno: ");scanf("%d",&nv->estado);
                            //guardamos el codigo de la actividad elegida
                            nv->cod_act = eleccion_actividad;
                            //insertamos
                            nv->sgte = NULL;
                            insertar_tipo_turno(&nv,&*ini_tipo_turno);
                        }
                    }
                }

            break;
            case 2:
                buscar = 0;
                do{
                    printf("Ingresar codigo del turno a eliminar: ");scanf("%ld",&codigo_turno);
                    buscar = buscar_codigo_turno(codigo_turno,*ini_tipo_turno);
                }while(buscar != 1 && codigo_turno != 0);

                if(codigo_turno!=0){
                    printf("Esta seguro/a de que quiere eliminar al cliente (1. SI | 0. NO): ");
                    scanf("%d",&op);
                    if(op == 1){
                        borrar_nodo_tipo_turno(codigo_turno,&*ini_tipo_turno);
                    }
                }
            break;
            case 3:
                do{
                    printf("Ingresar el codigo del turno: ");scanf("%ld",&codigo_turno);
                    buscar = buscar_codigo_turno(codigo_turno,*ini_tipo_turno);
                }while(buscar != 1 && codigo_turno != 0);

                if(codigo_turno != 0){
                    do{
						system("cls");
						do{
							printf("1-modificar precio del turno \n");
							printf("2-modificar hora de inicio del turno \n");
							printf("3-modificar hora de fin del turno \n");
                            printf("4-modificar dias del turno\n");
							printf("0-Finalizar\n>> ");
							scanf("%d",&op);
						}while(op<0 || op>4);
						// system("cls");
						modificar_tipo_turno(codigo_turno,op,&*ini_tipo_turno);
					}while(op!=0);
                }
                
            break;
        }
    }while(opcion != 0);
}












void borrar_nodo_tipo_turno(long int tipo_turno_borrar, tipo_turno **ini){
	tipo_turno *bor=*ini,*ant=NULL;
    buscar_borrar_tipo_turno(tipo_turno_borrar,&bor,&ant);
    if(bor != NULL){
        if(ant == NULL){
           *ini = (*ini)->sgte;
        }else{
            ant->sgte = bor->sgte;
        }
        bor->sgte = NULL;
        free(bor);
    }else
        printf("no existe el dato no esta en la lista\n");
}	

void buscar_borrar_tipo_turno(long int tipo_turno_borrar,tipo_turno **rc,tipo_turno **ant){
    int proceder = 0;
	*ant = NULL;
	while(rc!=NULL && proceder == 0){
		if((*rc)->cod_turno == tipo_turno_borrar){
			proceder = 1;
		}else{
			*ant = *rc;
			*rc = (*rc)->sgte;
		}
	}
}


























int buscar_codigo_turno(int codigo_turno,tipo_turno *ini_tipo_turno){
    int encontrado=0;
	while(ini_tipo_turno != NULL && encontrado != 1){
		if(ini_tipo_turno->cod_turno == codigo_turno){
			encontrado = 1;
		}else{
			encontrado = 0;
		}
		ini_tipo_turno = ini_tipo_turno->sgte;
	}
	
	return encontrado;
}


















void insertar_tipo_turno(tipo_turno **nv,tipo_turno **ini_tipo_turno){
    tipo_turno *aux=NULL;
    aux=*ini_tipo_turno;
    if(*ini_tipo_turno != NULL){
        while(aux->sgte != NULL){
            aux = aux->sgte;
        }
        aux->sgte = *nv;
        *nv = NULL;
    }else{
        *ini_tipo_turno = *nv;
        *nv = NULL;
    }
}


















void modificar_tipo_turno(long int dato,int op,reserva **ini_tipo_turno){
	int buscar,codigo,encontrado=0;
    char nombres_dias_sem[5][15]={"Lunes","Martes","Miercoles","Jueves","Vienes"};
    int i;
    tipo_turno *aux = *ini_tipo_turno;
	while(aux != NULL && encontrado != 1){
		
		if(aux->cod_turno == dato){
		
            // printf("1-modificar precio del turno \n");
            // printf("2-modificar hora de inicio del turno \n");
            // printf("2-modificar hora de fin del turno \n");
            // printf("4-modificar dias del turno\n");

			if(op==1){
				scanf("%f",&aux->precio);
			}else if(op==2){
				scanf("%d:%d",&aux->hora_inicio_turno.hh,&aux->hora_inicio_turno.mm);
			}else if(op==3){
				scanf("%d:%d",&aux->hora_fin_turno.hh,&aux->hora_fin_turno.mm);
			}else if(op==4){
				printf("Dias de la semana del turno:\n");
                for(i=0;i<5;i++){
                    do{
                        printf("%s: ",nombres_dias_sem[i]);scanf("%d",&aux->dias[i]);
                    }while(aux->dias[i]<0 || aux->dias[i]>1);
                }
			}
			encontrado = 1;
		}
		
		aux = aux->sgte;	
	}
}















void listar_all_tipo_turnos(tipo_turno *ini){
	if(ini!=NULL){
		while(ini != NULL){
			printf("cod_t: %7d | cod_act: %7d | precio: %.2f | est: %d\n",ini->cod_turno,ini->cod_act,ini->precio,ini->estado);
            printf("Dias %d-%d-%d-%d-%d\n",ini->dias[0],ini->dias[1],ini->dias[2],ini->dias[3],ini->dias[4]);
            printf("Hora inicio: %d:%d, Hora fin: %d:%d\n",ini->hora_inicio_turno.hh,ini->hora_inicio_turno.mm,ini->hora_fin_turno.hh,ini->hora_fin_turno.mm);
            printf("-----------\n");
            
			ini = ini->sgte;
		}
	}else
		printf("\nSIN TURNOS \n");
}


#endif

#ifndef ABM_RESERVAS_C
#define ABM_RESERVAS_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../estructuras.h"
#include"../../prototipos.h"

void ABM_reservas(reserva **ini_reserva){
    int opcion,encontrado,buscar,op;
    long int dni_quitar;
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
                    fflush(stdin);
                    printf("Ingresar nombre del cliente: ");gets(nv->nombre);
                    //DO WHILE PARA EL DNI------------------------------------------------------
                    printf("Ingresar DNI del cliente: ");scanf("%ld",&nv->dni);
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
            break;
            case 2:
                buscar = 0;
                do{
                    printf("Ingresar dni guardado en el reserva: ");scanf("%ld",&dni_quitar);
                    buscar = buscar_dni_reserva(dni_quitar,*ini_reserva);

                }while(buscar != 1 && dni_quitar != 0);

                if(dni_quitar!=0){
                    printf("Esta seguro/a de que quiere eliminar al cliente (1. SI | 0. NO): ");
                    scanf("%d",&op);
                    if(op == 1){
                        borrar_nodo_reserva(dni_quitar,&*ini_reserva);
                    }
                }
            break;
            case 3:
                
            break;
        }
    }while(opcion != 0);
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
			printf("\nddddddd\n");
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

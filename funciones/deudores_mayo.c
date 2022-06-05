#ifndef DEUDORES_MAYO_C
#define DEUDORES_MAYO_C

#include<stdio.h>
#include<stdlib.h>
#include"../prototipos.h"
#include"../estructuras.h"



void deudores_mayo(turno_cliente *ini_turno_cliente,cuenta *ini_cuenta,cliente *ini_cliente){
	deudores *nv=NULL,*arbol = NULL;
    cuenta *aux_cuenta=NULL;
	cliente *aux_cliente=NULL;
    int pagado,eleccion_yy,op;
	printf("Ingresar anio: ");scanf("%d",&eleccion_yy);
	while(ini_turno_cliente != NULL){
        pagado = 0;
		aux_cuenta = ini_cuenta;
        while(aux_cuenta != NULL){
            if(aux_cuenta->cod_clientesta == ini_turno_cliente->cod_clientesta){
                if(aux_cuenta->f_pago.mm == 5 && aux_cuenta->f_pago.yy == eleccion_yy){
                    pagado = 1;
                }
            }
            aux_cuenta = aux_cuenta->sgte;
        }
        if(pagado == 0){
			aux_cliente = ini_cliente;
			while(aux_cliente != NULL){
				if(aux_cliente->dni == ini_turno_cliente->dni){




				nv = malloc(sizeof(deudores));
				if(nv != NULL){
					puts(aux_cliente->nombre);
					strcpy(nv->nombre,aux_cliente->nombre);
					nv->der=NULL;
					nv->izq=NULL;
					arbol = insertar_deudor(arbol,nv);
					nv=NULL;
				}



					aux_cliente=NULL;
				}else
					aux_cliente = aux_cliente->sgte;
			}

        }
        ini_turno_cliente = ini_turno_cliente->sgte;
    }
	printf("DEUDORES MAYO ANIO %d\n\n",eleccion_yy);
	if(arbol != NULL){
		do{
			inorder(arbol);
			printf("\n");
			system("pause");
			printf("Ingrese 0 para salir: \n>> ");
			scanf("%d",&op);
		}while(op != 0);
		arbol = vaciar_arbol(arbol);
	}else
		printf("Sin deudores.\n");


	return 0;
}


deudores * borrar_nodo(deudores *borrar){
	deudores *ant,*r;
	ant = NULL;
	r = borrar->izq;
	if(r!=NULL){
		while(r->der != NULL){
			ant = r;
			r = r->der;
		}
		r->der = borrar->der;
		if(ant != NULL){
			ant->der = r->izq;
			r->izq = borrar->izq;
		}
	}else
		r = borrar->der;

	borrar->der = NULL;
	borrar->izq = NULL;
	free(borrar);
	return r;
}


deudores * vaciar_arbol(deudores *arbol){
	while(arbol != NULL){
		arbol = borrar_nodo(arbol);
	}
	return arbol;
}

void inorder(deudores *arbol){
	if(arbol != NULL){
		inorder(arbol->izq);
		puts(arbol->nombre);printf("\n");
		inorder(arbol->der);
	}
}

deudores * insertar_deudor(deudores *arbol,deudores *nv){
	if(arbol == NULL){
		arbol = nv;

	}else{
		if(strcmp(nv->nombre,arbol->nombre) >= 0){
			arbol->der = insertar_deudor(arbol->der,nv);
		}else{
			arbol->izq = insertar_deudor(arbol->izq,nv);
		}
	}
	return arbol;
}


#endif
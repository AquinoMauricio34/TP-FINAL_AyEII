#ifndef DEUDORES_MAYO_C
#define DEUDORES_MAYO_C

#include<stdio.h>
#include<stdlib.h>
#include"../prototipos.h"
#include"../estructuras.h"



void deudores_mayo(turno_cliente *ini_turno_cliente,cuenta *ini_cuenta,cliente *ini_cliente){
	deudores *nv=NULL,*arbol = NULL;
    cuenta *aux_cuenta=NULL;
	turno_cliente *aux_turno_cliente=NULL;
	cliente *aux_cliente=NULL;
    int pagado,eleccion_yy,op,encontrado;
	printf("Ingresar anio: ");scanf("%d",&eleccion_yy);
	while(ini_cliente != NULL){
		// puts(ini_cliente->nombre);
		aux_turno_cliente = ini_turno_cliente;
		encontrado = 0;
		while(aux_turno_cliente != NULL && encontrado != 1){
			if(aux_turno_cliente->dni == ini_cliente->dni){
				pagado = 0;
				aux_cuenta = ini_cuenta;
				while(aux_cuenta != NULL){
					if(aux_cuenta->cod_clientesta == aux_turno_cliente->cod_clientesta){
						if(aux_cuenta->f_pago.mm >= 5 && aux_cuenta->f_pago.yy == eleccion_yy){
							pagado = 1;
						}
					}
					aux_cuenta = aux_cuenta->sgte;
				}
				if(aux_turno_cliente->f_ultima_vez.yy == eleccion_yy){
					if(pagado == 0){
						
							nv = malloc(sizeof(deudores));
							if(nv != NULL){
								// puts(aux_cliente->nombre);
								strcpy(nv->nombre,ini_cliente->nombre);
								nv->der=NULL;
								nv->izq=NULL;
								// printf("123nombre: %s\n",nv->nombre);
								arbol = insertar_deudor(arbol,nv);
								nv=NULL;
							}
							encontrado = 1;
					}
				}

			}
			aux_turno_cliente = aux_turno_cliente->sgte;
		}
		ini_cliente = ini_cliente->sgte;
	}
	aux_cliente = NULL;
	aux_cuenta = NULL;
	aux_turno_cliente = NULL;
	printf("DEUDORES MAYO ANIO %d\n\n",eleccion_yy);
	if(arbol != NULL){
		do{
			system("pause");
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
		if(strcmp(nv->nombre,arbol->nombre) > 0){
			// printf("\nDERECHA\n");
			arbol->der = insertar_deudor(arbol->der,nv);
		}else{
			// printf("\nIZQUIERDA\n");
			arbol->izq = insertar_deudor(arbol->izq,nv);
		}
	}
	return arbol;
}


#endif
// #ifndef BORRAR_NODO_RESERVA_C
// #define BORRAR_NODO_RESERVA_C

// #include<stdio.h>
// #include<stdlib.h>
// #include"../../estructuras.h"
// #include"../../prototipos.h"

// // void desencolar(reserva **nv,reserva **S, reserva **E){
// //     *nv = *S;
// //     *S = (*S)->sgte;
// //     if(*S==NULL){
// //         *E = NULL;
// //     }
// // }


// void borrar_nodo_reserva(long int dni_borrar, reserva **ini){
// 	reserva *bor=NULL,*ant=NULL,*aux=NULL;
// 	int proceder = 0;
// 	bor = *ini;
// 	buscar_borrar_reserva(dni_borrar,&bor,&ant,&proceder);
// 	if(bor != NULL){
// 		if(ant==NULL){
// 			printf("aaaaaaaa\n");
// 			*ini = (*ini)->sgte;
// 			printf("c\n");
// 			bor->sgte = NULL;
// 			printf("b\n");
// 			if(*ini!=NULL){
// 				(*ini)->ant = NULL;
// 			}
// 			printf("d\n");
// 		}else{
// 			// printf("ant = %d, bor = %d\n",ant->dni,bor->dni);
// 			ant->sgte = bor->sgte;
// 			if(bor->sgte != NULL){
// 				aux = bor->sgte;
// 				// printf("bor->sgte = %d\n",aux->dni);
// 				aux->ant = ant;
// 				// printf("eeeeeeeeee\n");
// 				bor->sgte = NULL;
// 				// printf("ffffffffffffffffff\n");
// 				aux = NULL;
// 				// printf("gggggggggggg\n");
// 			}else
// 				// printf("bor->sgte = NULL\n");
// 			// printf("hhhhhhhhhhhh\n");
// 			bor->ant = NULL;
// 			// printf("iiiiiiii\n");
// 			ant = NULL;
// 			// printf("jjjjjjjjjjj\n");
// 		}
// 	}
// 	// printf("kkkkkkk\n");
// 	// printf("ant = %d, bor = %d\n",ant->dni,bor->dni);
// 	// printf("llllllllll\n");
// 	free(bor);

// 	system("pause");
// }	

// void buscar_borrar_reserva(long int dni_borrar,reserva **rc,reserva **ant,int *proceder){
// 	*proceder = 0;
	
// 	*ant = NULL;
// 	while(rc!=NULL && *proceder == 0){
// 		if((*rc)->dni == dni_borrar){
// 			*proceder = 1;
// 		}else{
// 			*ant = *rc;
// 			*rc = (*rc)->sgte;
// 		}
// 	}
// }

// #endif
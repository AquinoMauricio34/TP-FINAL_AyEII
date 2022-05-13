// #ifndef INSERTAR_RESERVA_C
// #define INSERTAR_RESERVA_C

// #include<stdio.h>
// #include<stdlib.h>
// #include"../../estructuras.h"
// #include"../../prototipos.h"

// // void encolar(reserva **nv,reserva **S, reserva **E){
// //     if(*E == NULL){
// //         *S = *nv;
// //     }else{
// //         (*E)->sgte = *nv;
// //     }
// //     *E = *nv;
// //     *nv = NULL;
// // }


// void insertar_reserva(reserva **nv,reserva **ini_reserva){
//     reserva *aux=NULL;
//     aux=*ini_reserva;
//     // printf("nv = %d\n",(*nv)->dni);
//     if(*ini_reserva != NULL){
//         // printf("1aux = %d\n",aux->dni);

//         while(aux->sgte != NULL){
//             // printf("2aux = %d\n",aux->dni);
//             aux = aux->sgte;
//             // if(aux != NULL){
//                 // printf("3aux = %d\n",aux->dni);
//             // }
//             // printf("\naaaaaaaa\n");
//             // system("pause");
//         }

//         aux->sgte = *nv;
//         (*nv)->ant = aux;
//         *nv = NULL;
//         // printf("\naaaa111111\n");
//     }else{
//         // printf("\nbbbbbbbbb\n");
//         *ini_reserva = *nv;
//         *nv = NULL;
//         // printf("\nbbbb111111\n");
//     }
//     // system("pause");
// }

// #endif
#include<stdio.h>
#include<stdlib.h>

#include"prototipos.h"
#include"includes.h"
#include"estructuras.h"


int main(){
    //reserva
    reserva *ini_reserva=NULL;

    int opcion;
    //llamado a funciones de verificacion de fecha, borrado o activacion de actividades/tipo_turnos
    do{
        do{
        //opciones a elegir
            printf("1. ABM Profesores\n");
            printf("2. ABM Reservas\n");
            printf("3. ABM Cliente\n");
            printf("0. Cerrar Programa\n");
            printf(">> ");scanf("%d",&opcion);
        }while(opcion<0 || opcion>3);

        switch(opcion){
            case 1:
                // ABM_profesores();
            break;
            case 2:
                ABM_reservas(&ini_reserva);
            break;
            case 3:
                // ABM_clientes();
            break;
        }
    }while(opcion != 0);


    return 0;
}

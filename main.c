#include<stdio.h>
#include<stdlib.h>

#include"prototipos.h"
#include"includes.h"
#include"estructuras.h"


int main(){
    //reserva
    reserva *ini_reserva=NULL;
    actividad *ini_actividad=NULL;
    turno_cliente *ini_turno_cliente=NULL;

    int opcion;
    //llamado a funciones de verificacion de fecha, borrado o activacion de actividades/tipo_turnos
    do{
        do{
            system("cls");
        //opciones a elegir
            printf("1. ABM Profesores\n");
            printf("2. ABM Reservas\n");
            printf("3. Listas Reservas\n");
            printf("4. ABM Actividades\n");
            printf("5. Listas Actividades\n");
            printf("0. Cerrar Programa\n");
            printf(">> ");scanf("%d",&opcion);
        }while(opcion<0 || opcion>5);

        switch(opcion){
            case 1:
                // ABM_profesores();
            break;
            case 2:
                system("cls");
                ABM_reservas(&ini_reserva,&ini_actividad,&ini_turno_cliente);
            break;
            case 3:
                system("cls");
                listar_reservas(ini_reserva);
                system("pause");
            break;
            case 4:
                system("cls");
                ABM_actividades(&ini_actividad,&ini_turno_cliente);
            break;
            case 5:
                system("cls");
                listar_all_actividades(ini_actividad);
                system("pause");
            break;
        }
    }while(opcion != 0);


    return 0;
}

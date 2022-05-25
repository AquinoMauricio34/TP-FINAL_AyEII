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
    cliente *ini_cliente=NULL;
    profesor *ini_profesor=NULL;
    tipo_turno *ini_tipo_turno=NULL;
    cuenta *ini_cuenta = NULL;
    char nombres_dias_sem[5][15]={"Lunes","Martes","Miercoles","Jueves","Vienes"};

    //cargado de las listas
    cargar_listas(&ini_actividad,&ini_tipo_turno,&ini_cliente);
    
    int opcion;
    //llamado a funciones de verificacion de fecha, borrado o activacion de actividades/tipo_turnos
    do{
        do{
            system("cls");
            fecha_actual();
            printf("%d/%d/%d %d:%d %s\n\n",fecha_global.dd,fecha_global.mm,fecha_global.yy,hora_global.hh,hora_global.mm,nombres_dias_sem[dia_sem_actual-1]);
        //opciones a elegir
            printf("1. ABM Clientes\n");
            printf("2. ABM Reservas\n");
            printf("3. Listar Reservas\n");
            printf("4. ABM Actividades\n");
            printf("5. Listar Actividades\n");
            printf("6. Listar Clientes\n");
            printf("7. ABM Profesores\n");
            printf("8. Listar Profesores\n");
            printf("9. ABM T.Turnos\n");
            printf("10. Listar T.Turnos\n");
            printf("11. ABM T.Clientes\n");
            printf("12. Listar T.Clientes\n");
            printf("13. Listar Cuentas\n");
            printf("0. Cerrar Programa\n");
            printf(">> ");scanf("%d",&opcion);
        }while(opcion<0 || opcion>13);

        switch(opcion){
            case 1:
                system("cls");
                ABM_clientes(&ini_cliente,ini_actividad,&ini_turno_cliente);
            break;
            case 2:
                system("cls");
                ABM_reservas(&ini_reserva,ini_actividad,ini_tipo_turno);
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
            case 6:
                system("cls");
                listar_all_clientes(ini_cliente);
                system("pause");
            break;
            case 7:
                system("cls");
                ABM_profesores(&ini_profesor);
            break;
            case 8:
                system("cls");
                listar_all_profesores(ini_profesor);
                system("pause");
            break;
            case 9:
                system("cls");
                ABM_tipo_turno(&ini_tipo_turno,ini_actividad);
            break;
            case 10:
                system("cls");
                listar_all_tipo_turnos(ini_tipo_turno);
                system("pause");
            break;
            case 11:
                system("cls");
                abm_clientes_ta(&ini_turno_cliente,&ini_tipo_turno,ini_actividad,ini_cliente,&ini_cuenta);
            break;
            case 12:
                system("cls");
                listar_all_turnos_clientes(ini_turno_cliente);
                system("pause");
            break;
            case 13:
                system("cls");
                listar_all_cuentas(ini_cuenta);
                system("pause");
            break;
            
        }
    }while(opcion != 0);

    guardado_listas(ini_actividad,ini_tipo_turno,ini_cliente);

    return 0;
}

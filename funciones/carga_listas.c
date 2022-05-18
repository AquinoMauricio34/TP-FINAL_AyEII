#ifndef CARGAR_LISTAS_C
#define CARGAR_LISTAS_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../estructuras.h"
#include"../prototipos.h"

void cargar_listas(actividad **ini_actividad){
    carga_actividades(&*ini_actividad);
}

void carga_actividades(actividad **ini_actividad){
	FILE *a_actividades;
	if((a_actividades=fopen("actividades.dat","rb"))!=NULL){
		
		actividad c_actividad;
		actividad *nv=NULL;
		
		// printf("\n111\n");
		
		fread(&c_actividad,sizeof(actividad),1,a_actividades);
		// printf("\n111\n");
		while(!feof(a_actividades)){
			// printf("%s | %d | %d\n",c_actividad.nombre,c_actividad.cant_personas,c_actividad.sede);
			// printf("\n222\n");
			nv = malloc(sizeof(actividad));
			if(nv!=NULL){
				// printf("\n333\n");
				//carga datos
				strcpy(nv->nombre,c_actividad.nombre);
				nv->cant_personas = c_actividad.cant_personas;
				nv->sede = c_actividad.sede;
                nv->cod_act = c_actividad.cod_act;
                nv->estado = c_actividad.estado;
				nv->sgte = NULL;
				//insertar
				insertar_actividad_carga(&nv,&*ini_actividad);
			}
			
			
			fread(&c_actividad,sizeof(actividad),1,a_actividades);
		}
		fclose(a_actividades);
	}else{
		// printf("\naaaa111\n");
		if((a_actividades=fopen("actividades.dat","wb"))!=NULL){
			fclose(a_actividades);
		}
	}
}

void insertar_actividad_carga(actividad **nv,actividad **ini){
	(*nv)->sgte = *ini;
	*ini = *nv;
	*nv = NULL;
}

#endif
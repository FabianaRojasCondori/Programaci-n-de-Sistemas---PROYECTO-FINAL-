#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../include/descargas.h"


#define MAX_DESCARGAS 50


struct Descarga
{
    char nombre[100];
    int tamano;
    int progreso;
    char estado[30];
};


struct Descarga cola[MAX_DESCARGAS];

int cantidadDescargas = 0;



void menuDescargas()
{
    int opcion;

    do
    {
        printf("\n====================================\n");
        printf("          COLA DE DESCARGAS\n");
        printf("====================================\n");
        printf("1. Agregar descarga\n");
        printf("2. Mostrar cola\n");
        printf("3. Iniciar descarga\n");
        printf("0. Regresar\n");
        printf("====================================\n");
        printf("Seleccione una opcion: ");

        scanf("%d", &opcion);


        switch(opcion)
        {
            case 1:
                agregarDescarga();
                break;


            case 2:
                mostrarCola();
                break;


            case 3:
                iniciarDescarga();
                break;


            case 0:
                printf("\nRegresando...\n");
                break;


            default:
                printf("\nOpcion invalida.\n");
        }


    }while(opcion != 0);
}
void agregarDescarga()
{
    if(cantidadDescargas >= MAX_DESCARGAS)
    {
        printf("\nLa cola esta llena.\n");
        return;
    }


    printf("\n========== AGREGAR DESCARGA ==========\n");


    printf("Nombre del archivo: ");
    scanf("%s", cola[cantidadDescargas].nombre);


    printf("Tamano del archivo (MB): ");
    scanf("%d", &cola[cantidadDescargas].tamano);


    cola[cantidadDescargas].progreso = 0;


    strcpy(cola[cantidadDescargas].estado, "En espera");


    guardarEvento("Nueva descarga agregada");


    cantidadDescargas++;


    printf("\nDescarga agregada correctamente.\n");
}



void guardarEvento(char mensaje[])
{
    FILE *archivo;


    archivo = fopen("logs/eventos.log", "a");


    if(archivo == NULL)
    {
        printf("No se pudo abrir el archivo de eventos.\n");
        return;
    }


    fprintf(archivo, "%s\n", mensaje);


    fclose(archivo);
}
void mostrarCola()
{
    int i;


    printf("\n========== COLA DE DESCARGAS ==========\n");


    if(cantidadDescargas == 0)
    {
        printf("No hay descargas en la cola.\n");
        return;
    }


    for(i = 0; i < cantidadDescargas; i++)
    {
        printf("\nDescarga %d\n", i + 1);
        printf("Archivo: %s\n", cola[i].nombre);
        printf("Tamano: %d MB\n", cola[i].tamano);
        printf("Progreso: %d%%\n", cola[i].progreso);
        printf("Estado: %s\n", cola[i].estado);
    }
}



void iniciarDescarga()
{
    int posicion;


    printf("\n========== INICIAR DESCARGA ==========\n");


    if(cantidadDescargas == 0)
    {
        printf("No existen descargas pendientes.\n");
        return;
    }


    printf("Seleccione la descarga (1-%d): ", cantidadDescargas);
    scanf("%d", &posicion);


    posicion--;


    if(posicion < 0 || posicion >= cantidadDescargas)
    {
        printf("Descarga invalida.\n");
        return;
    }


    strcpy(cola[posicion].estado, "Descargando");


    guardarEvento("Inicio de descarga");


    printf("\nDescargando %s...\n", cola[posicion].nombre);


    for(int progreso = 0; progreso <= 100; progreso += 20)
    {
        cola[posicion].progreso = progreso;


        printf("Progreso: %d%%\n", progreso);


        sleep(1);
    }


    strcpy(cola[posicion].estado, "Completada");


    guardarEvento("Descarga completada");


    printf("\nDescarga finalizada correctamente.\n");
}
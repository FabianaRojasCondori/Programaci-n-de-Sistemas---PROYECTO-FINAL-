#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#include "../include/backups.h"

void menuBackups()
{
    int opcion;

    do
    {
        printf("\n====================================\n");
        printf("      SISTEMA DE RESPALDOS\n");
        printf("====================================\n");
        printf("1. Crear respaldo\n");
        printf("2. Restaurar respaldo\n");
        printf("3. Listar respaldos\n");
        printf("0. Regresar\n");
        printf("====================================\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                crearRespaldo();
                break;

            case 2:
                restaurarRespaldo();
                break;

            case 3:
                listarRespaldos();
                break;

            case 0:
                printf("\nRegresando...\n");
                break;

            default:
                printf("\nOpcion invalida.\n");
        }

    }while(opcion!=0);
}
void crearRespaldo()
{
    char origen[200];
    char nombreRespaldo[100];
    char destino[300];

    FILE *entrada;
    FILE *salida;

    int caracter;

    printf("\n========== CREAR RESPALDO ==========\n");

    printf("Ingrese la ruta del archivo: ");
    scanf("%s", origen);

    printf("Ingrese el nombre del respaldo: ");
    scanf("%s", nombreRespaldo);

    sprintf(destino, "backups/%s", nombreRespaldo);

    entrada = fopen(origen, "rb");

    if (entrada == NULL)
    {
        printf("Error: No se pudo abrir el archivo origen.\n");
        return;
    }

    salida = fopen(destino, "wb");

    if (salida == NULL)
    {
        printf("Error: No se pudo crear el respaldo.\n");
        fclose(entrada);
        return;
    }

    while ((caracter = fgetc(entrada)) != EOF)
    {
        fputc(caracter, salida);
    }

    fclose(entrada);
    fclose(salida);

    printf("\nRespaldo creado correctamente en: %s\n", destino);
}
void restaurarRespaldo()
{
    char nombreRespaldo[100];
    char destino[200];
    char origen[300];

    FILE *entrada;
    FILE *salida;

    int caracter;

    printf("\n========== RESTAURAR RESPALDO ==========\n");

    printf("Nombre del respaldo: ");
    scanf("%s", nombreRespaldo);

    printf("Ruta destino: ");
    scanf("%s", destino);

    sprintf(origen, "backups/%s", nombreRespaldo);

    entrada = fopen(origen, "rb");

    if (entrada == NULL)
    {
        printf("Error: No existe el respaldo.\n");
        return;
    }

    salida = fopen(destino, "wb");

    if (salida == NULL)
    {
        printf("Error: No se pudo restaurar el archivo.\n");
        fclose(entrada);
        return;
    }

    while ((caracter = fgetc(entrada)) != EOF)
    {
        fputc(caracter, salida);
    }

    fclose(entrada);
    fclose(salida);

    printf("\nRespaldo restaurado correctamente.\n");
}

void listarRespaldos()
{
    DIR *directorio;
    struct dirent *archivo;

    directorio = opendir("backups");

    if (directorio == NULL)
    {
        printf("No existe la carpeta de respaldos.\n");
        return;
    }

    printf("\n========== RESPALDOS DISPONIBLES ==========\n\n");

    while ((archivo = readdir(directorio)) != NULL)
    {
        if (strcmp(archivo->d_name, ".") != 0 &&
            strcmp(archivo->d_name, "..") != 0)
        {
            printf("%s\n", archivo->d_name);
        }
    }

    closedir(directorio);
}
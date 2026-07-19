#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

#include "../include/archivos.h"

void menuArchivos()
{
    int opcion;

    do
    {
        printf("\n====================================\n");
        printf("        SHELL DE ARCHIVOS\n");
        printf("====================================\n");
        printf("1. Listar archivos\n");
        printf("2. Copiar / Mover archivos\n");
        printf("3. Eliminar archivo\n");
        printf("4. Buscar archivo\n");
        printf("5. Mostrar estadisticas\n");
        printf("0. Regresar\n");
        printf("====================================\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                listarArchivos();
                break;

            case 2:
                copiarMoverArchivo();
                break;

            case 3:
                eliminarArchivo();
                break;

            case 4:
                buscarArchivo();
                break;

            case 5:
                mostrarEstadisticas();
                break;

            case 0:
                printf("\nRegresando al menu principal...\n");
                break;

            default:
                printf("\nOpcion invalida.\n");
        }

    } while(opcion != 0);
}
void listarArchivos()
{
    DIR *directorio;
    struct dirent *archivo;

    directorio = opendir(".");

    if (directorio == NULL)
    {
        perror("Error al abrir el directorio");
        return;
    }

    printf("\n========== ARCHIVOS DEL DIRECTORIO ==========\n\n");

    while ((archivo = readdir(directorio)) != NULL)
    {
        printf("%s\n", archivo->d_name);
    }

    closedir(directorio);
}

void copiarMoverArchivo()
{
    int opcion;
    char origen[200];
    char destino[200];

    printf("\n========== COPIAR / MOVER ==========\n");
    printf("1. Copiar archivo\n");
    printf("2. Mover archivo\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    printf("Ruta del archivo origen: ");
    scanf("%s", origen);

    printf("Ruta destino: ");
    scanf("%s", destino);

    if (opcion == 1)
    {
        FILE *entrada;
        FILE *salida;
        int caracter;

        entrada = fopen(origen, "rb");

        if (entrada == NULL)
        {
            printf("No se pudo abrir el archivo origen.\n");
            return;
        }

        salida = fopen(destino, "wb");

        if (salida == NULL)
        {
            printf("No se pudo crear el archivo destino.\n");
            fclose(entrada);
            return;
        }

        while ((caracter = fgetc(entrada)) != EOF)
        {
            fputc(caracter, salida);
        }

        fclose(entrada);
        fclose(salida);

        printf("\nArchivo copiado correctamente.\n");
    }
    else if (opcion == 2)
    {
        if (rename(origen, destino) == 0)
        {
            printf("\nArchivo movido correctamente.\n");
        }
        else
        {
            perror("Error al mover el archivo");
        }
    }
    else
    {
        printf("Opcion invalida.\n");
    }
}
void eliminarArchivo()
{
    char nombre[200];

    printf("\n========== ELIMINAR ARCHIVO ==========\n");

    printf("Nombre del archivo: ");
    scanf("%s", nombre);

    if(remove(nombre) == 0)
    {
        printf("Archivo eliminado correctamente.\n");
    }
    else
    {
        perror("Error al eliminar archivo");
    }
}

void buscarArchivo()
{
    DIR *directorio;
    struct dirent *archivo;

    char nombre[200];

    int encontrado = 0;

    printf("\n========== BUSCAR ARCHIVO ==========\n");

    printf("Nombre del archivo: ");
    scanf("%s", nombre);

    directorio = opendir(".");

    if(directorio == NULL)
    {
        perror("Error");
        return;
    }

    while((archivo = readdir(directorio)) != NULL)
    {
        if(strcmp(nombre, archivo->d_name) == 0)
        {
            printf("\nArchivo encontrado: %s\n", archivo->d_name);
            encontrado = 1;
            break;
        }
    }

    if(!encontrado)
    {
        printf("\nArchivo no encontrado.\n");
    }

    closedir(directorio);
}

void mostrarEstadisticas()
{
    char nombre[200];

    struct stat info;

    printf("\n========== ESTADISTICAS ==========\n");

    printf("Nombre del archivo: ");
    scanf("%s", nombre);

    if(stat(nombre, &info) == 0)
    {
        printf("\nInformacion del archivo\n");
        printf("------------------------\n");

        printf("Tamano: %ld bytes\n", info.st_size);

        printf("Numero de enlaces: %ld\n",
               (long)info.st_nlink);

        printf("UID propietario: %d\n",
               info.st_uid);

        printf("GID propietario: %d\n",
               info.st_gid);

        printf("Permisos (octal): %o\n",
               info.st_mode & 0777);
    }
    else
    {
        perror("Error al obtener informacion");
    }
}
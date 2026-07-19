#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/bash_parser.h"

char rutaScript[200];

void menuBashParser()
{
    int opcion;

    do
    {
        printf("\n====================================\n");
        printf("        ANALIZADOR BASH\n");
        printf("====================================\n");
        printf("1. Analizar script Bash\n");
        printf("2. Detectar variables\n");
        printf("3. Detectar ciclos\n");
        printf("0. Regresar\n");
        printf("====================================\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                analizarScript();
                break;

            case 2:
                detectarVariables();
                break;

            case 3:
                detectarCiclos();
                break;

            case 0:
                printf("\nRegresando...\n");
                break;

            default:
                printf("\nOpcion invalida.\n");
        }

    }while(opcion!=0);
}

void analizarScript()
{
    FILE *archivo;

    char linea[300];

    printf("\nIngrese la ruta del script (.sh): ");
    scanf("%s",rutaScript);

    archivo = fopen(rutaScript,"r");

    if(archivo==NULL)
    {
        printf("No se pudo abrir el script.\n");
        return;
    }

    printf("\n========= CONTENIDO DEL SCRIPT =========\n\n");

    while(fgets(linea,sizeof(linea),archivo)!=NULL)
    {
        printf("%s",linea);
    }

    fclose(archivo);

    printf("\n\nAnalisis terminado.\n");
}
void detectarVariables()
{
    FILE *archivo;
    char linea[300];

    int encontradas = 0;

    archivo = fopen(rutaScript, "r");

    if (archivo == NULL)
    {
        printf("Primero debe analizar un script.\n");
        return;
    }

    printf("\n========= VARIABLES ENCONTRADAS =========\n\n");

    while (fgets(linea, sizeof(linea), archivo) != NULL)
    {
        /* Ignorar comentarios */
        if (linea[0] == '#')
            continue;

        /* Buscar una asignación de variable */
        if (strchr(linea, '=') != NULL)
        {
            char nombre[100];
            int i = 0;

            while (linea[i] != '=' &&
                   linea[i] != '\0' &&
                   linea[i] != ' ' &&
                   linea[i] != '\t')
            {
                nombre[i] = linea[i];
                i++;
            }

            nombre[i] = '\0';

            if (strlen(nombre) > 0)
            {
                printf("Variable: %s\n", nombre);
                encontradas++;
            }
        }
    }

    if (encontradas == 0)
    {
        printf("No se encontraron variables.\n");
    }

    fclose(archivo);
}
void detectarCiclos()
{
    FILE *archivo;
    char linea[300];

    int forEncontrado = 0;
    int whileEncontrado = 0;
    int untilEncontrado = 0;

    archivo = fopen(rutaScript, "r");

    if (archivo == NULL)
    {
        printf("Primero debe analizar un script.\n");
        return;
    }

    printf("\n========= CICLOS ENCONTRADOS =========\n\n");

    while (fgets(linea, sizeof(linea), archivo) != NULL)
    {
        if (strstr(linea, "for ") != NULL)
            forEncontrado = 1;

        if (strstr(linea, "while ") != NULL)
            whileEncontrado = 1;

        if (strstr(linea, "until ") != NULL)
            untilEncontrado = 1;
    }

    if (forEncontrado)
        printf("Se encontro un ciclo FOR.\n");

    if (whileEncontrado)
        printf("Se encontro un ciclo WHILE.\n");

    if (untilEncontrado)
        printf("Se encontro un ciclo UNTIL.\n");

    if (!forEncontrado && !whileEncontrado && !untilEncontrado)
        printf("No se encontraron ciclos.\n");

    fclose(archivo);
}
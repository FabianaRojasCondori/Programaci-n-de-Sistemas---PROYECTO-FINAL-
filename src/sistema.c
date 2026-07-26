#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "../include/sistema.h"

void sistemaOperativo();
void procesador();
void memoriaRAM();
void espacioDisco();
void tiempoActivo();
void usuariosConectados();

void menuSistema()
{
    int opcion;

    do
    {
        printf("\n====================================\n");
        printf("   INFORMACION DEL SISTEMA\n");
        printf("====================================\n");
        printf("1. Sistema Operativo\n");
        printf("2. Informacion del Procesador\n");
        printf("3. Memoria RAM\n");
        printf("4. Espacio en Disco\n");
        printf("5. Tiempo Activo del Sistema\n");
        printf("6. Usuarios Conectados\n");
        printf("0. Volver al menu principal\n");
        printf("====================================\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion)
        {
        case 1:
            sistemaOperativo();
            break;
        case 2:
            procesador();
            break;
        case 3:
            memoriaRAM();
            break;
        case 4:
            espacioDisco();
            break;
        case 5:
            tiempoActivo();
            break;
        case 6:
            usuariosConectados();
            break;
        case 0:
            printf("Volviendo al menu principal...\n");
            break;
        default:
            printf("Opcion invalida.\n");
        }

    } while (opcion != 0);
}

void sistemaOperativo()
{

    printf("\n--- INFORMACION DEL SISTEMA OPERATIVO ---\n");

    pid_t pid = fork();

    if (pid == 0)
    {

        execlp("cat", "cat", "/etc/os-release", NULL);

        perror("Error al obtener informacion");

        exit(EXIT_FAILURE);
    }
    else if (pid > 0)
    {

        wait(NULL);
    }
    else
    {

        perror("Error en fork");
    }
}

void procesador()
{

    printf("\n--- INFORMACION DEL PROCESADOR ---\n");

    pid_t pid = fork();

    if (pid == 0)
    {

        execlp("lscpu", "lscpu", NULL);

        perror("Error al ejecutar lscpu");

        exit(EXIT_FAILURE);
    }
    else if (pid > 0)
    {

        wait(NULL);
    }
    else
    {

        perror("Error en fork");
    }
}

void memoriaRAM()
{

    printf("\n--- MEMORIA RAM ---\n");

    pid_t pid = fork();

    if (pid == 0)
    {

        execlp("free", "free", "-h", NULL);

        perror("Error al ejecutar free");

        exit(EXIT_FAILURE);
    }
    else if (pid > 0)
    {

        wait(NULL);
    }
    else
    {

        perror("Error en fork");
    }
}

void espacioDisco()
{

    printf("\n--- ESPACIO EN DISCO ---\n");

    pid_t pid = fork();

    if (pid == 0)
    {

        execlp("df", "df", "-h", NULL);

        perror("Error al ejecutar df");

        exit(EXIT_FAILURE);
    }
    else if (pid > 0)
    {

        wait(NULL);
    }
    else
    {

        perror("Error en fork");
    }
}

void tiempoActivo()
{

    printf("\n--- TIEMPO ACTIVO DEL SISTEMA ---\n");

    pid_t pid = fork();

    if (pid == 0)
    {

        execlp("uptime", "uptime", NULL);

        perror("Error al ejecutar uptime");

        exit(EXIT_FAILURE);
    }
    else if (pid > 0)
    {

        wait(NULL);
    }
    else
    {

        perror("Error en fork");
    }
}

void usuariosConectados()
{

    printf("\n--- USUARIOS CONECTADOS ---\n");

    pid_t pid = fork();

    if (pid == 0)
    {

        execlp("who", "who", NULL);

        perror("Error al ejecutar who");

        exit(EXIT_FAILURE);
    }
    else if (pid > 0)
    {

        wait(NULL);
    }
    else
    {

        perror("Error en fork");
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include "../include/comandos.h"

#define HISTORIAL_PATH "logs/historial.txt"

void guardarHistorial(const char *comando) {
    FILE *f = fopen(HISTORIAL_PATH, "a");
    if (f == NULL) {
        perror("Error al abrir historial");
        return;
    }
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    fprintf(f, "[%02d/%02d/%04d %02d:%02d:%02d] %s\n",
            tm->tm_mday, tm->tm_mon+1, tm->tm_year+1900,
            tm->tm_hour, tm->tm_min, tm->tm_sec, comando);
    fclose(f);
}

void menuComandos() {
    int opcion;
    do {
        printf("\n====================================\n");
        printf("   EJECUTAR COMANDOS LINUX\n");
        printf("====================================\n");
        printf("1. Ejecutar un comando\n");
        printf("2. Mostrar historial de comandos\n");
        printf("0. Volver al menú principal\n");
        printf("====================================\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar(); // limpiar buffer

        switch(opcion) {
            case 1: ejecutarComando(); break;
            case 2: mostrarHistorial(); break;
            case 0: printf("Volviendo al menú principal...\n"); break;
            default: printf("Opción inválida.\n");
        }
    } while(opcion != 0);
}

void ejecutarComando() {
    char comando[256];
    printf("Ingrese el comando a ejecutar: ");
    fgets(comando, sizeof(comando), stdin);
    comando[strcspn(comando, "\n")] = '\0'; // quita salto de línea

    if (strlen(comando) == 0) {
        printf("Comando vacío.\n");
        return;
    }

    guardarHistorial(comando);

    pid_t pid = fork();
    if (pid == 0) {
        // Hijo: ejecuta el comando a través de /bin/sh -c
        execlp("/bin/sh", "sh", "-c", comando, NULL);
        perror("Error al ejecutar comando");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Comando finalizado con código %d\n", WEXITSTATUS(status));
        }
    } else {
        perror("Error en fork");
    }
}

void mostrarHistorial() {
    FILE *f = fopen(HISTORIAL_PATH, "r");
    if (f == NULL) {
        printf("No hay historial aún.\n");
        return;
    }
    char linea[256];
    printf("\n--- HISTORIAL DE COMANDOS ---\n");
    while (fgets(linea, sizeof(linea), f)) {
        printf("%s", linea);
    }
    fclose(f);
}
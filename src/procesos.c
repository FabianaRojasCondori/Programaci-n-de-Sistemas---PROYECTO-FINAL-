#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../include/procesos.h"

void menuProcesos() {
    int opcion;
    do {
        printf("\n====================================\n");
        printf("   ADMINISTRADOR DE PROCESOS\n");
        printf("====================================\n");
        printf("1. Listar procesos (ps aux)\n");
        printf("2. Buscar proceso por nombre\n");
        printf("3. Mostrar consumo de CPU y memoria\n");
        printf("4. Finalizar proceso (kill)\n");
        printf("5. Suspender proceso (kill -STOP)\n");
        printf("6. Reanudar proceso (kill -CONT)\n");
        printf("7. Mostrar árbol de procesos (pstree)\n");
        printf("0. Volver al menú principal\n");
        printf("====================================\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion) {
            case 1: listarProcesos(); break;
            case 2: buscarProceso(); break;
            case 3: mostrarCPUyMemoria(); break;
            case 4: finalizarProceso(); break;
            case 5: suspenderProceso(); break;
            case 6: reanudarProceso(); break;
            case 7: arbolProcesos(); break;
            case 0: printf("Volviendo al menú principal...\n"); break;
            default: printf("Opción inválida.\n");
        }
    } while(opcion != 0);
}

void listarProcesos() {
    printf("\n--- Listando procesos (ps aux) ---\n");
    pid_t pid = fork();
    if (pid == 0) {
        execlp("ps", "ps", "aux", NULL);
        perror("Error al ejecutar ps");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        wait(NULL);
    } else {
        perror("Error en fork");
    }
}

void buscarProceso() {
    char nombre[100];
    char comando[256];

    printf("Ingrese el nombre del proceso a buscar: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    if (strlen(nombre) == 0) {
        printf("Nombre no válido.\n");
        return;
    }

    snprintf(comando, sizeof(comando),
             "ps aux | grep -E --color=never 'USER|%s'", nombre);

    printf("\n--- Buscando procesos con '%s' ---\n", nombre);
    pid_t pid = fork();
    if (pid == 0) {
        execlp("sh", "sh", "-c", comando, NULL);
        perror("Error al ejecutar grep");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        wait(NULL);
    } else {
        perror("Error en fork");
    }
}

void mostrarCPUyMemoria() {
    printf("\n--- Consumo de CPU y memoria (top 5 procesos) ---\n");
    pid_t pid = fork();
    if (pid == 0) {
        execlp("sh", "sh", "-c", "ps aux --sort=-%cpu | head -6", NULL);
        perror("Error al ejecutar ps");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        wait(NULL);
    } else {
        perror("Error en fork");
    }
}

void finalizarProceso() {
    int pid;
    printf("Ingrese el PID del proceso a finalizar: ");
    scanf("%d", &pid);
    getchar();
    if (kill(pid, SIGTERM) == 0) {
        printf("Proceso %d finalizado correctamente.\n", pid);
    } else {
        perror("Error al finalizar el proceso");
    }
}


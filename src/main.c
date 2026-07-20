#include <stdio.h>
#include "../include/archivos.h"
#include "../include/backups.h"
#include "../include/bash_parser.h"
#include "../include/descargas.h"
#include "../include/procesos.h"
#include "../include/comandos.h"

int main() {
    int opcion;

    do {
        printf("\n=============================\n");
        printf("     ADMIN LINUX\n");
        printf("=============================\n");
        printf("1. Administrador de procesos\n");
        printf("2. Shell de archivos\n");
        printf("3. Ejecutar comandos Linux\n");
        printf("4. Sistema de respaldos\n");
        printf("5. Analizador Bash\n");
        printf("6. Cola de descargas\n");
        printf("0. Salir\n");
        printf("=============================\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                menuProcesos();
                break;
            case 2:
                menuArchivos();
                break;
            case 3:
                menuComandos();
                break;
            case 4:
                menuBackups();
                break;
            case 5:
                menuBashParser();
                break;
            case 6:
                menuDescargas();
                break;
            case 0:
                printf("Hasta luego.\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }

    } while(opcion != 0);

    return 0;
}

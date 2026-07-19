#include <stdio.h>

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
                printf("Entrando al Administrador de procesos...\n");
                break;
            case 2:
                printf("Entrando al Shell de archivos...\n");
                break;
            case 3:
                printf("Entrando a Ejecutar comandos...\n");
                break;
            case 4:
                printf("Entrando al Sistema de respaldos...\n");
                break;
            case 5:
                printf("Entrando al Analizador Bash...\n");
                break;
            case 6:
                printf("Entrando a la Cola de descargas...\n");
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

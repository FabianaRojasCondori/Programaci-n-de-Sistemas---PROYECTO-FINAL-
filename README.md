# ADMIN LINUX

## Universidad Nacional de San Agustín de Arequipa

**Curso:** Programación de Sistemas  
**Grupo:** A

### Integrantes

- Condori Catunta Joselin Sharon 
- Rojas Condori Fabiana Paola

---

## Descripción

**ADMIN LINUX** es un proyecto desarrollado en lenguaje C como trabajo final del curso de **Programación de Sistemas**. La aplicación integra diferentes herramientas de administración para sistemas Linux mediante una interfaz basada en menús, permitiendo gestionar procesos, archivos, respaldos, comandos del sistema, análisis de scripts Bash y una cola de descargas.

El proyecto tiene como finalidad aplicar conceptos fundamentales de programación de sistemas, tales como el uso de procesos, llamadas al sistema, manejo de archivos, ejecución de comandos del sistema operativo, modularización del código y automatización de tareas en entornos Linux.

---

## Funcionalidades

El sistema implementa los siguientes módulos:

- Administración de procesos.
- Shell para la gestión de archivos.
- Ejecución de comandos Linux.
- Sistema de creación y restauración de respaldos.
- Analizador de scripts Bash.
- Cola de descargas.
- Información del sistema, permitiendo consultar datos del sistema operativo, procesador, memoria RAM, espacio en disco, tiempo activo y usuario actual.

---

## Estructura del proyecto

```text
.
├── backups/          # Archivos de respaldo
├── bin/              # Ejecutable generado
├── downloads/        # Archivos descargados
├── include/          # Archivos de cabecera
├── logs/             # Archivos de registro
├── scripts/          # Scripts auxiliares
├── src/              # Código fuente
├── Makefile
└── README.md
```

---

## Requisitos

- Sistema operativo Linux.
- Compilador GCC.
- GNU Make.

---

## Compilación

Clonar el repositorio:

```bash
git clone https://github.com/FabianaRojasCondori/Programaci-n-de-Sistemas---PROYECTO-FINAL-.git
cd Programacion-de-Sistemas---PROYECTO-FINAL
```

Compilar el proyecto:

```bash
make
```

---

## Ejecución

Una vez compilado el proyecto, ejecutar:

```bash
./bin/admin_linux
```

---

## Menú principal

```text
===========================
        ADMIN LINUX
===========================

1. Administrador de procesos
2. Shell de archivos
3. Ejecutar comandos Linux
4. Sistema de respaldos
5. Analizador Bash
6. Cola de descargas
7. Informacion del Sistema
0. Salir
```

---

## Conceptos aplicados

Durante el desarrollo del proyecto se aplicaron los siguientes conceptos de Programación de Sistemas:

- Gestión de procesos.
- Llamadas al sistema (System Calls).
- Manejo de archivos.
- Ejecución de comandos del sistema operativo.
- Obtención de información del sistema mediante comandos Linux.
- Automatización mediante Bash.
- Modularización del código.
- Compilación mediante Makefiles.
- Obtención de información del sistema mediante comandos Linux.
- Creación y sincronización de procesos mediante fork(), exec() y wait().

---

## Licencia

Este proyecto fue desarrollado con fines exclusivamente académicos como parte del curso **Programación de Sistemas** de la **Universidad Nacional de San Agustín de Arequipa**.

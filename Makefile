CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/main.c src/procesos.c src/comandos.c src/archivos.c src/backups.c src/bash_parser.c src/descargas.c
OBJ = $(SRC:.c=.o)
TARGET = bin/admin_linux

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
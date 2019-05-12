# CFLAGS= -g -Wall -Wextra
.PHONY: all 
CC=gcc


all: +$(MAKE) -C calendarizacion
	 +$(MAKE) -C generador


# calendarizacion: calendarizacion/main.c
# 	$(CC) calendarizacion/main.c -lm -o cal

# generador: generador/main.c
# 	$(CC) generador/main.c -lm -o gen
# clean:
# 	rm -rf *.o 
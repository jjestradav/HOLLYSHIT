.PHONY: all clean calendarizacion generador

CC=gcc


all: calendarizacion generador
	 

calendarizacion: calendarizacion/main.c
	$(CC) calendarizacion/main.c -lm -o cal

generador: generador/main.c
	$(CC) generador/main.c -lm -o gen
clean:
	rm -rf *.o 
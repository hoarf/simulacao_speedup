CC=gcc
CFLAGS=-I.
DEPS = timer.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

simulacao_speedup: timer.o main.o
	$(CC) -o simulacao_speedup main.o timer.o -I.

main: main.c
	$(CC) -o main.c
CC=mpicc
CFLAGS=-I.
DEPS = timer.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

simulacao_speedup: clean mds_calcula_media.o timer.o main.o 
	$(CC) -o simulacao_speedup main.o timer.o mds_calcula_media.o -I.

main: main.c
	$(CC) -o main.c
clean:
	rm -rf *.o

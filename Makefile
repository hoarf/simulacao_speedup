CC=mpicc
CFLAGS=-I.
DEPS = main.h timer.h mds_calcula_media.h 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

broadcast: clean main.o 
	$(CC) -o broadcast main.o -I.

clean:
	rm -rf *.o

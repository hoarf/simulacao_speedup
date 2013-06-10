CC=mpicc
CFLAGS=-I.
DEPS = main.h timer.h mds_calcula_media.h 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

broadcast: clean mds_calcula_media.o timer.o main.o 
	$(CC) -o broadcast main.o timer.o mds_calcula_media.o -I.

clean:
	rm -rf *.o
